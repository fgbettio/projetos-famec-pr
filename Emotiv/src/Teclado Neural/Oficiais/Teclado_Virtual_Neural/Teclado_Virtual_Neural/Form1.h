#include <edk.h>
#include <edkErrorCode.h>
#include <iostream>
#include <conio.h>
#pragma comment(lib, "edk.lib")
#pragma once

namespace Teclado_Virtual_Neural {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Adicionado para uso do conversor String para const char
	using namespace System::Runtime::InteropServices;

	using namespace std;
	
	//using System.Collections.Generic; 
	//using Emotiv; 
	//using namespace System::OI; 
	//using System::Threading; 
	//using System::Reflection;
	
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::Button^  button31;
	private: System::Windows::Forms::Button^  button32;
	private: System::Windows::Forms::Button^  button33;
	private: System::Windows::Forms::Button^  button34;
	private: System::Windows::Forms::Button^  button35;
	private: System::Windows::Forms::Button^  button36;
	private: System::Windows::Forms::Button^  button37;
	private: System::Windows::Forms::Button^  button38;
	private: System::Windows::Forms::Button^  button39;
	private: System::Windows::Forms::Button^  button40;
	private: System::Windows::Forms::Button^  button41;
	private: System::Windows::Forms::Button^  button42;
	private: System::Windows::Forms::Button^  button43;
	private: System::Windows::Forms::Button^  button44;
	private: System::Windows::Forms::Button^  button45;
	private: System::Windows::Forms::Button^  button46;
	private: System::Windows::Forms::Button^  button47;
	private: System::Windows::Forms::Button^  button48;
	private: System::Windows::Forms::Button^  button49;
	private: System::Windows::Forms::Button^  button50;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button51;
	private: System::Windows::Forms::Button^  button52;
	private: System::Windows::Forms::Button^  button53;
	private: System::Windows::Forms::Button^  button54;
	private: System::Windows::Forms::Button^  button55;
	private: System::Windows::Forms::Button^  button56;
	private: System::Windows::Forms::Button^  button57;
	private: System::Windows::Forms::Button^  button58;
	private: System::Windows::Forms::Button^  button59;
	private: System::Windows::Forms::Button^  button60;
	private: System::Windows::Forms::Button^  button61;
	private: System::Windows::Forms::Button^  button62;
	private: System::Windows::Forms::Button^  button63;
	private: System::Windows::Forms::TextBox^  status;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button64;
	private: System::Windows::Forms::Button^  button65;
	private: EmoEngineEventHandle eEvent;
	private: EmoStateHandle eState;
	//private: unsigned int userID;
	private: unsigned short composerPort;
	private: int option, state, 
		blink, lookLeft, lookRight, 
		countBlink, countLookLeft, countLookRight, 
		tempBlink, tempLookLeft, tempLookRight, contMapButton,
		flagConectado;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button66;
private: System::Windows::Forms::Button^  button67;
private: System::Windows::Forms::Button^  button68;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->button60 = (gcnew System::Windows::Forms::Button());
			this->button61 = (gcnew System::Windows::Forms::Button());
			this->button62 = (gcnew System::Windows::Forms::Button());
			this->button63 = (gcnew System::Windows::Forms::Button());
			this->status = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button64 = (gcnew System::Windows::Forms::Button());
			this->button65 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button66 = (gcnew System::Windows::Forms::Button());
			this->button67 = (gcnew System::Windows::Forms::Button());
			this->button68 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(70, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(33, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Q";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(80, 239);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"A";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(90, 279);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(33, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Z";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(129, 279);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(33, 34);
			this->button4->TabIndex = 5;
			this->button4->Text = L"X";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(119, 239);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(33, 34);
			this->button5->TabIndex = 4;
			this->button5->Text = L"S";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(109, 199);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(33, 34);
			this->button6->TabIndex = 3;
			this->button6->Text = L"W";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(168, 279);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(33, 34);
			this->button7->TabIndex = 8;
			this->button7->Text = L"C";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(158, 239);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(33, 34);
			this->button8->TabIndex = 7;
			this->button8->Text = L"D";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(148, 199);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(33, 34);
			this->button9->TabIndex = 6;
			this->button9->Text = L"E";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(285, 279);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(33, 34);
			this->button10->TabIndex = 17;
			this->button10->Text = L"N";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(275, 239);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(33, 34);
			this->button11->TabIndex = 16;
			this->button11->Text = L"H";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(265, 199);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(33, 34);
			this->button12->TabIndex = 15;
			this->button12->Text = L"Y";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(246, 279);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(33, 34);
			this->button13->TabIndex = 14;
			this->button13->Text = L"B";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(236, 239);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(33, 34);
			this->button14->TabIndex = 13;
			this->button14->Text = L"G";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(226, 199);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(33, 34);
			this->button15->TabIndex = 12;
			this->button15->Text = L"T";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(207, 279);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(33, 34);
			this->button16->TabIndex = 11;
			this->button16->Text = L"V";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(197, 239);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(33, 34);
			this->button17->TabIndex = 10;
			this->button17->Text = L"F";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(187, 199);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(33, 34);
			this->button18->TabIndex = 9;
			this->button18->Text = L"R";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(402, 279);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(33, 34);
			this->button19->TabIndex = 26;
			this->button19->Text = L".";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(392, 239);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(33, 34);
			this->button20->TabIndex = 25;
			this->button20->Text = L"L";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(382, 199);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(33, 34);
			this->button21->TabIndex = 24;
			this->button21->Text = L"O";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(363, 279);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(33, 34);
			this->button22->TabIndex = 23;
			this->button22->Text = L",";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(353, 239);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(33, 34);
			this->button23->TabIndex = 22;
			this->button23->Text = L"K";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Form1::button23_Click);
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(343, 199);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(33, 34);
			this->button24->TabIndex = 21;
			this->button24->Text = L"I";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &Form1::button24_Click);
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(324, 279);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(33, 34);
			this->button25->TabIndex = 20;
			this->button25->Text = L"M";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Form1::button25_Click);
			// 
			// button26
			// 
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button26->Location = System::Drawing::Point(314, 239);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(33, 34);
			this->button26->TabIndex = 19;
			this->button26->Text = L"J";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &Form1::button26_Click);
			// 
			// button27
			// 
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button27->Location = System::Drawing::Point(304, 199);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(33, 34);
			this->button27->TabIndex = 18;
			this->button27->Text = L"U";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &Form1::button27_Click);
			// 
			// button29
			// 
			this->button29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button29->Location = System::Drawing::Point(509, 239);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(33, 34);
			this->button29->TabIndex = 34;
			this->button29->Text = L"]";
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button30->Location = System::Drawing::Point(499, 199);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(33, 34);
			this->button30->TabIndex = 33;
			this->button30->Text = L"[";
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button31->Location = System::Drawing::Point(480, 279);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(33, 34);
			this->button31->TabIndex = 32;
			this->button31->Text = L"Q";
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button32->Location = System::Drawing::Point(470, 239);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(33, 34);
			this->button32->TabIndex = 31;
			this->button32->Text = L"~";
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button33->Location = System::Drawing::Point(460, 199);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(33, 34);
			this->button33->TabIndex = 30;
			this->button33->Text = L"´";
			this->button33->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button34->Location = System::Drawing::Point(441, 279);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(33, 34);
			this->button34->TabIndex = 29;
			this->button34->Text = L";";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &Form1::button34_Click);
			// 
			// button35
			// 
			this->button35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button35->Location = System::Drawing::Point(431, 239);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(33, 34);
			this->button35->TabIndex = 28;
			this->button35->Text = L"Ç";
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &Form1::button35_Click);
			// 
			// button36
			// 
			this->button36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button36->Location = System::Drawing::Point(421, 199);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(33, 34);
			this->button36->TabIndex = 27;
			this->button36->Text = L"P";
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &Form1::button36_Click);
			// 
			// button37
			// 
			this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button37->Location = System::Drawing::Point(480, 159);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(33, 34);
			this->button37->TabIndex = 47;
			this->button37->Text = L"=";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &Form1::button37_Click);
			// 
			// button38
			// 
			this->button38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button38->Location = System::Drawing::Point(441, 159);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(33, 34);
			this->button38->TabIndex = 46;
			this->button38->Text = L"-";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &Form1::button38_Click);
			// 
			// button39
			// 
			this->button39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button39->Location = System::Drawing::Point(402, 159);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(33, 34);
			this->button39->TabIndex = 45;
			this->button39->Text = L"0";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &Form1::button39_Click);
			// 
			// button40
			// 
			this->button40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button40->Location = System::Drawing::Point(363, 159);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(33, 34);
			this->button40->TabIndex = 44;
			this->button40->Text = L"9";
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &Form1::button40_Click);
			// 
			// button41
			// 
			this->button41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button41->Location = System::Drawing::Point(324, 159);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(33, 34);
			this->button41->TabIndex = 43;
			this->button41->Text = L"8";
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &Form1::button41_Click);
			// 
			// button42
			// 
			this->button42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button42->Location = System::Drawing::Point(285, 159);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(33, 34);
			this->button42->TabIndex = 42;
			this->button42->Text = L"7";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &Form1::button42_Click);
			// 
			// button43
			// 
			this->button43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button43->Location = System::Drawing::Point(246, 159);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(33, 34);
			this->button43->TabIndex = 41;
			this->button43->Text = L"6";
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &Form1::button43_Click);
			// 
			// button44
			// 
			this->button44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button44->Location = System::Drawing::Point(207, 159);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(33, 34);
			this->button44->TabIndex = 40;
			this->button44->Text = L"5";
			this->button44->UseVisualStyleBackColor = true;
			this->button44->Click += gcnew System::EventHandler(this, &Form1::button44_Click);
			// 
			// button45
			// 
			this->button45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button45->Location = System::Drawing::Point(168, 159);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(33, 34);
			this->button45->TabIndex = 39;
			this->button45->Text = L"4";
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &Form1::button45_Click);
			// 
			// button46
			// 
			this->button46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button46->Location = System::Drawing::Point(129, 159);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(33, 34);
			this->button46->TabIndex = 38;
			this->button46->Text = L"3";
			this->button46->UseVisualStyleBackColor = true;
			this->button46->Click += gcnew System::EventHandler(this, &Form1::button46_Click);
			// 
			// button47
			// 
			this->button47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button47->Location = System::Drawing::Point(90, 159);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(33, 34);
			this->button47->TabIndex = 37;
			this->button47->Text = L"2";
			this->button47->UseVisualStyleBackColor = true;
			this->button47->Click += gcnew System::EventHandler(this, &Form1::button47_Click);
			// 
			// button48
			// 
			this->button48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button48->Location = System::Drawing::Point(51, 159);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(33, 34);
			this->button48->TabIndex = 36;
			this->button48->Text = L"1";
			this->button48->UseVisualStyleBackColor = true;
			this->button48->Click += gcnew System::EventHandler(this, &Form1::button48_Click);
			// 
			// button49
			// 
			this->button49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button49->Location = System::Drawing::Point(12, 159);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(33, 34);
			this->button49->TabIndex = 48;
			this->button49->Text = L"\'";
			this->button49->UseVisualStyleBackColor = true;
			// 
			// button50
			// 
			this->button50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button50->Location = System::Drawing::Point(51, 279);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(33, 34);
			this->button50->TabIndex = 49;
			this->button50->Text = L"Q";
			this->button50->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button28->Location = System::Drawing::Point(12, 199);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(52, 34);
			this->button28->TabIndex = 50;
			this->button28->Text = L"Tab";
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button51
			// 
			this->button51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button51->Location = System::Drawing::Point(12, 239);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(62, 34);
			this->button51->TabIndex = 51;
			this->button51->Text = L"Caps";
			this->button51->UseVisualStyleBackColor = true;
			// 
			// button52
			// 
			this->button52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button52->Location = System::Drawing::Point(12, 279);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(33, 34);
			this->button52->TabIndex = 52;
			this->button52->Text = L"Sh";
			this->button52->UseVisualStyleBackColor = true;
			// 
			// button53
			// 
			this->button53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button53->Location = System::Drawing::Point(12, 319);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(43, 34);
			this->button53->TabIndex = 53;
			this->button53->Text = L"Ctrl";
			this->button53->UseVisualStyleBackColor = true;
			// 
			// button54
			// 
			this->button54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button54->Location = System::Drawing::Point(61, 319);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(42, 34);
			this->button54->TabIndex = 54;
			this->button54->Text = L"Q";
			this->button54->UseVisualStyleBackColor = true;
			// 
			// button55
			// 
			this->button55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button55->Location = System::Drawing::Point(109, 319);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(43, 34);
			this->button55->TabIndex = 55;
			this->button55->Text = L"Alt";
			this->button55->UseVisualStyleBackColor = true;
			// 
			// button56
			// 
			this->button56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button56->Location = System::Drawing::Point(158, 319);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(218, 34);
			this->button56->TabIndex = 56;
			this->button56->Text = L"Espaço";
			this->button56->UseVisualStyleBackColor = true;
			this->button56->Click += gcnew System::EventHandler(this, &Form1::button56_Click);
			// 
			// button57
			// 
			this->button57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button57->Location = System::Drawing::Point(382, 319);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(43, 34);
			this->button57->TabIndex = 57;
			this->button57->Text = L"Alt";
			this->button57->UseVisualStyleBackColor = true;
			// 
			// button58
			// 
			this->button58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button58->Location = System::Drawing::Point(431, 319);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(43, 34);
			this->button58->TabIndex = 58;
			this->button58->Text = L"Q";
			this->button58->UseVisualStyleBackColor = true;
			// 
			// button59
			// 
			this->button59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button59->Location = System::Drawing::Point(480, 319);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(33, 34);
			this->button59->TabIndex = 59;
			this->button59->Text = L"Q";
			this->button59->UseVisualStyleBackColor = true;
			// 
			// button60
			// 
			this->button60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button60->Location = System::Drawing::Point(519, 319);
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(76, 34);
			this->button60->TabIndex = 60;
			this->button60->Text = L"Ctrl";
			this->button60->UseVisualStyleBackColor = true;
			// 
			// button61
			// 
			this->button61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button61->Location = System::Drawing::Point(519, 279);
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(76, 34);
			this->button61->TabIndex = 61;
			this->button61->Text = L"Shift";
			this->button61->UseVisualStyleBackColor = true;
			// 
			// button62
			// 
			this->button62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button62->Location = System::Drawing::Point(548, 199);
			this->button62->Name = L"button62";
			this->button62->Size = System::Drawing::Size(47, 74);
			this->button62->TabIndex = 62;
			this->button62->Text = L"Enter";
			this->button62->UseVisualStyleBackColor = true;
			this->button62->Click += gcnew System::EventHandler(this, &Form1::button62_Click);
			// 
			// button63
			// 
			this->button63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button63->Location = System::Drawing::Point(519, 159);
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(76, 34);
			this->button63->TabIndex = 63;
			this->button63->Text = L"Back";
			this->button63->UseVisualStyleBackColor = true;
			this->button63->Click += gcnew System::EventHandler(this, &Form1::button63_Click);
			// 
			// status
			// 
			this->status->AcceptsReturn = true;
			this->status->BackColor = System::Drawing::SystemColors::Info;
			this->status->Location = System::Drawing::Point(616, 52);
			this->status->Multiline = true;
			this->status->Name = L"status";
			this->status->ReadOnly = true;
			this->status->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->status->Size = System::Drawing::Size(276, 301);
			this->status->TabIndex = 64;
			this->status->TextChanged += gcnew System::EventHandler(this, &Form1::status_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(12, 52);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(583, 101);
			this->textBox1->TabIndex = 65;
			// 
			// button64
			// 
			this->button64->Location = System::Drawing::Point(12, 12);
			this->button64->Name = L"button64";
			this->button64->Size = System::Drawing::Size(123, 23);
			this->button64->TabIndex = 66;
			this->button64->Text = L"Conectar Headset";
			this->button64->UseVisualStyleBackColor = true;
			this->button64->Click += gcnew System::EventHandler(this, &Form1::button64_Click);
			// 
			// button65
			// 
			this->button65->Location = System::Drawing::Point(151, 12);
			this->button65->Name = L"button65";
			this->button65->Size = System::Drawing::Size(169, 23);
			this->button65->TabIndex = 67;
			this->button65->Text = L"Conectar EmoComposer";
			this->button65->UseVisualStyleBackColor = true;
			this->button65->Click += gcnew System::EventHandler(this, &Form1::button65_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(613, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 68;
			this->label1->Text = L"Logging panel:";
			// 
			// button66
			// 
			this->button66->Location = System::Drawing::Point(340, 12);
			this->button66->Name = L"button66";
			this->button66->Size = System::Drawing::Size(75, 23);
			this->button66->TabIndex = 69;
			this->button66->Text = L"Sair";
			this->button66->UseVisualStyleBackColor = true;
			this->button66->Click += gcnew System::EventHandler(this, &Form1::button66_Click);
			// 
			// button67
			// 
			this->button67->Location = System::Drawing::Point(499, 12);
			this->button67->Name = L"button67";
			this->button67->Size = System::Drawing::Size(75, 23);
			this->button67->TabIndex = 70;
			this->button67->Text = L"Gyroscope";
			this->button67->UseVisualStyleBackColor = true;
			this->button67->Click += gcnew System::EventHandler(this, &Form1::button67_Click);
			// 
			// button68
			// 
			this->button68->Location = System::Drawing::Point(709, 12);
			this->button68->Name = L"button68";
			this->button68->Size = System::Drawing::Size(95, 23);
			this->button68->TabIndex = 71;
			this->button68->Text = L"Mudar Cursor";
			this->button68->UseVisualStyleBackColor = true;
			this->button68->Click += gcnew System::EventHandler(this, &Form1::button68_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 380);
			this->Controls->Add(this->button68);
			this->Controls->Add(this->button67);
			this->Controls->Add(this->button66);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button65);
			this->Controls->Add(this->button64);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->status);
			this->Controls->Add(this->button63);
			this->Controls->Add(this->button62);
			this->Controls->Add(this->button61);
			this->Controls->Add(this->button60);
			this->Controls->Add(this->button59);
			this->Controls->Add(this->button58);
			this->Controls->Add(this->button57);
			this->Controls->Add(this->button56);
			this->Controls->Add(this->button55);
			this->Controls->Add(this->button54);
			this->Controls->Add(this->button53);
			this->Controls->Add(this->button52);
			this->Controls->Add(this->button51);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button50);
			this->Controls->Add(this->button49);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button38);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button40);
			this->Controls->Add(this->button41);
			this->Controls->Add(this->button42);
			this->Controls->Add(this->button43);
			this->Controls->Add(this->button44);
			this->Controls->Add(this->button45);
			this->Controls->Add(this->button46);
			this->Controls->Add(this->button47);
			this->Controls->Add(this->button48);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Teclado Virtual Neural";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeMyComponents(void)
		{
			eEvent = EE_EmoEngineEventCreate();
			eState = EE_EmoStateCreate();
			//userID = 0;
			composerPort = 1726;
			option = 0; 
			state = 0;
			blink = 0; 
			lookLeft = 0; 
			lookRight = 0;
			countBlink = 0; 
			countLookLeft = 0; 
			countLookRight = 0;
			tempBlink = 0;
			tempLookLeft = 0; 
			tempLookRight = 0;
			contMapButton = 29;
			flagConectado = 0;
		}
