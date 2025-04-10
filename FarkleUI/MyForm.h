#pragma once

#include <stdlib.h> // For rand()
#include <time.h> // For time()
#include <vector>

namespace FarkleUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(time(NULL));
			dynamicButtons = gcnew System::Collections::Generic::List<System::Windows::Forms::Button^>();
			throwButton->Enabled = true;
			againButton->Enabled = false;
			passButton->Enabled = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ throwButton;
	protected:

	protected:

	protected:


		   System::Collections::Generic::List<System::Windows::Forms::Button^>^ dynamicButtons;
		   System::Drawing::Rectangle allowedArea;
	private: System::Windows::Forms::Panel^ diceArea;
	private: System::Windows::Forms::Button^ againButton;


	private: System::Windows::Forms::Button^ passButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->throwButton = (gcnew System::Windows::Forms::Button());
			this->diceArea = (gcnew System::Windows::Forms::Panel());
			this->againButton = (gcnew System::Windows::Forms::Button());
			this->passButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// throwButton
			// 
			this->throwButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->throwButton->BackColor = System::Drawing::SystemColors::Control;
			this->throwButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->throwButton->Location = System::Drawing::Point(12, 12);
			this->throwButton->Name = L"throwButton";
			this->throwButton->Size = System::Drawing::Size(125, 60);
			this->throwButton->TabIndex = 0;
			this->throwButton->Text = L"Throw dice!";
			this->throwButton->UseVisualStyleBackColor = false;
			this->throwButton->Click += gcnew System::EventHandler(this, &MyForm::diceThrower);
			// 
			// diceArea
			// 
			this->diceArea->BackColor = System::Drawing::Color::Transparent;
			this->diceArea->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diceArea->ForeColor = System::Drawing::Color::Transparent;
			this->diceArea->Location = System::Drawing::Point(12, 217);
			this->diceArea->Name = L"diceArea";
			this->diceArea->Size = System::Drawing::Size(758, 536);
			this->diceArea->TabIndex = 2;
			// 
			// againButton
			// 
			this->againButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->againButton->BackColor = System::Drawing::SystemColors::Control;
			this->againButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->againButton->Location = System::Drawing::Point(325, 12);
			this->againButton->Name = L"againButton";
			this->againButton->Size = System::Drawing::Size(125, 60);
			this->againButton->TabIndex = 3;
			this->againButton->Text = L"Score and roll again";
			this->againButton->UseVisualStyleBackColor = false;
			// 
			// passButton
			// 
			this->passButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passButton->BackColor = System::Drawing::SystemColors::Control;
			this->passButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passButton->Location = System::Drawing::Point(645, 12);
			this->passButton->Name = L"passButton";
			this->passButton->Size = System::Drawing::Size(125, 60);
			this->passButton->TabIndex = 5;
			this->passButton->Text = L"Score and pass";
			this->passButton->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(321, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Total/4000";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(432, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"0";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(321, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"This Round";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(432, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"0";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(321, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Selected";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(432, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"0";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 765);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->passButton);
			this->Controls->Add(this->againButton);
			this->Controls->Add(this->diceArea);
			this->Controls->Add(this->throwButton);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Farkle";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void diceThrower(System::Object^ sender, System::EventArgs^ e)
	{
		// Remove all existing dynamic buttons
		for each (Button ^ btn in dynamicButtons) {
			diceArea->Controls->Remove(btn);
			// Remove click handler to prevent memory leaks
			btn->Click -= gcnew EventHandler(this, &MyForm::DynamicButton_Click);
		}
		dynamicButtons->Clear();

		// Create new buttons (dice)
		for (int i = 0; i < 6; i++)
		{
			Button^ newButton = gcnew Button();
			newButton->Size = System::Drawing::Size(90, 90);
			diceArea->Controls->Add(newButton);

			// Try to find a non-overlapping position
			Point newPos;
			bool posFound = false;
			int attempts = 0;
			const int maxAttempts = 100; //  Seems to work fine as low as 10, but 100 is a safe bet without risking being too slow

			do {
				// Calc random position within panel
				newPos = Point(
					rand() % (diceArea->Width - newButton->Width),
					rand() % (diceArea->Height - newButton->Height)
				);

				// Check if position is valid (non-overlapping)
				posFound = !IsOverlapping(newButton, newPos);
				attempts++;

			} while (!posFound && attempts < maxAttempts);

			if (!posFound)
			{
				// Couldn't find non-overlap position
				MessageBox::Show("Couldn't place all buttons without overlapping!");
				delete newButton;
				continue;
			}

			// Set button properties
			newButton->Name = String::Format("button{0}", dynamicButtons->Count);
			newButton->Location = newPos;
			newButton->Text = String::Format("{0}", rand() % 6 + 1);
			newButton->Font = gcnew System::Drawing::Font(
				newButton->Font->FontFamily, // Same font family
				20.0f, // Font size
				newButton->Font->Style // Keep same style
			);
			//newButton->BackColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256);
			newButton->BackColor = Color::Black;
			newButton->ForeColor = Color::White;
			newButton->FlatStyle = FlatStyle::Flat;
			newButton->FlatAppearance->BorderSize = 0;
			newButton->FlatAppearance->MouseOverBackColor = Color::LightGray;
			newButton->FlatAppearance->MouseDownBackColor = Color::DarkGray;

			// Add click handler
			newButton->Click += gcnew EventHandler(this, &MyForm::DynamicButton_Click);

			dynamicButtons->Add(newButton);

			// Update control buttons
			throwButton->Enabled = false;
			againButton->Enabled = true;
			passButton->Enabled = true;
		}
	}

	System::Void DynamicButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ clickedButton = (Button^)sender;

		/* Test code
		* MessageBox::Show(String::Format("You clicked {0} at position ({1}, {2})",
			clickedButton->Name,
			clickedButton->Location.X,
			clickedButton->Location.Y));
		*/

		// Set border if adding to selection, else remove border to deselect
		if (clickedButton->FlatAppearance->BorderSize == 0)
		{
			clickedButton->FlatAppearance->BorderSize = 3;
			clickedButton->FlatAppearance->BorderColor = Color::LimeGreen;
		}
		else
		{
			clickedButton->FlatAppearance->BorderSize = 0;
		}
	}

	// Determine if new button (die) location intersects with any existing button (die)
	private: bool IsOverlapping(Button^ newButton, Point proposedLocation)
	{
		Rectangle newRect = Rectangle(proposedLocation, newButton->Size);

		// Check against all existing buttons
		for each(Button ^ existingButton in dynamicButtons)
		{
			Rectangle existingRect = Rectangle(existingButton->Location, existingButton->Size);
			if (newRect.IntersectsWith(existingRect))
			{
				return true;
			}
		}
		return false;
	}
	};
}
