//Objetivo: Inserir contador de "piscadas" que o programa realiza.
 
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
using namespace std;
int main(int argc, char **argv) 
{

	EmoEngineEventHandle eEvent = EE_EmoEngineEventCreate();//EE_EmoEngineEventCreate cria um evento o qual é recebido pelo EmoEngineEventHandle e guardado no eEvent
	EmoStateHandle eState = EE_EmoStateCreate(); //EE_EmoStateCreate cria um evento o qual é recebido pelo EmoStateHandle e armazenado no eState
	unsigned int userID = 0;
	const unsigned short composerPort = 1726;
	int option = 0;
	int state = 0;
	int x=0;
	std::string input;

	try 
	{
		if (argc != 2) 
		{
			throw std::exception("Please supply the log file name.\nUsage: [log_file_name].");
		}
		cout << "===================================================================" << endl;
		cout << "v1.0 Example to show how to log the EmoState from EmoEngine/EmoComposer." << endl;
		cout << "===================================================================" << endl;
		cout << "Press '1' to start and connect to the EmoEngine " << endl;
		cout << "Press '2' to connect to the EmoComposer " << endl;
		cout << ">> ";
		getline(std::cin, input, '\n'); //getline recebe a ação do teclado
		option = atoi(input.c_str()); //leitura do teclado, tansformar um caracter em um inteiro e atribui para a variavel	option
		switch (option) 
		{
			case 1:
			{
				if (EE_EngineConnect() != EDK_OK) 
				{
					throw std::exception("Emotiv Engine start up failed.");
				}
				break;
			}
			case 2:
			{
				cout << "Target IP of EmoComposer? [127.0.0.1] ";
				getline(cin, input, '\n');
				if (input.empty()) 
				{
					input = string("127.0.0.1");
				}
				if (EE_EngineRemoteConnect(input.c_str(), composerPort) != EDK_OK) 
				{
					string errMsg = "Cannot connect to EmoComposer on [" + input + "]";
					throw exception(errMsg.c_str());
				}
				break;
			}
			default:
			throw exception("Invalid option...");
			break;
		}


		cout << "Start receiving EmoState! Press any key to stop logging...\n" << endl;
		ofstream ofs(argv[1]);
		bool writeHeader = true;	
		int tes;
		cout << "===================================================================" << endl;
		while (!_kbhit()) 
		{
			
			state = EE_EngineGetNextEvent(eEvent); //API Emotiv - //EE_EngineGetNextEvent recupera o evento eEvent
			// New event needs to be handled
			if (state == EDK_OK) 
			{// EDK_OK = Define
				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);//EE_EmoEngineEventGetType(eEvent)retorna o tipo de evento que se aloca em EE_Event_t eventType
				EE_EmoEngineEventGetUserId(eEvent, &userID);//EE_EmoEngineEventGetUserId recupera parâmetros de (eEvent, &userID)
				// Log the EmoState if it has been updated
				if (eventType == EE_EmoStateUpdated) //Se o eventType for igual ao EE_EmoStateUpdated, continue com código abaixo
				{
					
					EE_EmoEngineEventGetEmoState(eEvent, eState);//EE_EmoEngineEventGetEmoState retorna e/ou recupera parâmetros (eEvent, eState)
					const float timestamp = ES_GetTimeFromStart(eState);//ES_GetTimeFromStart(eState)retorna um tempo somente quando EmoEngine se conectou com sucesso no headset
					
					printf("%10.3fs : New EmoState from user %d ...\n", timestamp, userID);
					tes=ES_ExpressivIsBlink(eState);//ES_ExpressivIsBlink consulta se usuário esta piscando no momento em que EmoState captura
					if(tes!=0)
					{
						printf("Blink:%d\n",tes);
						x++;
						printf("Contador de Blink numero %d\n",x);
						cout << "===================================================================" << endl;
					}
				
					Sleep(1);
				}
				ofs.close();
			}
		}

		EE_EngineDisconnect();//Término de conexão com EmoEngine
		EE_EmoStateFree(eState);//Liberação de memória referenciada do EmoState
		EE_EmoEngineEventFree(eEvent);//Liberação de memória referenciada de um indicador de eventos
		return 0;
	}

	catch (const exception& e) 
	{
		cerr << e.what() << endl;
		cout << "P4to exit..." << endl;
		getchar();
	}
}
void logEmoState(ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader) {
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
	os << endl;
}
// Log the time stamp and user ID
os << ES_GetTimeFromStart(eState) << ",";//ES_GetTimeFromStart(eState)retorna um tempo somente quando EmoEngine se conectou com sucesso no headset
os << userID << ",";
os << static_cast<int>(ES_GetWirelessSignalStatus(eState)) << ",";//Consulta do sinal do Wirelles se está forte ou não
// Expressiv Suite results
os << ES_ExpressivIsBlink(eState) << ",";//Sinal expressivo de piscando
os << ES_ExpressivIsLeftWink(eState) << ",";//Sinal expressivo de piscando no lado esquerdo
os << ES_ExpressivIsRightWink(eState) << ",";//Sinal expressivo de piscando no lado direito
os << ES_ExpressivIsLookingLeft(eState) << ",";//Sinal expressivo de olhando para equerda
os << ES_ExpressivIsLookingRight(eState) << ",";//Sinal expressivo de olhando para direita
map<EE_ExpressivAlgo_t, float> expressivStates;
EE_ExpressivAlgo_t upperFaceAction = ES_ExpressivGetUpperFaceAction(eState);//ES_ExpressivGetUpperFaceAction(eState) retorna uma detecção de expressão na face superior
float upperFacePower = ES_ExpressivGetUpperFaceActionPower(eState);
EE_ExpressivAlgo_t lowerFaceAction = ES_ExpressivGetLowerFaceAction(eState);//ES_ExpressivGetLowerFaceAction(eState) retorna uma detecção de expressão na face inferior
float lowerFacePower = ES_ExpressivGetLowerFaceActionPower(eState);
expressivStates[ upperFaceAction ] = upperFacePower;
expressivStates[ lowerFaceAction ] = lowerFacePower;

os << expressivStates[ EXP_EYEBROW ] << ",";//Sinal expressivo da sombrancelha
os << expressivStates[ EXP_FURROW ] << ","; // furrow (sem interpretação)
os << expressivStates[ EXP_SMILE ] << ","; //Sinal expressivo do sorriso
os << expressivStates[ EXP_CLENCH ] << ","; //Forçar olhos para fechar
os << expressivStates[ EXP_SMIRK_LEFT ] << ",";//Sinal expressivo de sorriso no lado esquerdo
os << expressivStates[ EXP_SMIRK_RIGHT ] << ","; //Sinal expressivo de sorriso no lado direito
os << expressivStates[ EXP_LAUGH ] << ","; //Sinal expressivo de risos
// Affectiv Suite results
os << ES_AffectivGetExcitementShortTermScore(eState) << ",";//Nível de excitação de curto prazo do usuário
os << ES_AffectivGetExcitementLongTermScore(eState) << ",";//Nível de excitação de longo prazo do usuário
os << ES_AffectivGetEngagementBoredomScore(eState) << ",";//Nível de alegria ou tédio do usuário
// Cognitiv Suite results
os << static_cast<int>(ES_CognitivGetCurrentAction(eState)) << ",";//Retorna a ação cognitiva do usuário
os << ES_CognitivGetCurrentActionPower(eState);//Retorna uma ação cognitiva forte do usuário
os << endl;
}