#pragma endregion

// conversor int to string
/*
public std::string intToStr (int i) {
    std::ostringstream s;
    s << i;
    return s.str();
}
*/

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 cout << "foi";
			 button2->Select(); //Inicializando o focus no botão espaço
		 }

private: System::Void status_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void button56_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + " ";
		 }

private: System::Void button64_Click(System::Object^  sender, System::EventArgs^  e) {
			
			status->Text = status->Text + "---------- HEADSET v1 ---------" + "\r\n";
			status->Text = status->Text + "Conectando ao Headset." + "\r\n";

			if (EE_EngineConnect() != EDK_OK) {
				status->Text = status->Text + "Falha na inicialização do motor Emotiv" + "\r\n";
			}else{
				flagConectado = 1;
				status->Text = status->Text + "\r\n";
				status->Text = status->Text + "------- FUNÇÃO DO HEADSET -------" + "\r\n";
				status->Text = status->Text + "Conectado, aguardando comandos." + "\r\n";
				button2->Select();
			}
		 }

private: System::Void button65_Click(System::Object^  sender, System::EventArgs^  e) {
			
			status->Text = status->Text + "--------- EMO-COMPOSER ---------" + "\r\n";
			status->Text = status->Text + "Conectando ao EmoComposer." + "\r\n";

			String ^ input = gcnew String("127.0.0.1");
			
			const char* str = (const char*) (Marshal::StringToHGlobalAnsi(input)).ToPointer();

			if (EE_EngineRemoteConnect(str, composerPort) != EDK_OK) {
				status->Text = status->Text + "Não foi possível conectar ao EmoComposer" + "\r\n";
			}else{
				flagConectado = 1;
				status->Text = status->Text + "\r\n";
				status->Text = status->Text + "------- FUNÇÃO DO EMO-COMPOSER -------" + "\r\n";
				status->Text = status->Text + "Conectado, aguardando instruções EmoComposer." + "\r\n";
				button2->Select();
			}
		 }

