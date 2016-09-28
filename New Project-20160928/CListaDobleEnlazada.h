#pragma once
#ifndef _CLISTADOBLEENLAZADA_H_
#define _CLISTADOBLEELAZADA_H_

using namespace std;
using namespace System::Drawing;

template<typename T>

class CNodoDE //Doblemente enlazada
{
	T elem;
	CNodoDE<T>* Next; //Siguiente
	CNodoDE<T>* Pre; //Preerior
public:
	CNodoDE(T elem = 0, CNodoDE<T>* Next = nullptr, CNodoDE<T>*Pre = nullptr) : elem(elem), Next(Next), Pre(Pre) {}

	T Getelem();
	CNodoDE<T>* GetNext();
	CNodoDE<T>* GetPre();

	void  Setelem(T elem);
	void  SetNext(CNodoDE<T>* Next);
	void  SetPre(CNodoDE<T>* Pre);	
	

	void dibujar(Graphics^ gr, int x, int y, int largo, int alto, int numeroNodo);
};


template <typename T>
T CNodoDE<T>::Getelem()
{
	return elem;
}

template <typename T>
CNodoDE<T>* CNodoDE<T>::GetNext()
{
	return Next;
}

template <typename T>
CNodoDE<T>* CNodoDE<T>::GetPre()
{
	return Pre;
}

template <typename T>
void CNodoDE<T>::Setelem(T elem)
{
	this->elem = elem;
}

template <typename T>
void CNodoDE<T>::SetNext(CNodoDE<T>* Next)
{
	this->Next = Next;
}

template <typename T>
void CNodoDE<T>::SetPre(CNodoDE<T>* Pre)
{
	this->Pre = Pre;
}

template <typename T>
void CNodoDE<T>::dibujar(Graphics^ gr, int x, int y, int largo, int alto, int nroNodo)
{
	gr->DrawString(Convert::ToString(nroNodo), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Red), x - 14, y - 20);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x - 60, y, largo, alto);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x - 10, y, largo - 50, alto);
	gr->DrawString(Convert::ToString(elem), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x - 40, y + 19);
	gr->DrawString("Next", gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x-5, y + 18);
	gr->DrawLine(gcnew Pen(Color::White), Point(x + 30, y + 21), Point(x + 70, y + 21));
	gr->DrawLine(gcnew Pen(Color::White), Point(x + 34, y + 31), Point(x + 74, y + 31));
	gr->DrawString(">", gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), x + 68, y + 13);
	gr->DrawString("<", gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), x + 27, y + 23);
}
#endif // !_CONTROLADORDOBLE_H_
