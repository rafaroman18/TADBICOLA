#ifndef EJ1TADCOLA_TADBICOLA_H
#define EJ1TADCOLA_TADBICOLA_H
#include <iostream>
#include <cassert>
#include "tadcoladinamico.h"
using namespace std;
template <typename T> class Bicola
{
public:
    Bicola();
    Bicola(const Bicola<T>& B);
    Bicola<T>& operator=(const Bicola<T>& B);
    void pushA(const T& x);
    void pushB(const T& x);
    void popA();
    void popB();
    bool vacia() const;
    const T &frenteA() const;
    const T &frenteB() const;
    ~Bicola();

private:
    struct nodo
    {
       T elto;
       nodo* sig;
        explicit nodo(const T &e,nodo* p=0):elto(e),sig(p){}
    };
    nodo *inicio, *fin;
    void copiar(const Bicola<T>& B);
};

template <typename T>
Bicola<T>::Bicola():inicio(0),fin(0){};

template <typename T>
Bicola<T>::Bicola(const Bicola<T>& B):inicio(0),fin(0)
{
    copiar(B);
}

template <typename T>
inline Bicola<T>& Bicola<T>::operator=(const Bicola<T>& B)
{
    if(this!=&B)
    {
        this->~Bicola();
        copiar(B);
    }
    return *this;
}

template <typename T>
inline void Bicola<T>::pushA(const T &x)
{
    nodo *p=new nodo(x);
    if(inicio==0)
        inicio=fin=p;
    else
        p->sig=inicio;
        inicio=p;
}

template <typename T>
void Bicola<T>::pushB(const T &x)
{
    nodo *p=new nodo(x);
    if(inicio==0)
        inicio=fin=p;
    else
        fin=fin->sig=p;
}

template <typename T>
void Bicola<T>::popA()
{
    assert(!vacia());               //FALTAN COMPROBACIONES DE SI ESTA VACIA
    nodo*p=inicio;
    inicio=p->sig;
    if(!inicio) fin =0;
    delete p;
}

template <typename T>
void Bicola<T>::popB()
{
    assert(!vacia());
    nodo *p = inicio;               //COMPROBACIONES DE SI ESTA VACIA
    while (p->sig != fin)          // ...||p!=fin)
    {
        p = p->sig;
    }
    fin =p;
    fin->sig=p->sig;
    delete p->sig;
}

template <typename T>
bool Bicola<T>::vacia()const
{
    return (inicio==0);
}

template <typename T>
inline const T& Bicola<T>::frenteA() const
{
    return inicio->elto;
}

template <typename T>
inline const T& Bicola<T>::frenteB() const
{
    return fin->elto;
}

template <typename T>
void Bicola<T>::copiar(const Bicola<T>& B)
{
    if(inicio)
    {
        inicio=fin=new nodo(inicio->elto);
        for(nodo*p = inicio->sig;p;p=p->sig)
        {
            fin->sig=new nodo(p->elto);
            fin=fin->sig;
        }
    }
}

template <typename T>
inline Bicola<T>::~Bicola()
{
    nodo *p;
    while(inicio)
    {
        p=inicio->sig;delete inicio;inicio=p;
    }
    fin=0;
}
#endif //EJ1TADCOLA_TADBICOLA_H
