#pragma once
#ifndef __CLISTAENLAZADA_H__
#define __CLISTAENLAZADA_H__

using namespace std;
using namespace System::Drawing;

template<typename T>
class CNodo
{
	T elem;
	CNodo<T>* next;

public:
	CNodo(T elem = 0, CNodo<T>* next = nullptr) :elem(elem), next(next) {}

	T getelem();
	CNodo<T>* getnext();

	void setelem(T elem);
	void setnext(CNodo<T>* next);
	void dibujar(Graphics^ gr, int x, int y, int largo, int alto, int numeroNodo);
};


template<typename T>
T CNodo<T>::getelem()
{ 
	return elem;
}

template <typename T>
CNodo<T>* CNodo<T>::getnext() 
{ 
	return next; 
}

template <typename T>
void CNodo<T>::setelem(T elem)
{ 
	this->elem = elem; 
}

template <typename T>
void CNodo<T>::setnext(CNodo<T>* next) 
{ 
	this->next = next; 
}

template <typename T>
void CNodo<T>::dibujar(Graphics^ gr, int x, int y, int largo, int alto, int nroNodo)
{
	gr->DrawString(Convert::ToString(nroNodo), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Red), x - 14 , y - 20);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x-60, y, largo, alto);
	gr->DrawRectangle(gcnew Pen(Color::LawnGreen), x-10, y, largo - 50, alto);
	gr->DrawString(Convert::ToString(elem), gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x - 40, y + 19);
	gr->DrawString("Next", gcnew Font("Arial", 10), gcnew SolidBrush(Color::Yellow), x , y + 18);
	gr->DrawLine(gcnew Pen(Color::White), Point(x + 30, y + 27), Point(x + 65, y + 27));
	gr->DrawString(">", gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), x+63, y + 19);
}
#endif
