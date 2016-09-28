#pragma once
#ifndef _CONTROLADOR1_H_
#define _CONTROLADOR1_H_

#include "CListaEnlazada.h"
template <typename T>

class CListaEnlazada
{
	CNodo<T>* inicio;
public:
	CListaEnlazada();
	~CListaEnlazada();

	void InsertarInicio(T elem);
	void InsertarEnPosicion(T elem, int pos);
	void InsertaralFinal(T elem);

	void EliminarenPosicion(int pos);

	int ObtenerCantidadElementos();

	void MostrarDatos();
	void Dibujar(Graphics^ gr);
};

template <typename T>
CListaEnlazada<T>::CListaEnlazada() { inicio = nullptr; }

template <typename T>
CListaEnlazada<T>::~CListaEnlazada() {
	while (inicio != nullptr) {
		CNodo<T>* aux = inicio;
		inicio = inicio->next;
		delete aux;
	}
}

template <typename T>
void CListaEnlazada<T>::InsertarInicio(T elem)
{
	if (inicio == nullptr)
		inicio = new CNodo<T>(elem);
	else
	{
		CNodo<T>* nuevo = new CNodo<T>(elem);
		nuevo->setnext(inicio);
		inicio = nuevo;
	}
}

template <typename T>
void CListaEnlazada<T>::InsertarEnPosicion(T elem, int pos)
{
	CNodo<T>* nuevo = new CNodo<T>(elem);

	if (pos == 0) { InsertarInicio(elem); }
	else
	{
		int contador = 1;
		CNodo<T>* rec = inicio->getnext();
		CNodo<T>* anterior = inicio;

		while (contador != pos && contador <= pos)
		{
			rec = rec->getnext();
			anterior = anterior->getnext();
			contador++;
		}

		nuevo->setnext(rec);
		anterior->setnext(nuevo);
	}
}

template <typename T>
void CListaEnlazada<T>::InsertaralFinal(T elem)
{
	CNodo<T>* aux = inicio;

	if (aux == nullptr)
		inicio = new CNodo<T>(elem);
	else
	{
		while (aux->getnext() != nullptr)
			aux = aux->getnext();

		aux->setnext(new CNodo<T>(elem));
	}
}

template <typename T>
void CListaEnlazada<T>::EliminarenPosicion(int pos)
{
	if (pos == 0)
		inicio = inicio->getnext();
	else
	{
		int contador = 1;
		CNodo<T>* rec = inicio->getnext();
		CNodo<T>* anterior = inicio;
		while (contador != pos && contador <= pos)
		{
			rec = rec->getnext();
			anterior = anterior->getnext();
			contador++;
		}
		anterior->setnext(rec->getnext());
	}
}

template <typename T>
int CListaEnlazada<T>::ObtenerCantidadElementos()
{
	int contador = 0;
	CNodo<T>* aux = inicio;
	while (aux != nullptr)
	{
		contador++;
		aux = aux->getnext();
	}
	return contador;
}

template <typename T>
void CListaEnlazada<T>::MostrarDatos()
{
	CNodo<T>* aux = inicio;
	while (aux != nullptr)
	{
		cout << "Dato: " << aux->getelem() << endl;
		aux = aux->getnext();
	}
}

template <typename T>
void CListaEnlazada<T>::Dibujar(Graphics^ gr)
{
	if (inicio != nullptr)
	{
		int x = 100, y = (gr->VisibleClipBounds.Height / 5) - 25, largo = 100, alto = 50, nronodo = 0;
		CNodo<T>* aux = inicio;

		while (aux != nullptr)
		{
			aux->dibujar(gr, x, y, largo, alto, nronodo);
			x += largo + 20;
			nronodo++;
			aux = aux->getnext();
		}
		gr->DrawString("NULL", gcnew Font("Arial", 11), gcnew SolidBrush(Color::Red), x - 48, y + 19);
	}
}

#endif