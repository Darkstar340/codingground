#pragma once
#ifndef _CONTROLADORDOBLE_H_
#define _CONTROLADORDOBLE_H_
#include "CListaDobleEnlazada.h"

template<typename T>

class CListaDobleEnlazada
{
	CNodoDE<T>* Inicio; //Inicio puntero.
	CNodoDE<T>* Final; //Final puntero.
public:
	CListaDobleEnlazada();
	~CListaDobleEnlazada();

	void InsertarInicio(T elem);	
	void InsertarFinal(T elem);
	bool InsertarEnPosicion(T elem, int pos); //Tipo Bool para Insertar un Elemento (elem).

	void EliminarPosicion(int pos);

	int ObtenerCPreidadElementos();

	void Mostrarelems();
	void Dibujar(Graphics^gr);


};

template <typename T>
CListaDobleEnlazada<T>::CListaDobleEnlazada() { Inicio = nullptr; Final = nullptr; } //Comienza en vacio.

template <typename T>
CListaDobleEnlazada<T>::~CListaDobleEnlazada() 
{
	delete Inicio; delete Final; //Destructor de Punteros.
}

template <typename T>
void CListaDobleEnlazada<T>::InsertarInicio(T elem)
{
	CNodoDE<T>* Term = new CNodoDE<T>();
	Term->Setelem(elem); //Term = n, nuevo termino.
	if (Inicio == nullptr) //Sí Puntero inicio = vacio.
	{
		Term->SetNext(nullptr);  // Termino = apunta a vacio.
		Term->SetPre(nullptr); // Termino = apunta hacia atras a vacio.
		Inicio = Term; // Puntero Inicio apunta a Termino nuevo.
		Final = Term; // Puntero Final apunta a Termino nuevo.
	}
	else //Sino
	{
		Term->SetNext(Inicio); 
		Inicio->SetPre(Term);
		Inicio = Term;
	}
}

template <typename T>
void CListaDobleEnlazada<T>::InsertarFinal(T elem)
{
	CNodoDE<T>* Term = new CNodoDE<T>();
	CNodoDE<T>* aux = nullptr;
	Term->Setelem(elem);
	Term->SetNext(nullptr);
	Final = Term;

	if (Inicio == nullptr)
	{
		Term->SetPre(nullptr);
		Inicio = Term;
	}
	else
	{
		aux = Inicio;
		while (aux->GetNext() != nullptr)
		{
			aux = aux->GetNext();
		}
		aux->SetNext(Term);
		Term->SetPre(aux);
	}	
}

template <typename T>
bool CListaDobleEnlazada<T>::InsertarEnPosicion(T elem, int pos)
{
	CNodoDE<T>* aux = nullptr;
	CNodoDE <T>* Term = new CNodoDE<T>();

	Term->Setelem(elem);

	if (pos == 0)
	{
		InsertarInicio(elem);		
	}
	else
	{
		aux = Inicio;

		for (int i = 1; aux != nullptr; i++)
		{
			if (i == pos)
			{
				Term->SetNext(aux->GetNext());
				Term->SetPre(aux);
				aux->SetNext(Term);
				if (aux->GetNext() == nullptr) Final = aux; return true;
			}
			aux = aux->GetNext();
		}
	}return false;
}

template<typename T>
void CListaDobleEnlazada<T>::EliminarPosicion(int pos)
{
	CNodoDE<T> * anterior = nullptr;
	CNodoDE<T> * aux = Inicio;
	if (Inicio != nullptr)
	{
		
		while (aux != nullptr)
		{
			if (aux != nullptr)
			{
				if (aux == Inicio)
				{
					Inicio = Inicio->GetNext();
					Inicio -> SetPre(nullptr);
				}
				else
				{
					anterior->SetNext(aux->GetNext());
					if (aux->GetNext() != nullptr)
						aux->GetNext()->SetPre(anterior);
					if (anterior->GetNext() == nullptr)
						Final = anterior;
					
				}
				delete (aux);
				return;

			}
			anterior = aux;
			aux = aux->GetNext();
			
		}
	}
}

template <typename T>
int CListaDobleEnlazada<T>::ObtenerCPreidadElementos()
{
	int contador = 0;
	CNodoDE<T>* aux = Inicio;
	while (aux != nullptr)
	{
		contador++;
		aux = aux->GetNext();
	}
	return contador;
}

template <typename T>
void CListaDobleEnlazada<T>::Mostrarelems() //Mostrar elem en Interfaz
{
	CNodoDE<T>* aux = Inicio; 
	while (aux != nullptr)
	{
		cout << "elem: " << aux->Getelem() << endl;
		aux = aux->GetNext();
	}
}

template <typename T>
void CListaDobleEnlazada<T>::Dibujar(Graphics^ gr) //Dibujor en Interfaz
{
	if (Inicio != nullptr)
	{
		int x = 100, y = (gr->VisibleClipBounds.Height / 2) - 25, largo = 100, alto = 50, nronodo = 0;
		CNodoDE<T>* aux = Inicio;

		while (aux != nullptr)
		{
			aux->dibujar(gr, x, y, largo, alto, nronodo);
			x += largo + 20;
			nronodo++;
			aux = aux->GetNext();
		}
		gr->DrawString(" NULL", gcnew Font("Arial", 12), gcnew SolidBrush(Color::Red), x - 50, y + 19); //para vacio
		gr->DrawLine(gcnew Pen(Color::Cyan), Point(x, y + 25), Point(x + 50, y + 25));
		gr->DrawString(" Puntero ", gcnew Font("Arial", 12), gcnew SolidBrush(Color::Yellow), x + 10, y + 32); //puntero doble
	}
}
#endif // !_CONTROLADORDOBLE_H_
