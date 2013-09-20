// Teclado_Virtual_Neural.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <windows.h>
#include <map>
#include <dos.h>

using namespace Teclado_Virtual_Neural;
//=====================

/*
#include <edk.h>
#include <edkErrorCode.h>
#pragma comment(lib, "edk.lib")
*/

/*
int x=0,y=0,x_old;
void logEmoState(std::ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader = false);
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/
//=====================
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	/*
	EmoEngineEventHandle eEvent			= EE_EmoEngineEventCreate();
	EmoStateHandle eState				= EE_EmoStateCreate();
	unsigned int userID					= 0;
	const unsigned short composerPort	= 1726;
	int option = 0, state = 0, 
		blink = 0, lookLeft = 0, lookRight = 0, 
		countBlink = 0, countLookLeft = 0, countLookRight = 0, 
		tempBlink = 0, tempLookLeft = 0, tempLookRight = 0;

	std::string input;
	*/
	//status.Text="oi";

	


	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
