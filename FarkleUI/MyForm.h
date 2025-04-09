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

			// Define allowed area for dice buttons
			allowedArea = System::Drawing::Rectangle(100, 100, 500, 300);
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

	private: System::Windows::Forms::Label^ statusLabel;
		   System::Collections::Generic::List<System::Windows::Forms::Button^>^ dynamicButtons;
		   System::Drawing::Rectangle allowedArea;
	private: System::Windows::Forms::Panel^ diceArea;


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
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->diceArea = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// throwButton
			// 
			this->throwButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->throwButton->BackColor = System::Drawing::SystemColors::Control;
			this->throwButton->Location = System::Drawing::Point(325, 62);
			this->throwButton->Name = L"throwButton";
			this->throwButton->Size = System::Drawing::Size(125, 60);
			this->throwButton->TabIndex = 0;
			this->throwButton->Text = L"Throw dice!";
			this->throwButton->UseVisualStyleBackColor = false;
			this->throwButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// statusLabel
			// 
			this->statusLabel->Location = System::Drawing::Point(325, 9);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(125, 16);
			this->statusLabel->TabIndex = 1;
			this->statusLabel->Text = L"status label";
			this->statusLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// diceArea
			// 
			this->diceArea->BackColor = System::Drawing::Color::Transparent;
			this->diceArea->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diceArea->ForeColor = System::Drawing::Color::Transparent;
			this->diceArea->Location = System::Drawing::Point(12, 152);
			this->diceArea->Name = L"diceArea";
			this->diceArea->Size = System::Drawing::Size(758, 589);
			this->diceArea->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 753);
			this->Controls->Add(this->diceArea);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->throwButton);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Farkle";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Update the label text
		statusLabel->Text = "Button clicked!!";

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
			newButton->Size = System::Drawing::Size(80, 40);
			diceArea->Controls->Add(newButton);

			// Then calculate positions relative to panel:
			int x = rand() % (diceArea->Width - newButton->Width);
			int y = rand() % (diceArea->Height - newButton->Height);

			// Set button properties
			newButton->Name = String::Format("button{0}", dynamicButtons->Count);
			newButton->Location = System::Drawing::Point(x, y);
			newButton->Size = System::Drawing::Size(100, 50);
			newButton->Text = String::Format("{0}", rand() % 6 + 1);
			newButton->BackColor = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256);

			// Add click handler
			newButton->Click += gcnew EventHandler(this, &MyForm::DynamicButton_Click);

			dynamicButtons->Add(newButton);
		}
	}
		   System::Void DynamicButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ clickedButton = (Button^)sender;
			   MessageBox::Show(String::Format("You clicked {0} at position ({1}, {2})",
				   clickedButton->Name,
				   clickedButton->Location.X,
				   clickedButton->Location.Y));
		   }


	};
}
