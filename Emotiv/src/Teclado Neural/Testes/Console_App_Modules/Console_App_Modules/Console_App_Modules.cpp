// Console_App_Modules.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <edk.h>
#include <edkErrorCode.h>

#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <windows.h>
#include <map>
#include <dos.h>

#pragma comment(lib, "edk.lib")

void iniciar_processo_captura_sinais();
void logEmoState(std::ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader = false);

int _tmain(int argc, _TCHAR* argv[])
{

	EmoEngineEventHandle eEvent			= EE_EmoEngineEventCreate();
	EmoStateHandle eState				= EE_EmoStateCreate();
	unsigned int userID					= 0;
	const unsigned short composerPort	= 1726;
	int option = 0, state = 0, 
		blink = 0, lookLeft = 0, lookRight = 0, 
		countBlink = 0, countLookLeft = 0, countLookRight = 0, 
		tempBlink = 0, tempLookLeft = 0, tempLookRight = 0;

	std::string input;

	try {

		if (argc != 2) {
			throw std::exception("Favor, informar o nome do arquivo de log.\nUse: EmoStateLogger [nome_do_arquivo].");
		}

		std::cout << "===================================================================" << std::endl;
		std::cout << "                         Formas de conexoes.                       " << std::endl;
		std::cout << "===================================================================" << std::endl;
		std::cout << "Pressione '1' para iniciar e conectar ao EmoEngime (HeadSet)       " << std::endl;
		std::cout << "Pressione '2' para conectar ao EmoComposer (Simulador)             " << std::endl;
		std::cout << ">> ";

		std::getline(std::cin, input, '\n');
		option = atoi(input.c_str());

		switch (option) {
			case 1:
			{
				if (EE_EngineConnect() != EDK_OK) {
					throw std::exception("Falha na inicializacao do Emotiv.");
				}
				break;
			}
			case 2:
			{
				input = std::string("127.0.0.1");

				if (EE_EngineRemoteConnect(input.c_str(), composerPort) != EDK_OK) {
					std::string errMsg = "Nao foi possivel conectar ao EmoComposer em [" + input + "]";
					throw std::exception(errMsg.c_str());
				}
				break;
			}
			default:
				throw std::exception("Opcao Invalida...");
				break;
		}

		// Exemplo de segundo menu
		std::cout << "===================================================================" << std::endl;
		std::cout << "Selecione uma opcao" << std::endl;
		std::cout << "===================================================================" << std::endl;
		std::cout << "Pression '1' para 'ExpressivIsLookingRight'" << std::endl;
		std::cout << "Pression '2' para 'ExpressivGetEyeLocation'" << std::endl;
		std::cout << "Pression '3' para 'ExpressivIsEyesOpen'" << std::endl;
		std::cout << "Pression '4' para 'GetHeadsetOn'" << std::endl;
		std::cout << "Pression '5' para 'GetNumContactQualityChannels'" << std::endl;
		std::cout << "Pression '6' para 'GetContactQuality'" << std::endl;
		std::cout << "Pression '7' para 'GetContactQualityFromAllChannels'" << std::endl;
		std::cout << "Pression '8' para ''" << std::endl;
		std::cout << "Pression '9' para ''" << std::endl;
		std::cout << "Pression '10' para 'Sair'" << std::endl;
		std::cout << ">> ";

		std::getline(std::cin, input, '\n');
		option = atoi(input.c_str());

		switch (option) {
			case 1: {
				iniciar_processo_captura_sinais();
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				break;
			}
			case 7: {
				break;
			}
			case 8: {
				break;
			}
			case 9: {
				break;
			}
			case 10: {
				break;
			}
			default:
				throw std::exception("Opcao Invalida...");
				break;
		}

		// TODO criar metodo conforme menu selecionado e adicionar código abaixo para iniciar
		// o funcionamento

		
		std::cout << "Recebimento do EmoState iniciado! \nPressione alguma tecla para finalizar a aplicacao...\n" << std::endl;

		std::ofstream ofs(argv[1]);
		bool writeHeader = true;

		while (!_kbhit()) {

			state = EE_EngineGetNextEvent(eEvent);

			// New event needs to be handled
			if (state == EDK_OK) {

				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);
				EE_EmoEngineEventGetUserId(eEvent, &userID);

				// Log the EmoState if it has been updated
				if (eventType == EE_EmoStateUpdated)
				{

					EE_EmoEngineEventGetEmoState(eEvent, eState);

					//Linha adicionada. Recebe o valor da piscada
					blink = ES_ExpressivIsBlink(eState); 
					
					printf("Left: %d, Right: %d, UP: %d, Blink: %d\t Time: %f\n",
						ES_ExpressivIsLookingLeft(eState),ES_ExpressivIsLookingRight(eState),ES_ExpressivIsLookingUp(eState), ES_ExpressivIsBlink(eState), ES_GetTimeFromStart(eState));

				}
			}
			else if (state != EDK_NO_EVENT) {
				std::cout << "Houve um erro interno no Emotiv!" << std::endl;
				break;
			}
		}

		ofs.close();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Pressione uma tecla para sair..." << std::endl;
		getchar();
	}

	EE_EngineDisconnect();
	EE_EmoStateFree(eState);
	EE_EmoEngineEventFree(eEvent);

	return 0;
}

void iniciar_processo_captura_sinais(){
	std::cout << "Chamou!!!" << std::endl;
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
	os << ES_GetTimeFromStart(eState) << ",";
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