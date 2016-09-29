#pragma once
#ifndef _CLISTAENLAZADAPUNTEROFINAL_H_
#define _CLISTAENLAZADAPUNTEROFINAL_H_

using namespace std;
using namespace System::Drawing;

template<typename T>
class CNodoo
{
	T elem;
	CNodoo<T>* next;

public:
	CNodoo(T elem = 0, CNodoo<T>* next = nullptr) :elem(elem), next(next) {}

	T getelem();
	CNodoo<T>* getneext();

	void seteleem(T elem);
	void setneext(CNodoo<T>* next);
	void dibujar(Graphics^ gr, int x, int y, int largo, int alto, int numeroNodo);
};

template<typename T>
T CNodoo<T>::getelem()
{
	return elem;
}

template <typename T>
CNodoo<T>* CNodoo<T>::getneext()
{
	return next;
}

template <typename T>
void CNodoo<T>::seteleem(T elem)
{
	this->elem = elem;
}

template <typename T>
void CNodoo<T>::setneext(CNodoo<T>* next)
{
	this->next = next;
}

template <typename T>
void CNodoo<T>::dibujar(Graphics^ gr, int x, int y, int largo, int alto, int nroNodo)
{
	gr->DrawString(Convert::ToString(nroNodo), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Red), x - 14, y - 20);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x - 60, y, largo, alto);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x - 10, y, largo - 50, alto);
	gr->DrawString(Convert::ToString(elem), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x - 40, y + 19);
	gr->DrawString("Next", gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x, y + 18);
	gr->DrawLine(gcnew Pen(Color::White), Point(x + 30, y + 27), Point(x + 65, y + 27));
	gr->DrawString(">", gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), x + 63, y + 19);
}
#endif
