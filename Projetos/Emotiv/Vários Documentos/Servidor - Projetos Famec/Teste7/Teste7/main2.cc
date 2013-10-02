//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <windows.h>
#include <map>


#include "C:\Arquivos de programas\Emotiv Development Kit_v1.0.0.3\doc\examples\include\edk.h"
#include "C:\Arquivos de programas\Emotiv Development Kit_v1.0.0.3\doc\examples\include\edkErrorCode.h"
#pragma comment(lib, "C:/Arquivos de programas/Emotiv Development Kit_v1.0.0.3/doc/examples/lib/edk.lib")

void logEmoState(std::ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader = false);


int main(int argc, char **argv) {


	EmoEngineEventHandle	eEvent			= EE_EmoEngineEventCreate();//# 
	EmoStateHandle eState				= EE_EmoStateCreate();
	unsigned int userID					= 0;// declara a variavel que sera usda para armazenar o ID (Codigo) do usu�rio
	const unsigned short composerPort	= 1726; //Declara Porta usada pelo Composer
	int option = 0; //Declara valor Option
	int state  = 0; //Declara valor State 
	std::string input; //# STD BIBLIOTECA


	try { //Tentar executar o programa

		if (argc != 2) { 
			throw std::exception("Please supply the log file name.\nUsage: teste2 [log_file_name]."); 
		}  // THROW joga o erro inesperado para ultima op��o (CATCH)
	
		std::cout << "===================================================================" << std::endl;
		std::cout << "####Example to show how to log the EmoState from EmoEngine/EmoComposer." << std::endl;
		std::cout << "===================================================================" << std::endl;
		std::cout << "Press '1' to start and connect to the EmoEngine                    " << std::endl;
		std::cout << "Press '2' to connect to the EmoComposer                            " << std::endl;
		std::cout << ">> ";
		// Texto impresso na Tela
		std::getline(std::cin, input, '\n'); // Pega Texto digitado e atribui para variavel IMPUT
		option = atoi(input.c_str()); // Converte a String (PALAVRA) para um Inteiro (Num�rico)

		switch (option) {
			case 1:
			{
				if (EE_EngineConnect() != EDK_OK) { //Da Start a conex�o com o EmoEngine
					throw std::exception("Emotiv Engine start up failed."); //Se for diferente de OK joga para Catch (Ultima Alternativa)
				}
				break;
			}
			case 2: // ESTUDAR CODIGO!!!!!
			{
				std::cout << "Target IP of EmoComposer? [127.0.0.1] ";
				std::getline(std::cin, input, '\n');

				if (input.empty()) {
					input = std::string("127.0.0.1");
				}

				if (EE_EngineRemoteConnect(input.c_str(), composerPort) != EDK_OK) {
					std::string errMsg = "Cannot connect to EmoComposer on [" + input + "]";
					throw std::exception(errMsg.c_str());
				}
				break;
			}
			default:
				throw std::exception("Invalid option...");
				break;
		}
		
		
		std::cout << "Start receiving EmoState! Press any key to stop logging...\n" << std::endl;
		// Tentando Conectar com as Configura��es User (CONFIRMAR)
		std::ofstream ofs(argv[1]);//Pega o Conte�do das Strings
		bool writeHeader = true;// # Booleana (Verdadeiro e Falso)
		
		while (!_kbhit()) {

			state = EE_EngineGetNextEvent(eEvent); //API Emotiv - Atribui o o proximo evento ao state

			// New event needs to be handled
			if (state == EDK_OK) {// State for igual ao Define EDK_OK

				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent); // # Pesquisar sobre
				EE_EmoEngineEventGetUserId(eEvent, &userID);// pega (Get) usuario ativo

				// Log the EmoState if it has been updated
				if (eventType == EE_EmoStateUpdated) {		//"eventtype=controlador" de adi��o e remo��o de usuarios
															//"EE_EmoStateUpdated" enumerador de "eventtype"
					EE_EmoEngineEventGetEmoState(eEvent, eState;) // Copia o Retorno do estado retornado pelo Emostateupdated
					const float timestamp = ES_GetTimeFromStart(eState); // Retorna o tempo em que o capacete est� conectado ou zera se desconectado

					//printf("%10.3fs : New EmoState from user %d ...\n", timestamp, userID);
					printf( ES_ExpressivIsBlink(eState),"%s\n");// ES_ExpressivIsBlink(eState) 
					logEmoState(ofs, userID, eState, writeHeader);    //Fun��o de relat�rio do Emostate
					writeHeader = false;
				}
			}
			else if (state != EDK_NO_EVENT) { //EDK_NO_EVENT = Retorna quando n�o h� um novo evento no EmoEngine
				std::cout << "Internal error in Emotiv Engine!" << std::endl;
				break;
			}

			Sleep(1);
		}

		ofs.close();
	}
	catch (const std::exception& e) {  // Recebe o erro enviado pelo Throw
		std::cerr << e.what() << std::endl;
		std::cout << "Press any key to exit..." << std::endl;
		getchar();
	}

	EE_EngineDisconnect(); // Finaliza conex�o com o EmoEngine
	EE_EmoStateFree(eState);  // Libera Mem�ria do Computador referenciado pelo EmoState
	EE_EmoEngineEventFree(eEvent);  // Libera Mem�ria do Computador referenciado pelo EventState

	return 0;
}


