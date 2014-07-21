#include <edk.h>
#include <edkErrorCode.h>
#include <EmoStateDLL.h>
#include <iostream>
#include <conio.h>
#pragma comment(lib, "edk.lib")
#pragma once

namespace Teclado_Numerico_Acelerometro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			InitializeMyComponents();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	protected: 

	private: System::Windows::Forms::TextBox^  textBoxDisplay;

	private: System::Windows::Forms::Button^  buttonConectarHeadset;
	private: System::Windows::Forms::Button^  buttonConectarEmoComposer;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  buttonSair;

	private: System::Windows::Forms::TextBox^  textBoxConsole;
	private: System::Windows::Forms::Label^  labelDisplay;


	private: System::Windows::Forms::Label^  labelConsole;
	private: System::Windows::Forms::TextBox^  textBoxCoordY;
	private: System::Windows::Forms::TextBox^  textBoxCoordX;
	private: System::Windows::Forms::Label^  labelCoordY;
	private: System::Windows::Forms::Label^  labelCoordX;
	
	private: int flagConectado;
	private: static const String ^versao = "v01";

	private: EmoEngineEventHandle eEvent;
	private: EmoStateHandle eState;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBoxDisplay = (gcnew System::Windows::Forms::TextBox());
			this->buttonConectarHeadset = (gcnew System::Windows::Forms::Button());
			this->buttonConectarEmoComposer = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxCoordY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCoordX = (gcnew System::Windows::Forms::TextBox());
			this->labelCoordY = (gcnew System::Windows::Forms::Label());
			this->labelCoordX = (gcnew System::Windows::Forms::Label());
			this->buttonSair = (gcnew System::Windows::Forms::Button());
			this->textBoxConsole = (gcnew System::Windows::Forms::TextBox());
			this->labelDisplay = (gcnew System::Windows::Forms::Label());
			this->labelConsole = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(12, 263);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(102, 23);
			this->button0->TabIndex = 0;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 234);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(48, 234);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(84, 234);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 205);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(30, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(48, 205);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(30, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(84, 205);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(30, 23);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 176);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(30, 23);
			this->button7->TabIndex = 7;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(48, 176);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 23);
			this->button8->TabIndex = 8;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(84, 176);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(30, 23);
			this->button9->TabIndex = 9;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// textBoxDisplay
			// 
			this->textBoxDisplay->Location = System::Drawing::Point(12, 85);
			this->textBoxDisplay->Multiline = true;
			this->textBoxDisplay->Name = L"textBoxDisplay";
			this->textBoxDisplay->Size = System::Drawing::Size(100, 85);
			this->textBoxDisplay->TabIndex = 10;
			// 
			// buttonConectarHeadset
			// 
			this->buttonConectarHeadset->Location = System::Drawing::Point(12, 12);
			this->buttonConectarHeadset->Name = L"buttonConectarHeadset";
			this->buttonConectarHeadset->Size = System::Drawing::Size(102, 23);
			this->buttonConectarHeadset->TabIndex = 11;
			this->buttonConectarHeadset->Text = L"Conectar Headset";
			this->buttonConectarHeadset->UseVisualStyleBackColor = true;
			this->buttonConectarHeadset->Click += gcnew System::EventHandler(this, &Form1::buttonConectarHeadset_Click);
			// 
			// buttonConectarEmoComposer
			// 
			this->buttonConectarEmoComposer->Location = System::Drawing::Point(120, 12);
			this->buttonConectarEmoComposer->Name = L"buttonConectarEmoComposer";
			this->buttonConectarEmoComposer->Size = System::Drawing::Size(142, 23);
			this->buttonConectarEmoComposer->TabIndex = 12;
			this->buttonConectarEmoComposer->Text = L"Conectar EmoComposer";
			this->buttonConectarEmoComposer->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBoxCoordY);
			this->panel1->Controls->Add(this->textBoxCoordX);
			this->panel1->Controls->Add(this->labelCoordY);
			this->panel1->Controls->Add(this->labelCoordX);
			this->panel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Location = System::Drawing::Point(120, 85);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(257, 85);
			this->panel1->TabIndex = 13;
			// 
			// textBoxCoordY
			// 
			this->textBoxCoordY->Location = System::Drawing::Point(87, 43);
			this->textBoxCoordY->Name = L"textBoxCoordY";
			this->textBoxCoordY->Size = System::Drawing::Size(129, 20);
			this->textBoxCoordY->TabIndex = 3;
			// 
			// textBoxCoordX
			// 
			this->textBoxCoordX->Location = System::Drawing::Point(87, 19);
			this->textBoxCoordX->Name = L"textBoxCoordX";
			this->textBoxCoordX->Size = System::Drawing::Size(129, 20);
			this->textBoxCoordX->TabIndex = 2;
			// 
			// labelCoordY
			// 
			this->labelCoordY->AutoSize = true;
			this->labelCoordY->Location = System::Drawing::Point(33, 46);
			this->labelCoordY->Name = L"labelCoordY";
			this->labelCoordY->Size = System::Drawing::Size(48, 13);
			this->labelCoordY->TabIndex = 1;
			this->labelCoordY->Text = L"Coord Y:";
			// 
			// labelCoordX
			// 
			this->labelCoordX->AutoSize = true;
			this->labelCoordX->Location = System::Drawing::Point(33, 22);
			this->labelCoordX->Name = L"labelCoordX";
			this->labelCoordX->Size = System::Drawing::Size(48, 13);
			this->labelCoordX->TabIndex = 0;
			this->labelCoordX->Text = L"Coord X:";
			// 
			// buttonSair
			// 
			this->buttonSair->Location = System::Drawing::Point(325, 12);
			this->buttonSair->Name = L"buttonSair";
			this->buttonSair->Size = System::Drawing::Size(52, 23);
			this->buttonSair->TabIndex = 14;
			this->buttonSair->Text = L"Sair";
			this->buttonSair->UseVisualStyleBackColor = true;
			this->buttonSair->Click += gcnew System::EventHandler(this, &Form1::buttonSair_Click);
			// 
			// textBoxConsole
			// 
			this->textBoxConsole->Location = System::Drawing::Point(120, 205);
			this->textBoxConsole->Multiline = true;
			this->textBoxConsole->Name = L"textBoxConsole";
			this->textBoxConsole->Size = System::Drawing::Size(257, 81);
			this->textBoxConsole->TabIndex = 15;
			// 
			// labelDisplay
			// 
			this->labelDisplay->AutoSize = true;
			this->labelDisplay->Location = System::Drawing::Point(12, 69);
			this->labelDisplay->Name = L"labelDisplay";
			this->labelDisplay->Size = System::Drawing::Size(41, 13);
			this->labelDisplay->TabIndex = 16;
			this->labelDisplay->Text = L"Display";
			// 
			// labelConsole
			// 
			this->labelConsole->AutoSize = true;
			this->labelConsole->Location = System::Drawing::Point(120, 186);
			this->labelConsole->Name = L"labelConsole";
			this->labelConsole->Size = System::Drawing::Size(45, 13);
			this->labelConsole->TabIndex = 17;
			this->labelConsole->Text = L"Console";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 307);
			this->Controls->Add(this->labelConsole);
			this->Controls->Add(this->labelDisplay);
			this->Controls->Add(this->textBoxConsole);
			this->Controls->Add(this->buttonSair);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonConectarEmoComposer);
			this->Controls->Add(this->buttonConectarHeadset);
			this->Controls->Add(this->textBoxDisplay);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button0);
			this->Name = L"Form1";
			this->Text = L"Teclado Numérico - Acelerômetro";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeMyComponents(void)
		{
			flagConectado = 0;
		}

#pragma endregion

//
// FUNCAO DE CARREGAMENTO DO FORM
//
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 buttonConectarHeadset->Select();
		 }

//
// FUNCAO QUE FINALIZA O PROGRAMA
//
private: System::Void buttonSair_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }

//
// FUNCAO DE CONEXAO COM HEADSET
//
private: System::Void buttonConectarHeadset_Click(System::Object^  sender, System::EventArgs^  e) {

			textBoxConsole->Text = textBoxConsole->Text + "---------- HEADSET ---------" + "\r\n";
			textBoxConsole->Text = textBoxConsole->Text + "Conectando ao Headset." + "\r\n";
			
			if (EE_EngineConnect() != EDK_OK) {
				textBoxConsole->Text = textBoxConsole->Text + "Falha na inicialização do motor Emotiv" + "\r\n";
			}else{
				flagConectado = 1;
				textBoxConsole->Text = textBoxConsole->Text + "\r\n";
				textBoxConsole->Text = textBoxConsole->Text + "------- FUNÇÃO DO HEADSET -------" + "\r\n";
				textBoxConsole->Text = textBoxConsole->Text + "Conectado, aguardando comandos." + "\r\n";
				button0->Select();
			}
			
		 }
};
}

