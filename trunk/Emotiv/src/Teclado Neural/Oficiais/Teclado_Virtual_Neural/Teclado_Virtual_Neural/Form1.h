#include <edk.h>
#include <edkErrorCode.h>
#pragma comment(lib, "edk.lib")
#pragma once

namespace Teclado_Virtual_Neural {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	// Adicionado para uso do conversor String para const char
	using namespace System::Runtime::InteropServices;

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
	private: unsigned int userID;
	private: unsigned short composerPort;
	private: int option, state, 
		blink, lookLeft, lookRight, 
		countBlink, countLookLeft, countLookRight, 
		tempBlink, tempLookLeft, tempLookRight;
	Thread ^th1;

	protected: 

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(131, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(33, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Q";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(141, 250);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"A";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(151, 290);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(33, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Z";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(190, 290);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(33, 34);
			this->button4->TabIndex = 5;
			this->button4->Text = L"X";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(180, 250);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(33, 34);
			this->button5->TabIndex = 4;
			this->button5->Text = L"S";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(170, 210);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(33, 34);
			this->button6->TabIndex = 3;
			this->button6->Text = L"W";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(229, 290);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(33, 34);
			this->button7->TabIndex = 8;
			this->button7->Text = L"C";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(219, 250);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(33, 34);
			this->button8->TabIndex = 7;
			this->button8->Text = L"D";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(209, 210);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(33, 34);
			this->button9->TabIndex = 6;
			this->button9->Text = L"E";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(346, 290);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(33, 34);
			this->button10->TabIndex = 17;
			this->button10->Text = L"N";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(336, 250);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(33, 34);
			this->button11->TabIndex = 16;
			this->button11->Text = L"H";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(326, 210);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(33, 34);
			this->button12->TabIndex = 15;
			this->button12->Text = L"Y";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(307, 290);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(33, 34);
			this->button13->TabIndex = 14;
			this->button13->Text = L"B";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(297, 250);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(33, 34);
			this->button14->TabIndex = 13;
			this->button14->Text = L"G";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(287, 210);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(33, 34);
			this->button15->TabIndex = 12;
			this->button15->Text = L"T";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(268, 290);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(33, 34);
			this->button16->TabIndex = 11;
			this->button16->Text = L"V";
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(258, 250);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(33, 34);
			this->button17->TabIndex = 10;
			this->button17->Text = L"F";
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(248, 210);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(33, 34);
			this->button18->TabIndex = 9;
			this->button18->Text = L"R";
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(463, 290);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(33, 34);
			this->button19->TabIndex = 26;
			this->button19->Text = L".";
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(453, 250);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(33, 34);
			this->button20->TabIndex = 25;
			this->button20->Text = L"L";
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(443, 210);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(33, 34);
			this->button21->TabIndex = 24;
			this->button21->Text = L"O";
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(424, 290);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(33, 34);
			this->button22->TabIndex = 23;
			this->button22->Text = L",";
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(414, 250);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(33, 34);
			this->button23->TabIndex = 22;
			this->button23->Text = L"K";
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button24->Location = System::Drawing::Point(404, 210);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(33, 34);
			this->button24->TabIndex = 21;
			this->button24->Text = L"I";
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button25->Location = System::Drawing::Point(385, 290);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(33, 34);
			this->button25->TabIndex = 20;
			this->button25->Text = L"M";
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button26->Location = System::Drawing::Point(375, 250);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(33, 34);
			this->button26->TabIndex = 19;
			this->button26->Text = L"J";
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button27->Location = System::Drawing::Point(365, 210);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(33, 34);
			this->button27->TabIndex = 18;
			this->button27->Text = L"U";
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button29->Location = System::Drawing::Point(570, 250);
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
			this->button30->Location = System::Drawing::Point(560, 210);
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
			this->button31->Location = System::Drawing::Point(541, 290);
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
			this->button32->Location = System::Drawing::Point(531, 250);
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
			this->button33->Location = System::Drawing::Point(521, 210);
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
			this->button34->Location = System::Drawing::Point(502, 290);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(33, 34);
			this->button34->TabIndex = 29;
			this->button34->Text = L";";
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button35->Location = System::Drawing::Point(492, 250);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(33, 34);
			this->button35->TabIndex = 28;
			this->button35->Text = L"Ç";
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button36->Location = System::Drawing::Point(482, 210);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(33, 34);
			this->button36->TabIndex = 27;
			this->button36->Text = L"P";
			this->button36->UseVisualStyleBackColor = true;
			// 
			// button37
			// 
			this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button37->Location = System::Drawing::Point(541, 170);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(33, 34);
			this->button37->TabIndex = 47;
			this->button37->Text = L"=";
			this->button37->UseVisualStyleBackColor = true;
			// 
			// button38
			// 
			this->button38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button38->Location = System::Drawing::Point(502, 170);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(33, 34);
			this->button38->TabIndex = 46;
			this->button38->Text = L"-";
			this->button38->UseVisualStyleBackColor = true;
			// 
			// button39
			// 
			this->button39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button39->Location = System::Drawing::Point(463, 170);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(33, 34);
			this->button39->TabIndex = 45;
			this->button39->Text = L"0";
			this->button39->UseVisualStyleBackColor = true;
			// 
			// button40
			// 
			this->button40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button40->Location = System::Drawing::Point(424, 170);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(33, 34);
			this->button40->TabIndex = 44;
			this->button40->Text = L"9";
			this->button40->UseVisualStyleBackColor = true;
			// 
			// button41
			// 
			this->button41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button41->Location = System::Drawing::Point(385, 170);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(33, 34);
			this->button41->TabIndex = 43;
			this->button41->Text = L"8";
			this->button41->UseVisualStyleBackColor = true;
			// 
			// button42
			// 
			this->button42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button42->Location = System::Drawing::Point(346, 170);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(33, 34);
			this->button42->TabIndex = 42;
			this->button42->Text = L"7";
			this->button42->UseVisualStyleBackColor = true;
			// 
			// button43
			// 
			this->button43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button43->Location = System::Drawing::Point(307, 170);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(33, 34);
			this->button43->TabIndex = 41;
			this->button43->Text = L"6";
			this->button43->UseVisualStyleBackColor = true;
			// 
			// button44
			// 
			this->button44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button44->Location = System::Drawing::Point(268, 170);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(33, 34);
			this->button44->TabIndex = 40;
			this->button44->Text = L"5";
			this->button44->UseVisualStyleBackColor = true;
			// 
			// button45
			// 
			this->button45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button45->Location = System::Drawing::Point(229, 170);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(33, 34);
			this->button45->TabIndex = 39;
			this->button45->Text = L"4";
			this->button45->UseVisualStyleBackColor = true;
			// 
			// button46
			// 
			this->button46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button46->Location = System::Drawing::Point(190, 170);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(33, 34);
			this->button46->TabIndex = 38;
			this->button46->Text = L"3";
			this->button46->UseVisualStyleBackColor = true;
			// 
			// button47
			// 
			this->button47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button47->Location = System::Drawing::Point(151, 170);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(33, 34);
			this->button47->TabIndex = 37;
			this->button47->Text = L"2";
			this->button47->UseVisualStyleBackColor = true;
			// 
			// button48
			// 
			this->button48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button48->Location = System::Drawing::Point(112, 170);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(33, 34);
			this->button48->TabIndex = 36;
			this->button48->Text = L"1";
			this->button48->UseVisualStyleBackColor = true;
			// 
			// button49
			// 
			this->button49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button49->Location = System::Drawing::Point(73, 170);
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
			this->button50->Location = System::Drawing::Point(112, 290);
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
			this->button28->Location = System::Drawing::Point(73, 210);
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
			this->button51->Location = System::Drawing::Point(73, 250);
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
			this->button52->Location = System::Drawing::Point(73, 290);
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
			this->button53->Location = System::Drawing::Point(73, 330);
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
			this->button54->Location = System::Drawing::Point(122, 330);
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
			this->button55->Location = System::Drawing::Point(170, 330);
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
			this->button56->Location = System::Drawing::Point(219, 330);
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
			this->button57->Location = System::Drawing::Point(443, 330);
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
			this->button58->Location = System::Drawing::Point(492, 330);
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
			this->button59->Location = System::Drawing::Point(541, 330);
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
			this->button60->Location = System::Drawing::Point(580, 330);
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
			this->button61->Location = System::Drawing::Point(580, 290);
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
			this->button62->Location = System::Drawing::Point(609, 210);
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
			this->button63->Location = System::Drawing::Point(580, 170);
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(76, 34);
			this->button63->TabIndex = 63;
			this->button63->Text = L"Back";
			this->button63->UseVisualStyleBackColor = true;
			// 
			// status
			// 
			this->status->Location = System::Drawing::Point(73, 371);
			this->status->Multiline = true;
			this->status->Name = L"status";
			this->status->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->status->Size = System::Drawing::Size(583, 55);
			this->status->TabIndex = 64;
			this->status->TextChanged += gcnew System::EventHandler(this, &Form1::status_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 63);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(726, 438);
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
			userID = 0;
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
			th1 = gcnew Thread(gcnew ThreadStart(this, &Form1::th1Method));

		}
#pragma endregion
static double time = 0.0;

private: System::Void th1Method()
         {
			 // TODO erro neste codigo
             for(int i=0;i<500;i++)
             {
                 this.BeginInvoke
				 ((Action)(
					() =>
					{
						
						
					   textBox1->Text = time.ToString();
					   time += 0.1;
					}
				 )) ;
				Thread::Sleep(1);
             }
         }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {	
		 }

private: System::Void status_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void button56_Click(System::Object^  sender, System::EventArgs^  e) {
			 status->Text = status->Text + "Botão 56" + "\r\n";
		 }

private: System::Void button64_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 status->Text = "";
			 status->Text = status->Text + "Conectando ao Headset." + "\r\n";

			if (EE_EngineConnect() != EDK_OK) {
				status->Text = status->Text + "Falha na inicialização do motor Emotiv" + "\r\n";
			}else{
				status->Text = status->Text + "Conectado, aguardando comandos." + "\r\n";
			}
		 }

private: System::Void button65_Click(System::Object^  sender, System::EventArgs^  e) {
			
			status->Text = "";			 
			status->Text = status->Text + "Conectando ao EmoComposer." + "\r\n";

			String ^ input = gcnew String("127.0.0.1");
			
			const char* str = (const char*) (Marshal::StringToHGlobalAnsi(input)).ToPointer();

			if (EE_EngineRemoteConnect(str, composerPort) != EDK_OK) {
				status->Text = status->Text + "Não foi possível conectar ao EmoComposer" + "\r\n";
			}else{
				status->Text = status->Text + "Conectado, aguardando instruções EmoComposer." + "\r\n";
			}
		 }

private: System::Void button62_Click(System::Object^  sender, System::EventArgs^  e) {
			 th1->Start();
		 }
};
}

