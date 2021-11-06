#pragma once
namespace Dyn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	public ref class SzukLiczbPierw
	{
	private: System::Int32 i_max;
	private: TextBox^ pole;
	private:delegate void wyswDelegat1(System::Int32 i);
	private: System::Void wyswietl1(System::Int32 i)
	{
		pole->AppendText(i.ToString() + System::Environment::NewLine);
	}
		   // konstruktor
	public: SzukLiczbPierw(System::Int32 gora, TextBox^ ramka)
	{
		i_max = gora;
		pole = ramka;
	}
		  // metoda obliczeñ
	public: System::Void watek1()
	{
		wyswDelegat1^ wyswietlDelegat =
			gcnew wyswDelegat1(this, &SzukLiczbPierw::wyswietl1);
		System::Int32 n = 2;
		for (System::Int32 i = 2; i < Convert::ToInt32(i_max); i++)
		{
			n = 2;
			while ((i % n)) n++;
			if (i == n)
				pole->Invoke(wyswietlDelegat, gcnew array <System::Object^>(1) { i });
		}
	}
	}; // koniec class SzukLiczbPierw


	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(82, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 78);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 42);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(367, 109);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(244, 163);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(135, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->label1->Location = System::Drawing::Point(13, 163);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(206, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Górna granica liczb";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 362);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


private: System::Void button1_Click(System::Object^ sender,
	System::EventArgs^ e)
{
	// konieczne dla wyeliminowania startu z polem pustym !!
	if (textBox2->Text == "") { textBox2->Text = "800"; }
	System::Int32 jk = Convert::ToInt32(textBox2->Text);
	SzukLiczbPierw^ obliczenia =
		gcnew SzukLiczbPierw(jk, textBox1);
	Thread^ watek_liczenia =
		gcnew Thread(gcnew ThreadStart(obliczenia,
			&SzukLiczbPierw::watek1));
	watek_liczenia->Start();
}

};
}