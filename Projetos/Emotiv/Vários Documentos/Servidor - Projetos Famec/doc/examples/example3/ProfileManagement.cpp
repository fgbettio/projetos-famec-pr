#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>

#include "EmoStateDLL.h"
#include "edk.h"
#include "edkErrorCode.h"
#include "ProfileControl.h"

#pragma comment(lib, "../lib/edk.lib")

ExternalProfileManager profileManager;
std::map<unsigned int,std::string> headsetProfileMap;
unsigned char* baseProfile = 0;
unsigned int baseProfileSize = 0;

bool handleUserInput() {

	static std::string inputBuffer;

	char c = _getch();

	if (c == '\r') {
		std::cout << std::endl;
		std::string command;

		const size_t len = inputBuffer.length();
		command.reserve(len);

		// Convert the input to lower case first
		for (size_t i=0; i < len; i++) {
			command.append(1, tolower(inputBuffer.at(i)));
		}

		inputBuffer.clear();

		bool success = parseCommand(command, std::cout,
							profileManager, headsetProfileMap,
							baseProfile, baseProfileSize);
		std::cout << "ProfileManagement> ";
		return success;

		return true;
	}
	else {
		if (c == '\b') { // Backspace key
			if (inputBuffer.length()) {
				putchar(c);
				putchar(' ');
				putchar(c);
				inputBuffer.erase(inputBuffer.end()-1);
			}
		}
		else {
			inputBuffer.append(1,c);
			std::cout << c;
		}
	}	

	return true;
}


int main(int argc, char** argv) {

	EmoEngineEventHandle eEvent		= EE_EmoEngineEventCreate();
	EmoEngineEventHandle eProfile	= EE_ProfileEventCreate();
	EmoStateHandle eState			= EE_EmoStateCreate();
	unsigned int userID				= 0;

	profileManager.load(DEFAULT_PROFILE_NAME);
	
	try {

     // if (EE_EngineConnect() != EDK_OK ) { // connect directly to EmoEngine
		if (EE_EngineRemoteConnect("127.0.0.1", 3008) != EDK_OK) { // connect to Control Panel
			throw std::exception("Emotiv Engine start up failed.");
		}
		else {
			std::cout << "Emotiv Engine started!" << std::endl;
		}

		std::cout << "Type \"exit\" to quit, \"help\" to list available commands..." << std::endl;

		// Retrieve the base profile and save it in buffer
		EE_GetBaseProfile(eProfile);
		profileHandleToByteArray(eProfile, &baseProfile, &baseProfileSize);

		while (true) {
			
			// Handle the user input
			if (_kbhit()) {
				if (!handleUserInput()) {
					break;
				}
			}

            int state = EE_EngineGetNextEvent(eEvent);

			// New event needs to be handled
			if (state == EDK_OK) {

				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);
				EE_EmoEngineEventGetUserId(eEvent, &userID);

				switch (eventType) {

					// New headset connected
					case EE_UserAdded:
					{
						std::cout << "New user " << userID << " added." << std::endl;
						
						// add the headset
						headsetProfileMap.insert(
							std::pair<unsigned int,std::string>(userID, std::string())
						);
						break;
					}
				
					// Headset disconnected
					case EE_UserRemoved:
					{
						std::cout << "User " << userID << " has been removed." << std::endl;

						// Profile will be returned as well, we need to save the profile according
						// to the associated headset ID

						unsigned char* profileBuffer = 0;
						unsigned int   profileSize   = 0;

						if (profileHandleToByteArray(eEvent, &profileBuffer, &profileSize)) {
						
							std::map<unsigned int, std::string>::iterator iter
								= headsetProfileMap.find(userID);

							if (iter != headsetProfileMap.end()) {
								const std::string& profileName = iter->second;

								if (!profileName.empty()) {
									profileManager.insertProfile(profileName, profileBuffer, profileSize);
								}

								// Remove the headset ID from the mapping table
								headsetProfileMap.erase(iter);
							}
						}

						if (profileBuffer) {
							delete [] profileBuffer, profileBuffer = 0;
						}

						break;
					}
					
					// Handle EmoState update
					case EE_EmoStateUpdated:
					{
						//std::cout << "New EmoState from user " << userID << "..." << std::endl;
						EE_EmoEngineEventGetEmoState(eEvent, eState);
						break;
					}

					default:
						break;
				}
			}
			else if (state != EDK_NO_EVENT) {
				std::cout << "Internal error in Emotiv Engine!" << std::endl;
				break;
			}

			Sleep(15);
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		std::cout << "Press any keys to exit..." << std::endl;
		getchar();
	}

	// Save the binary form of all profiles into a physical file
	profileManager.save(DEFAULT_PROFILE_NAME);

	// Free up resources
	EE_EngineDisconnect();
	EE_EmoStateFree(eState);
	EE_EmoEngineEventFree(eEvent);
	EE_EmoEngineEventFree(eProfile);

	if (baseProfile) {
		delete [] baseProfile, baseProfile = 0;
	}

	return 0;
}