private: System::Void button62_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "\r\n";
		 }

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

			 //status->Text = "Teste";

			//Verificar se o flag é de conectado ou não - 1 = conectado, 2 = não conectado
			 if(flagConectado == 0){
				return;
			 }
			 
			//int dx; 
			//int dy;
			//int result;
			
			//result = EE_HeadsetGetGyroDelta (0, &dx, &dy);
			//EmoEngine.Instance.HeadsetGetGyroDelta(0, dx, dy); 

			//status->Text = "Timer: DX: " + dx + ", DY: " + dy + ", result: " + result + "\r\n";

			//status->SelectionStart = status->Text->Length;
			//status->ScrollToCaret();

			//textBox1->SelectionStart = textBox1->Text->Length;
			//textBox1->ScrollToCaret();

			//return;
			

			unsigned int userID = 0;

			state = EE_EngineGetNextEvent(eEvent);
				
			// New event needs to be handled
			if (state == EDK_OK) {

				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);

				// Erro nessa linha: cannot convert parameter 2 from 'cli::interior_ptr<Type>' to 'unsigned int *'
				EE_EmoEngineEventGetUserId(eEvent, &userID);

				// Log the EmoState if it has been updated
				if (eventType == EE_EmoStateUpdated)
				{
					EE_EmoEngineEventGetEmoState(eEvent, eState);
						
					lookLeft = ES_ExpressivIsLookingLeft(eState);
					lookRight = ES_ExpressivIsLookingRight(eState);
					blink = ES_ExpressivIsBlink(eState);

					//status->Text = status->Text + "Esquerda: " + lookLeft + ", direta: "+ lookRight +"\r\n";
						
					if(lookRight==1)
					{
						status->Text = status->Text + "Olhou para a direita!" + "\r\n";
						contMapButton++;
						if(contMapButton > 63){
							contMapButton = 1;
						}
						status->Text = status->Text + "Numero do mapa do teclado: " + contMapButton + "\r\n";
						chamarSwitch(contMapButton, blink);
					}
					if(lookLeft==1)
					{
						status->Text = status->Text + "Olhou para esquerda!" + "\r\n";
						contMapButton--;
						if(contMapButton < 1){
							contMapButton = 63;
						}
						status->Text = status->Text + "Numero do mapa do teclado: " + contMapButton + "\r\n";
						chamarSwitch(contMapButton, blink);
					}

					if(blink==1){
						status->Text = status->Text + "Piscou!" + "\r\n";
						status->Text = status->Text + "Numero do mapa do teclado: " + contMapButton + "\r\n";
						chamarSwitch(contMapButton, blink);
					}
				}

				// codigo mostra os valores do gyroscope

				//int dx; 
				//int dy;
				//int result;
			
				//result = EE_HeadsetGetGyroDelta (0, &dx, &dy);
				//EmoEngine.Instance.HeadsetGetGyroDelta(0, out dx, out dy); 

				//status->Text = status->Text + "DX: " + dx + ", DY: " + dy + ", result: " + result + "\r\n";


			}
			else if (state != EDK_NO_EVENT) {
				status->Text = status->Text + "Erro interno no Emotiv Engine!" + "\r\n";
			}

			//Efeito AutoScroll - Não é a melhor pratica, o scroll fica piscando conforme
			// a velocidade aplicada nas ações de digitação.
			statusAutoScroll();
			textBox1AutoScroll();
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			textBox1->Text = textBox1->Text + "A";
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "S";
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "D";
		 }
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "F";
		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "G";
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "H";
		 }
