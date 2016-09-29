#pragma once
#ifndef _CONTROLADORPUNTERO_H_
#define _CONTROLADORPUNTERO_H_

#include "CListaEnlazadaPunteroFinal.h"
template <typename T>

class CListaEnlazadaPunteroFinal
{
	CNodoo <T> *inicio;
	CNodoo<T>* fin;
public:
	CListaEnlazadaPunteroFinal();
	~CListaEnlazadaPunteroFinal();

	void InsertarInicio(T elem);
	void InsertarEnPosicion(T elem, int pos);
	void InsertaralFinal(T elem);

	void EliminarenPosicion(int pos);

	int ObtenerCantidadElementos();

	void MostrarDatos();
	void Dibujar(Graphics^ gr);
};

template <typename T>
CListaEnlazadaPunteroFinal<T>::CListaEnlazadaPunteroFinal()
{
	inicio = nullptr;
	fin = nullptr;
}

template <typename T>
CListaEnlazadaPunteroFinal<T>::~CListaEnlazadaPunteroFinal()
{
	while (inicio != nullptr) {
		CNodoo<T>* aux = inicio;
		inicio = inicio->next;
		delete aux;
	}

	while (fin != nullptr) {
		CNodoo<T>* aux = fin;
		fin = fin->next;
		delete aux;
	}
}


template <typename T> void CListaEnlazadaPunteroFinal<T>::InsertarInicio(T elem) {
	if (inicio == nullptr)
	{
		inicio = new CNodoo <T>(elem);
		fin = inicio;
	}
	else
	{
		CNodoo <T>* nuevo = new CNodoo <T>(elem);

		nuevo->setneext(inicio);
		inicio = nuevo;
	}
}
template <typename T> void CListaEnlazadaPunteroFinal<T>::InsertaralFinal(T elem) {
	if (inicio == nullptr)
	{
		inicio = new CNodoo <T>(elem);
		fin = inicio;
	}
	else if (inicio->getneext() == nullptr) {
		CNodoo <T> * nuevo = new CNodoo <T>(elem);
		inicio->setneext(nuevo);
		fin = nuevo;
	}
	else
	{
		CNodoo<T>*nuevo = new CNodoo<T>(elem);
		fin->setneext(nuevo);
		fin = nuevo;

	}

}
template <typename T> void CListaEnlazadaPunteroFinal<T>::InsertarEnPosicion(T elem, int posicion) {

	CNodoo <T>* nuevo = new CNodoo <T>(elem);

	if (posicion == 0)
	{
		InsertarInicio(elem);
	}
	else
	{
		int contador = 1;
		CNodoo <T>* rec = inicio->getneext();
		CNodoo <T>* anterior=inicio;
		
		while (contador < posicion)
		{
			rec = rec->getneext();
			anterior = anterior->getneext();
			contador++;
		}
		nuevo->setneext(rec);
		anterior->setneext(nuevo);
		
	}
}

template <typename T> 
void CListaEnlazadaPunteroFinal<T>::EliminarenPosicion(int posicion) {

	if (posicion== 0)
		inicio = inicio->getneext();
	else
	{
		int contador = 1;
		CNodoo<T>* rec = inicio->getneext();
		CNodoo<T>* anterior = inicio;
		while (contador != posicion && contador <= posicion)
		{
			rec = rec->getneext();
			anterior = anterior->getneext();
			contador++;
		}
		anterior->setneext(rec->getneext());
	}

}






template <typename T>
int CListaEnlazadaPunteroFinal<T>::ObtenerCantidadElementos()
{
	int contador = 0;
	CNodoo<T>* aux = inicio;
	while (aux != nullptr)
	{
		contador++;
		aux = aux->getneext();
	}
	return contador;
}

template <typename T>
void CListaEnlazadaPunteroFinal<T>::MostrarDatos()
{
	CNodoo<T>* aux = inicio;
	while (aux != nullptr)
	{
		cout << "Dato: " << aux->getelem() << endl;
		aux = aux->getneext();
	}
}

template <typename T>
void CListaEnlazadaPunteroFinal<T>::Dibujar(Graphics^ gr)
{
	if (inicio != nullptr)
	{
		int x = 100, y = (gr->VisibleClipBounds.Height / 1.2) - 25, largo = 100, alto = 50, nronodo = 0;
		CNodoo<T>* aux = inicio;

		while (aux != nullptr)
		{
			aux->dibujar(gr, x, y, largo, alto, nronodo);
			x += largo + 20;
			nronodo++;
			aux = aux->getneext();
		}
		gr->DrawString("NULL", gcnew Font("Arial", 11), gcnew SolidBrush(Color::Red), x - 48, y + 19);
		gr->DrawLine(gcnew Pen(Color::Cyan), Point(x, y + 25), Point(x + 50, y + 25));
		gr->DrawString(" Puntero ", gcnew Font("Arial", 12), gcnew SolidBrush(Color::Yellow), x + 10, y + 32);
	}
}

#endif