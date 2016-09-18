#include<iostream>
#include <stdio.h> 
#include <stdlib.h>

#pragma once

namespace pro2 {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private:
		// dizide týklanan butonlarýn kooradinatlarýný tutuyor
		array<Int32, 2>^ dizi = gcnew array<Int32, 2>(15, 2);
		//diziye seçili düðüm koordinatlarý atanýrken indis deðeri olarak kullanýlýr
	public: int sayac = 0, sayac2 = 0;
	private: array<Int32>^ ziyaretEdilen = gcnew array<Int32>(15); // seçilen düðümleri tutar
	private: array<Int32, 2>^ uzaklik; //düðümler arasýndaki uzakliði tutar
	private: 
		// array<Int32, 2>^ butonmatrisi = gcnew array<Int32, 2>(20, 20);
	public:
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
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	public: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Button^  button;
	public: int dugum = 0;
	private: System::Windows::Forms::Label^  label1;
	public:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		//private: System::ComponentModel.IContainer components = null;
	private: System::ComponentModel::IContainer ^components;
			 int mesafe;
			 int u;
			 int v;
			 int dugumSayisi = 1;

			 int min = 0;
			 //	 System::ComponentModel::Container ^components = null;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->AutoSize = true;
				 this->tableLayoutPanel1->ColumnCount = 20;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 5)));
				 this->tableLayoutPanel1->Location = System::Drawing::Point(26, 50);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 20;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(800, 450);
				 this->tableLayoutPanel1->TabIndex = 0;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(889, 72);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(0, 13);
				 this->label1->TabIndex = 1;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(833, 3);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(92, 44);
				 this->button1->TabIndex = 2;
				 this->button1->Text = L"KOMSULUK MATRISLERI";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(961, 3);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(86, 44);
				 this->button2->TabIndex = 3;
				 this->button2->Text = L"PRÝM DUGUMLERI";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(23, 660);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(106, 13);
				 this->label2->TabIndex = 4;
				 this->label2->Text = L"TOPLAM MALIYET :";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->ClientSize = System::Drawing::Size(1059, 682);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
			 // PRÝM algoritmasý
			 //http://scanftree.com/Data_Structure/prim's-algorithm prim algoritmasý bu siteden alýndý
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->label1->Text += "\nEn Kýsa Yol Algoritmasý (Prim Düðümleri)\n";

		ziyaretEdilen[1] = 1;

		while (dugumSayisi < dugum)
		{			
			min = 999;
			for (int i	= 0; i < dugum; i++)
			{
				for (int j = 0; j < dugum; j++)
				{
					if (uzaklik[i, j] < min)
					{
						if (ziyaretEdilen[i] != 0)
						{
							min = uzaklik[i, j];
							u = i;
							v = j;
						}
					}
				}
			}

			if (ziyaretEdilen[u] == 0 || ziyaretEdilen[v] == 0)
			{
				dugumSayisi++;
				this->label1->Text += " Düðüm" + u.ToString() + "-Düðüm" + v.ToString() + "=" + min.ToString() + " br\n";

				// RENKLENDÝRME
/*#pragma region en kýsa yolu boyama
				int basNokY, basNokX, bitNokX, bitNokY;
				if (dizi[u, 1] <= dizi[v, 1])
				{
					if (dizi[u, 1] != 0)
					{
						basNokX = dizi[u, 1];
						bitNokX = dizi[v, 1];
						basNokY = dizi[v, 0];
					}
					else
					{
						basNokY = matrix[v, 1];
						bitNokY = matrix[u, 1];
						basNokX = matrix[u, 0];
						basNokX = dizi[u, 1];
						bitNokX = dizi[v, 1];
						basNokY = dizi[u, 0];
					}
				}
				else
				{
					basNokX = dizi[v, 1];
					bitNokX = dizi[u, 1];
					basNokY = dizi[u, 0];
				}

				for (int sayac = basNokX; sayac <= bitNokX - 1; sayac++)
				{
					this->tableLayoutPanel1->GetControlFromPosition(basNokY, sayac)->BackColor = System::Drawing::Color::FromArgb(0, 255, 0);
				}

				if (dizi[u, 0] <= dizi[v, 0])
				{
					basNokY = dizi[u, 0];
					bitNokY = dizi[v, 0];
				}
				else
				{
					basNokY = dizi[v, 0];
					bitNokY = dizi[u, 0];
				}

				if (dizi[u, 1] <= dizi[v, 1])
				{
					if (dizi[u, 1] != 0)
					{
						bitNokX = dizi[u, 1];
					}
					else
					{
						bitNokX = dizi[v, 1];
					}
				}
				else
				{
					bitNokX = dizi[v, 1];
				}

				for (int sayac = basNokY; sayac <= bitNokY - 1; sayac++)
				{
					this->tableLayoutPanel1->GetControlFromPosition(sayac, bitNokX)->BackColor = System::Drawing::Color::FromArgb(0, 255, 0);
				}
#pragma endregion
				*/
				//minimum uzaklýk mesafeye eklenerek toplam maliyet hesaplamasý yapýlýr.
				mesafe += min;
				ziyaretEdilen[v] = 1;
			}

			uzaklik[u, v] = 999;
			uzaklik[v, u] = 999;
		}

		this->label2->Text += mesafe.ToString() + " br";
	}

			 //form yüklenirken labellar ve butonlar kod yardýmýyla oluþturuluyor
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		int labelX = 26, labelY = 57;

		//400 tane buton oluþturulur
		for (int sayici = 0; sayici < 20; sayici++)
		{
			for (int sayici2 = 0; sayici2 < 20; sayici2++)
			{
				button = gcnew Button();
				button->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
				button->Name = sayici.ToString() + "-" + sayici2.ToString();
				button->AutoSize = true;
				button->Text = "D?";
				button->Size = System::Drawing::Size(20, 15);
				this->Controls->Add(button);
				this->tableLayoutPanel1->Controls->Add(button, sayici2, sayici);
			}
		}

		//LABEL SOLDAN SAÐA
		for (int sayici = 0; sayici < 20; sayici++)
		{
			label = gcnew Label();
			label->AutoSize = true;
			label->Location = System::Drawing::Point(labelX, 31);
			label->Name = sayici.ToString();
			label->Size = System::Drawing::Size(13, 13);
			label->TabIndex = 1;
			label->Text = sayici.ToString();
			labelX += 40.5;
			this->Controls->Add(label);
		}

		//LABEL YUKARIDAN AÞAÐI
		for (int sayici = 0; sayici < 20; sayici++)
		{
			label = gcnew Label();
			label->AutoSize = true;
			label->Location = System::Drawing::Point(9, labelY);
			label->Name = sayici.ToString();
			label->Size = System::Drawing::Size(13, 13);
			label->TabIndex = 1;
			label->Text = sayici.ToString();
			labelY += 29;
			this->Controls->Add(label);
		}

	}

			 //butona her týklandýðýnda buton renk deðiþtirir ve sýradaki düðümün ismini text olarak alýr
	private: System::Void buttonClick(System::Object^ sender, System::EventArgs^ e){
		
		//týklanan component buton olarak gösterilir(buton gibiymiþ davranýr).
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = BackColor.Red;
		if (dugum == 0)
			this->label1->Text += "Kullanýcýnýn Seçtiði Düðümler\n\n";
		
		//her düðüm seçildiðinde düðüm sayýsý artýrýlýr.
		dugum++;

		//buton sýradaki düðümün ismini alýr.
		button->Text = "D" + (dugum - 1).ToString();

		//seçilen düðüm labelda gösterilir.
		this->label1->Text += "Düðüm" + (dugum - 1).ToString() + " : " + button->Name + "\n";

		//her butona týklandýðýnda butonun ismi split edilerek dizi arrayine atanýr(her düðümün koordinatý)
		String^ splitText = "-";
		array<Char>^ spliter = splitText->ToCharArray();
		array<String^>^ koordinat;
		String^ satir = button->Name;

		koordinat = satir->Split(spliter);
		for (int kelime = 0; kelime < koordinat->Length; kelime++)
		{
			//koordinat alma iþlemi yapýlarak diziye atanýr. örneðin koordinat{lenght=2} / [0]=5, [1]=6 gibi x ve y koordinatlarý bulunur.
			dizi[sayac, sayac2] = Convert::ToInt32(koordinat[kelime]);
			sayac2++;
		}

		sayac++;
		sayac2 = 0;

	}

			 //komþuluk matrislerini oluþturur.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		uzaklik = gcnew array<Int32, 2>(dugum, dugum);
		

		// Warning
		if (dugum > 1)
		{
			this->label1->Text += "Düðümlerin Birbirlerine Uzaklýklarý (Komþuluk Matrisleri)\n";
			int dugum_uzaklik;

			//labela komþuluk matrislerini(düðümler arasýndaki mesafe) yazdýrmak için
			for (int sayici = 0; sayici < dugum - 1; sayici++)
			{
				for (int sayici2 = sayici; sayici2 < dugum - 1; sayici2++)
				{
					//dugum uzaklýk deðiþkeni x ve y deðiþkenlerinin farký alýnýp toplandýðýnda aradaki uzaklýðý buluyor fakat düðüme ulaþmak için bir eklenmelidir.
					dugum_uzaklik = abs(dizi[sayici, 0] - dizi[sayici2 + 1, 0]) + abs(dizi[sayici, 1] - dizi[sayici2 + 1, 1]);
					this->label1->Text += "Düðüm" + sayici.ToString() + "-Düðüm" + (sayici2 + 1).ToString() + ":" + dugum_uzaklik.ToString() + " br\n";
				}
			}

			//komþuluk matrislerini(düðümler arasýndaki mesafe) uzaklýk dizisine atamak için
			for (int sayici = 0; sayici < dugum; sayici++)
			{
				for (int sayici2 = 0; sayici2 < dugum; sayici2++)
				{
					//uzaklik eþitse düðümün kendisini iþaret etmektedir
					if (sayici == sayici2)
						uzaklik[sayici, sayici2] = 0;
					else
					{
						dugum_uzaklik = abs(dizi[sayici, 0] - dizi[sayici2, 0]) + abs(dizi[sayici, 1] - dizi[sayici2, 1]);
						if (dugum_uzaklik == 1)
							// gidilen düðüm uzakliði 1 olursa bunun uzaklik id si 999 olur
							uzaklik[sayici, sayici2] = 1;
						else
							uzaklik[sayici, sayici2] = dugum_uzaklik;
					}
				}
			}
		}

	}


	};
}