private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "J";
		 }
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "K";
		 }
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "L";
		 }
private: System::Void button35_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "Ç";
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "Z";
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "X";
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "C";
		 }
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "V";
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "B";
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "N";
		 }
private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "M";
		 }
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + ",";
		 }
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + ".";
		 }
private: System::Void button34_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + ";";
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "Q";
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "W";
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "E";
		 }
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "R";
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "T";
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "Y";
		 }
private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "U";
		 }
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "I";
		 }
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "O";
		 }
private: System::Void button36_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "P";
		 }
private: System::Void button48_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "1";
		 }
private: System::Void button47_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "2";
		 }
private: System::Void button46_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "3";
		 }
private: System::Void button45_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "4";
		 }
private: System::Void button44_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "5";
		 }
private: System::Void button43_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "6";
		 }
private: System::Void button42_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "7";
		 }
private: System::Void button41_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "8";
		 }
private: System::Void button40_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "9";
		 }
private: System::Void button39_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "0";
		 }
private: System::Void button38_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "-";
		 }
private: System::Void button37_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = textBox1->Text + "=";
		 }
private: System::Void button63_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Backspace
			 String ^ texto = gcnew String(textBox1->Text);
			 if(texto->Length > 0){
				texto = texto->Remove(texto->Length -1);
				textBox1->Text = texto;
			 }
		 }
