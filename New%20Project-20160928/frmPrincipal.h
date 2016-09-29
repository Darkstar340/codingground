#pragma once
#include "Controlador1.h"
#include "ConroladorDoble.h"
#include "ControladorPuntero.h"

namespace TrabajoParcial {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	private:
		CListaEnlazada<int>* objListaEnlazada;
		CNodo<int>* objNodo1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
			 CListaDobleEnlazada<int>*objListaDobleEnlazada;
			 CListaEnlazadaPunteroFinal<int>*objListaEnlazadaPunteroFinal;
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			objListaEnlazada = new CListaEnlazada<int>();
			objListaEnlazada->InsertaralFinal(5);
			objListaEnlazada->InsertaralFinal(45);
			objListaEnlazada->InsertaralFinal(23);

			objListaDobleEnlazada = new CListaDobleEnlazada<int>();
			objListaDobleEnlazada->InsertarEnPosicion(34,0);
			objListaDobleEnlazada->InsertarEnPosicion(23,1);
			objListaDobleEnlazada->InsertarEnPosicion(14,2);

			objListaEnlazadaPunteroFinal = new CListaEnlazadaPunteroFinal<int>();
			objListaEnlazadaPunteroFinal->InsertaralFinal(15);
			objListaEnlazadaPunteroFinal->InsertaralFinal(20);
			objListaEnlazadaPunteroFinal->InsertaralFinal(30);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtDato;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnInsertarInicio;
	private: System::Windows::Forms::Button^  btnInsertarenPosicion;
	private: System::Windows::Forms::Button^  btnInsertaralFinal;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnEliminar;
	private: System::Windows::Forms::TextBox^  txtPosicion;
	private: System::Windows::Forms::TextBox^  txtPosicionElminar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

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
			this->txtDato = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnInsertarInicio = (gcnew System::Windows::Forms::Button());
			this->btnInsertarenPosicion = (gcnew System::Windows::Forms::Button());
			this->btnInsertaralFinal = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->txtPosicion = (gcnew System::Windows::Forms::TextBox());
			this->txtPosicionElminar = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtDato
			// 
			this->txtDato->Location = System::Drawing::Point(34, 58);
			this->txtDato->Name = L"txtDato";
			this->txtDato->Size = System::Drawing::Size(100, 20);
			this->txtDato->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Dato:";
			// 
			// btnInsertarInicio
			// 
			this->btnInsertarInicio->Location = System::Drawing::Point(153, 37);
			this->btnInsertarInicio->Name = L"btnInsertarInicio";
			this->btnInsertarInicio->Size = System::Drawing::Size(100, 41);
			this->btnInsertarInicio->TabIndex = 2;
			this->btnInsertarInicio->Text = L"Insertar al Inicio";
			this->btnInsertarInicio->UseVisualStyleBackColor = true;
			this->btnInsertarInicio->Click += gcnew System::EventHandler(this, &frmPrincipal::btnInsertarInicio_Click);
			// 
			// btnInsertarenPosicion
			// 
			this->btnInsertarenPosicion->Location = System::Drawing::Point(386, 38);
			this->btnInsertarenPosicion->Name = L"btnInsertarenPosicion";
			this->btnInsertarenPosicion->Size = System::Drawing::Size(128, 39);
			this->btnInsertarenPosicion->TabIndex = 3;
			this->btnInsertarenPosicion->Text = L"Insertar en Posición";
			this->btnInsertarenPosicion->UseVisualStyleBackColor = true;
			this->btnInsertarenPosicion->Click += gcnew System::EventHandler(this, &frmPrincipal::btnInsertarenPosicion_Click);
			// 
			// btnInsertaralFinal
			// 
			this->btnInsertaralFinal->Location = System::Drawing::Point(275, 37);
			this->btnInsertaralFinal->Name = L"btnInsertaralFinal";
			this->btnInsertaralFinal->Size = System::Drawing::Size(94, 39);
			this->btnInsertaralFinal->TabIndex = 4;
			this->btnInsertaralFinal->Text = L"Insertar al Final";
			this->btnInsertaralFinal->UseVisualStyleBackColor = true;
			this->btnInsertaralFinal->Click += gcnew System::EventHandler(this, &frmPrincipal::btnInsertaralFinal_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(34, 109);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1077, 351);
			this->panel1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(12, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"label4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(12, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"label2";
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(611, 38);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(116, 39);
			this->btnEliminar->TabIndex = 7;
			this->btnEliminar->Text = L"Eliminar en Posición";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmPrincipal::btnEliminar_Click);
			// 
			// txtPosicion
			// 
			this->txtPosicion->Location = System::Drawing::Point(520, 57);
			this->txtPosicion->Name = L"txtPosicion";
			this->txtPosicion->Size = System::Drawing::Size(85, 20);
			this->txtPosicion->TabIndex = 8;
			// 
			// txtPosicionElminar
			// 
			this->txtPosicionElminar->Location = System::Drawing::Point(733, 57);
			this->txtPosicionElminar->Name = L"txtPosicionElminar";
			this->txtPosicionElminar->Size = System::Drawing::Size(67, 20);
			this->txtPosicionElminar->TabIndex = 9;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmPrincipal::timer1_Tick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(520, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Posición:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(730, 42);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Posición:";
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1123, 481);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtPosicionElminar);
			this->Controls->Add(this->txtPosicion);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnInsertaralFinal);
			this->Controls->Add(this->btnInsertarenPosicion);
			this->Controls->Add(this->btnInsertarInicio);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtDato);
			this->Name = L"frmPrincipal";
			this->Text = L"Listas PLANETARIUM";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	Graphics^ g = panel1->CreateGraphics();
	BufferedGraphicsContext^ esp = BufferedGraphicsManager::Current;
	BufferedGraphics^ gn = esp->Allocate(g, panel1->ClientRectangle);
	

	objListaEnlazada->Dibujar(gn->Graphics);
	objListaDobleEnlazada->Dibujar(gn->Graphics);
	objListaEnlazadaPunteroFinal->Dibujar(gn->Graphics);
	label2->Text = "Lista Simplemente Enlazada";
	label3->Text = "Lista Doblemente Enlazada";
	label4->Text = "Lista simplemente Enlazada con puntero al final";

	gn->Render(g);
	delete gn;
	delete esp;
	delete g;
}
private: System::Void btnInsertarInicio_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDato->Text == "")
	{
		MessageBox::Show("Ingrese un valor por favor.");
		return;
	}
	objListaEnlazada->InsertarInicio(Convert::ToInt32(txtDato->Text));
	objListaDobleEnlazada->InsertarInicio(Convert::ToInt32(txtDato -> Text));
	objListaEnlazadaPunteroFinal->InsertarInicio(Convert::ToInt32(txtDato->Text));
	txtDato->Text = "";

}
private: System::Void btnInsertarenPosicion_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDato->Text == "")
	{
		MessageBox::Show("Ingrese un valor por favor.");
		return;
	}
	if (txtPosicion->Text == "")
	{
		MessageBox::Show("Ingrese una posicion por favor.");
		return;
	}
	objListaEnlazada->InsertarEnPosicion(Convert::ToInt32(txtDato->Text), Convert::ToInt32(txtPosicion->Text));
	objListaDobleEnlazada->InsertarEnPosicion(Convert::ToInt32(txtDato->Text), Convert::ToInt32(txtPosicion->Text));
	objListaEnlazadaPunteroFinal->InsertarEnPosicion(Convert::ToInt32(txtDato->Text), Convert::ToInt32(txtPosicion->Text));

	txtDato->Text = "";
	txtPosicion->Text = "";
}
private: System::Void btnInsertaralFinal_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtDato->Text == "")
	{
		MessageBox::Show("Ingrese un valor valido por favor.");
		return;
	}
	objListaEnlazada->InsertaralFinal(Convert::ToInt32(txtDato->Text));
	objListaDobleEnlazada->InsertarFinal(Convert::ToInt32(txtDato->Text));
	objListaEnlazadaPunteroFinal->InsertaralFinal(Convert::ToInt32(txtDato->Text));
	txtDato->Text = "";
}
private: System::Void btnEliminar_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtPosicionElminar->Text == "")
	{
		MessageBox::Show("Ingrese una posicion por favor.");
		return;
	}
	objListaEnlazada->EliminarenPosicion(Convert::ToInt32(txtPosicionElminar->Text));
	objListaDobleEnlazada->EliminarPosicion(Convert::ToInt32(txtPosicionElminar->Text));
	objListaEnlazadaPunteroFinal->EliminarenPosicion(Convert::ToInt32(txtPosicionElminar->Text));
	txtPosicionElminar->Text = "";
}
};
}
