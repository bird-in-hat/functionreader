#pragma once

#include <msclr\marshal_cppstd.h>
#include "fparser.hh";
#include "optlib.h"; 

namespace optigui {

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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::ComboBox^  cbFunctions;
	private: System::Windows::Forms::TextBox^  tbNewFunc;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::TextBox^  tbLB;
	private: System::Windows::Forms::TextBox^  tbRB;
	protected:




	private: System::Windows::Forms::TextBox^  tbEpsilon;
	private: System::Windows::Forms::TextBox^  tbRel;
	private: System::Windows::Forms::Button^  btnOptimize;
	private: System::Windows::Forms::TextBox^  tbResult;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cbMethod;



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
            this->cbFunctions = (gcnew System::Windows::Forms::ComboBox());
            this->tbNewFunc = (gcnew System::Windows::Forms::TextBox());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->tbLB = (gcnew System::Windows::Forms::TextBox());
            this->tbRB = (gcnew System::Windows::Forms::TextBox());
            this->tbEpsilon = (gcnew System::Windows::Forms::TextBox());
            this->tbRel = (gcnew System::Windows::Forms::TextBox());
            this->btnOptimize = (gcnew System::Windows::Forms::Button());
            this->tbResult = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->cbMethod = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // cbFunctions
            // 
            this->cbFunctions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->cbFunctions->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
                L"1+x*x+cos(18*x*x)", L"10+x*x- 10*cos(2*pi*x)",
                    L"x*cos(x)-12*sin(x)"
            });
            this->cbFunctions->Location = System::Drawing::Point(137, 54);
            this->cbFunctions->Name = L"cbFunctions";
            this->cbFunctions->Size = System::Drawing::Size(269, 21);
            this->cbFunctions->TabIndex = 0;
            this->cbFunctions->Text = L"1+x*x+cos(18*x*x)";
            this->cbFunctions->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbFunctions_SelectedIndexChanged);
            // 
            // tbNewFunc
            // 
            this->tbNewFunc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tbNewFunc->Location = System::Drawing::Point(137, 81);
            this->tbNewFunc->Name = L"tbNewFunc";
            this->tbNewFunc->Size = System::Drawing::Size(188, 20);
            this->tbNewFunc->TabIndex = 1;
            // 
            // btnAdd
            // 
            this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnAdd->Location = System::Drawing::Point(331, 80);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(75, 21);
            this->btnAdd->TabIndex = 2;
            this->btnAdd->Text = L"Add";
            this->btnAdd->UseVisualStyleBackColor = true;
            this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
            // 
            // tbLB
            // 
            this->tbLB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tbLB->Location = System::Drawing::Point(303, 159);
            this->tbLB->Name = L"tbLB";
            this->tbLB->Size = System::Drawing::Size(47, 20);
            this->tbLB->TabIndex = 3;
            this->tbLB->Text = L"-0,5";
            // 
            // tbRB
            // 
            this->tbRB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tbRB->Location = System::Drawing::Point(358, 159);
            this->tbRB->Name = L"tbRB";
            this->tbRB->Size = System::Drawing::Size(48, 20);
            this->tbRB->TabIndex = 4;
            this->tbRB->Text = L"0,5";
            // 
            // tbEpsilon
            // 
            this->tbEpsilon->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tbEpsilon->Location = System::Drawing::Point(303, 107);
            this->tbEpsilon->Name = L"tbEpsilon";
            this->tbEpsilon->Size = System::Drawing::Size(103, 20);
            this->tbEpsilon->TabIndex = 5;
            this->tbEpsilon->Text = L"0,001";
            // 
            // tbRel
            // 
            this->tbRel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->tbRel->Location = System::Drawing::Point(303, 133);
            this->tbRel->Name = L"tbRel";
            this->tbRel->Size = System::Drawing::Size(103, 20);
            this->tbRel->TabIndex = 6;
            this->tbRel->Text = L"2,4";
            // 
            // btnOptimize
            // 
            this->btnOptimize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnOptimize->Location = System::Drawing::Point(331, 217);
            this->btnOptimize->Name = L"btnOptimize";
            this->btnOptimize->Size = System::Drawing::Size(75, 29);
            this->btnOptimize->TabIndex = 7;
            this->btnOptimize->Text = L"Optimize";
            this->btnOptimize->UseVisualStyleBackColor = true;
            this->btnOptimize->Click += gcnew System::EventHandler(this, &MyForm::btnOptimize_Click);
            // 
            // tbResult
            // 
            this->tbResult->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tbResult->Location = System::Drawing::Point(12, 252);
            this->tbResult->Multiline = true;
            this->tbResult->Name = L"tbResult";
            this->tbResult->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->tbResult->Size = System::Drawing::Size(394, 125);
            this->tbResult->TabIndex = 8;
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(171, 110);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(41, 13);
            this->label1->TabIndex = 9;
            this->label1->Text = L"Epsilon";
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(161, 136);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(51, 13);
            this->label2->TabIndex = 10;
            this->label2->Text = L"Reliability";
            // 
            // label3
            // 
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(169, 162);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(43, 13);
            this->label3->TabIndex = 11;
            this->label3->Text = L"Borders";
            // 
            // cbMethod
            // 
            this->cbMethod->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->cbMethod->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"AGP", L"Piyavskiy", L"Kushner" });
            this->cbMethod->Location = System::Drawing::Point(137, 12);
            this->cbMethod->Name = L"cbMethod";
            this->cbMethod->Size = System::Drawing::Size(269, 21);
            this->cbMethod->TabIndex = 12;
            this->cbMethod->Text = L"AGP";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(418, 379);
            this->Controls->Add(this->cbMethod);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->tbResult);
            this->Controls->Add(this->btnOptimize);
            this->Controls->Add(this->tbRel);
            this->Controls->Add(this->tbEpsilon);
            this->Controls->Add(this->tbRB);
            this->Controls->Add(this->tbLB);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->tbNewFunc);
            this->Controls->Add(this->cbFunctions);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		cbFunctions->Items->Add(tbNewFunc->Text);
		tbNewFunc->Text = "";
	}


	private: System::Void btnOptimize_Click(System::Object^  sender, System::EventArgs^  e) {
				 String^ s = cbFunctions->SelectedItem->ToString();
				 double eps = System::Convert::ToDouble(tbEpsilon->Text);
				 double r = System::Convert::ToDouble(tbRel->Text);
				 double a = System::Convert::ToDouble(tbLB->Text);
				 double b = System::Convert::ToDouble(tbRB->Text);
				 int n = 0;
				 double x = 0;

				 msclr::interop::marshal_context context;
				 std::string function = context.marshal_as<std::string>(s);
				 FunctionParser fparser;

				 fparser.AddConstant("pi", 3.1415926535897932);
				 fparser.Parse(function, "x");

				 /*while (true)
				 {
					 int res = fparser.Parse(function, "x");
					 if (res < 0) break;

					 //MessageBox::Show(0, fparser.ErrorMsg(), "MessageBox caption", MB_OK);
				 }*/

				 switch (cbMethod->SelectedIndex)
				 {
				 case 0:
					 x = agp(fparser, a, b, r, eps, n);
					 break;
				 case 1:
					 x = piyavskiy(fparser, a, b, r, eps, n);
					 break;
				 case 2:
					 x = kushner(fparser, a, b, eps, n);
					 break;
				 }

				 tbResult->Text = "\r\n" + cbMethod->SelectedItem->ToString() + " result(" 
					 + Convert::ToString(cbFunctions->SelectedIndex) + "): "
					 + System::Convert::ToString(x) + " for " +
					 System::Convert::ToString(n) + " iterations\r\n" + tbResult->Text;
	}

private: System::Void cbFunctions_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
             return;
}
};
}