void logEmoState(std::ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader) {

	// Create the top header
	if (withHeader) {
		os << "Time,";
		os << "UserID,";
		os << "Wireless Signal Status,";
		os << "Blink,";
		os << "Wink Left,";
		os << "Wink Right,";
		os << "Look Left,";
		os << "Look Right,";
		os << "Eyebrow,";
		os << "Furrow,";
		os << "Smile,";
		os << "Clench,";
		os << "Smirk Left,";
		os << "Smirk Right,";
		os << "Laugh,";
		os << "Short Term Excitement,";
		os << "Long Term Excitement,";
		os << "Engagement/Boredom,";
		os << "Cognitiv Action,";
		os << "Cognitiv Power,";
		os << std::endl;
	}

	// Log the time stamp and user ID
	os << ES_GetTimeFromStart(eState) << ","; // Retorna o tempo em que o EmoEngine esta conectado ao Capacete.
	os << userID << ",";
	os << static_cast<int>(ES_GetWirelessSignalStatus(eState)) << ",";

	// Expressiv Suite results
	os << ES_ExpressivIsBlink(eState) << ",";
	os << ES_ExpressivIsLeftWink(eState) << ",";
	os << ES_ExpressivIsRightWink(eState) << ",";

	os << ES_ExpressivIsLookingLeft(eState) << ",";
	os << ES_ExpressivIsLookingRight(eState) << ",";

	std::map<EE_ExpressivAlgo_t, float> expressivStates;

	EE_ExpressivAlgo_t upperFaceAction = ES_ExpressivGetUpperFaceAction(eState);
	float			   upperFacePower  = ES_ExpressivGetUpperFaceActionPower(eState);

	EE_ExpressivAlgo_t lowerFaceAction = ES_ExpressivGetLowerFaceAction(eState);
	float			   lowerFacePower  = ES_ExpressivGetLowerFaceActionPower(eState);

	expressivStates[ upperFaceAction ] = upperFacePower;
	expressivStates[ lowerFaceAction ] = lowerFacePower;
	
	os << expressivStates[ EXP_EYEBROW     ] << ","; // eyebrow
	os << expressivStates[ EXP_FURROW      ] << ","; // furrow
	os << expressivStates[ EXP_SMILE       ] << ","; // smile
	os << expressivStates[ EXP_CLENCH      ] << ","; // clench
	os << expressivStates[ EXP_SMIRK_LEFT  ] << ","; // smirk left
	os << expressivStates[ EXP_SMIRK_RIGHT ] << ","; // smirk right
	os << expressivStates[ EXP_LAUGH       ] << ","; // laugh

	// Affectiv Suite results
	os << ES_AffectivGetExcitementShortTermScore(eState) << ",";
	os << ES_AffectivGetExcitementLongTermScore(eState) << ",";

	os << ES_AffectivGetEngagementBoredomScore(eState) << ",";

	// Cognitiv Suite results
	os << static_cast<int>(ES_CognitivGetCurrentAction(eState)) << ",";
	os << ES_CognitivGetCurrentActionPower(eState);

	os << std::endl;

}