private: System::Void button66_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: void chamarSwitch(int contMapButton, int blink1){
		 
			status->Text = status->Text + "Chamou switch!" + "\r\n";

			switch(contMapButton){
						
				case 1:
					if(blink1==1){
						button49->PerformClick();
					}else{
						button49->Select();
					}		
					break;
				case 2:
					if(blink1==1){
						button48->PerformClick();
					}else{
						button48->Select();
					}							
					break;
				case 3:
					if(blink1==1){
						button47->PerformClick();
					}else{
						button47->Select();
					}
					break;
				case 4:
					if(blink1==1){
						button46->PerformClick();
					}else{
						button46->Select();
					}					
					break;
				case 5:
					if(blink1==1){
						button45->PerformClick();
					}else{
						button45->Select();
					}
					break;
				case 6:
					if(blink1==1){
						button44->PerformClick();
					}else{
						button44->Select();
					}					
					break;
				case 7:
					if(blink1==1){
						button43->PerformClick();
					}else{
						button43->Select();
					}					
					break;
				case 8:
					if(blink1==1){
						button42->PerformClick();
					}else{
						button42->Select();
					}					
					break;
				case 9:
					if(blink1==1){
						button41->PerformClick();
					}else{
						button41->Select();
					}					
					break;
				case 10:
					if(blink1==1){
						button40->PerformClick();
					}else{
						button40->Select();
					}
					break;
				case 11:
					if(blink1==1){
						button39->PerformClick();
					}else{
						button39->Select();
					}
					break;
				case 12:
					if(blink1==1){
						button38->PerformClick();
					}else{
						button38->Select();
					}
					break;
				case 13:
					if(blink1==1){
						button37->PerformClick();
					}else{
						button37->Select();
					}
					break;
				case 14:
					if(blink1==1){
						button63->PerformClick();
					}else{
						button63->Select();
					}
					break;
				case 15:
					if(blink1==1){
						button28->PerformClick();
					}else{
						button28->Select();
					}
					break;
				case 16:
					if(blink1==1){
						button1->PerformClick();
					}else{
						button1->Select();
					}
					break;
				case 17:
					if(blink1==1){
						button6->PerformClick();
					}else{
						button6->Select();
					}
					break;
				case 18:
					if(blink1==1){
						button9->PerformClick();
					}else{
						button9->Select();
					}
					break;
				case 19:
					if(blink1==1){
						button18->PerformClick();
					}else{
						button18->Select();
					}
					break;
				case 20:
					if(blink1==1){
						button15->PerformClick();
					}else{
						button15->Select();
					}
					break;
				case 21:
					if(blink1==1){
						button12->PerformClick();
					}else{
						button12->Select();
					}
					break;
				case 22:
					if(blink1==1){
						button27->PerformClick();
					}else{
						button27->Select();
					}
					break;
				case 23:
					if(blink1==1){
						button24->PerformClick();
					}else{
						button24->Select();
					}
					break;
				case 24:
					if(blink1==1){
						button21->PerformClick();
					}else{
						button21->Select();
					}
					break;
				case 25:
					if(blink1==1){
						button36->PerformClick();
					}else{
						button36->Select();
					}
					break;
				case 26:
					if(blink1==1){
						button33->PerformClick();
					}else{
						button33->Select();
					}
					break;
				case 27:
					if(blink1==1){
						button30->PerformClick();
					}else{
						button30->Select();
					}
					break;
				case 28:
					if(blink1==1){
						button51->PerformClick();
					}else{
						button51->Select();
					}
					break;
				case 29:
					if(blink1==1){
						button2->PerformClick();
					}else{
						button2->Select();
					}
					break;
				case 30:
					if(blink1==1){
						button5->PerformClick();
					}else{
						button5->Select();
					}
					break;
				case 31:
					if(blink1==1){
						button8->PerformClick();
					}else{
						button8->Select();
					}
					break;
				case 32:
					if(blink1==1){
						button17->PerformClick();
					}else{
						button17->Select();
					}
					break;
				case 33:
					if(blink1==1){
						button14->PerformClick();
					}else{
						button14->Select();
					}
					break;
				case 34:
					if(blink1==1){
						button11->PerformClick();
					}else{
						button11->Select();
					}
					break;
				case 35:
					if(blink1==1){
						button26->PerformClick();
					}else{
						button26->Select();
					}
					break;
				case 36:
					if(blink1==1){
						button23->PerformClick();
					}else{
						button23->Select();
					}
					break;
				case 37:
					if(blink1==1){
						button20->PerformClick();
					}else{
						button20->Select();
					}
					break;
				case 38:
					if(blink1==1){
						button35->PerformClick();
					}else{
						button35->Select();
					}
					break;
				case 39:
					if(blink1==1){
						button32->PerformClick();
					}else{
						button32->Select();
					}
					break;
				case 40:
					if(blink1==1){
						button29->PerformClick();
					}else{
						button29->Select();
					}
					break;
				case 41:
					if(blink1==1){
						button62->PerformClick();
					}else{
						button62->Select();
					}
					break;
				case 42:
					if(blink1==1){
						button52->PerformClick();
					}else{
						button52->Select();
					}
					break;
				case 43:
					if(blink1==1){
						button50->PerformClick();
					}else{
						button50->Select();
					}
					break;
				case 44:
					if(blink1==1){
						button3->PerformClick();
					}else{
						button3->Select();
					}
					break;
				case 45:
					if(blink1==1){
						button4->PerformClick();
					}else{
						button4->Select();
					}
					break;
				case 46:
					if(blink1==1){
						button7->PerformClick();
					}else{
						button7->Select();
					}
					break;
				case 47:
					if(blink1==1){
						button16->PerformClick();
					}else{
						button16->Select();
					}
					break;
				case 48:
					if(blink1==1){
						button13->PerformClick();
					}else{
						button13->Select();
					}
					break;
				case 49:
					if(blink1==1){
						button10->PerformClick();
					}else{
						button10->Select();
					}
					break;
				case 50:
					if(blink1==1){
						button25->PerformClick();
					}else{
						button25->Select();
					}
					break;
				case 51:
					if(blink1==1){
						button22->PerformClick();
					}else{
						button22->Select();
					}
					break;
				case 52:
					if(blink1==1){
						button19->PerformClick();
					}else{
						button19->Select();
					}
					break;
				case 53:
					if(blink1==1){
						button34->PerformClick();
					}else{
						button34->Select();
					}
					break;
				case 54:
					if(blink1==1){
						button31->PerformClick();
					}else{
						button31->Select();
					}
					break;
				case 55:
					if(blink1==1){
						button61->PerformClick();
					}else{
						button61->Select();
					}
					break;
				case 56:
					if(blink1==1){
						button53->PerformClick();
					}else{
						button53->Select();
					}
					break;
				case 57:
					if(blink1==1){
						button54->PerformClick();
					}else{
						button54->Select();
					}
					break;
				case 58:
					if(blink1==1){
						button55->PerformClick();
					}else{
						button55->Select();
					}
					break;
				case 59:
					if(blink1==1){
						button56->PerformClick();
					}else{
						button56->Select();
					}
					break;
				case 60:
					if(blink1==1){
						button57->PerformClick();
					}else{
						button57->Select();
					}
					break;
				case 61:
					if(blink1==1){
						button58->PerformClick();
					}else{
						button58->Select();
					}
					break;
				case 62:
					if(blink1==1){
						button59->PerformClick();
					}else{
						button59->Select();
					}
					break;
				case 63:
					if(blink1==1){
						button60->PerformClick();
					}else{
						button60->Select();
					}		
					break;	
			}
		}

private: void textBox1AutoScroll(void){
			textBox1->SelectionStart = textBox1->Text->Length;
			textBox1->ScrollToCaret();
		 }
private: void statusAutoScroll(void){
			status->SelectionStart = status->Text->Length;
			status->ScrollToCaret();
		 }
private: System::Void button67_Click(System::Object^  sender, System::EventArgs^  e) {


			int dx; 
			int dy;
			int result;
			
			result = EE_HeadsetGetGyroDelta (0, &dx, &dy);
			//EmoEngine.Instance.HeadsetGetGyroDelta(0, out dx, out dy); 

			status->Text = "DX: " + dx + ", DY: " + dy + ", result: " + result + "\r\n";


		 }
private: System::Void button68_Click(System::Object^  sender, System::EventArgs^  e) {

			status->Text = status->Text + "Clicou! \r\n";

			int mx = 100;
			int my = 100;

			//SetCursorPos(mx, my);

			status->Text = "mx: " + mx + ", my: " + my + "\r\n";


		 }
};

}

