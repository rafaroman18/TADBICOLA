#ifndef EJ1TADCOLA_TADCOLADINAM22ICO_H
#define EJ1TADCOLA_TADCOLADINAMICO_H
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class Cola
{
public:
    Cola();

    Cola(const Cola<T> &C);

    Cola<T> &operator=(const Cola<T> &C);

    bool vacia() const;

    const T &frente() const;

    void pop();

    void push(const T &x);

    ~Cola();

private:

    struct nodo {
        T elto;
        nodo* sig;
        explicit nodo(const T &e, nodo* p = 0) : elto(e), sig(p) {}
    };
    nodo *inicio, *fin;
    void copiar(const Cola<T>& C);
};

template <typename T>
void Cola<T>::copiar(const Cola<T>& C)
{
   if(C.inicio)
   {
       inicio=fin=new nodo(C.inicio->elto);
       for(nodo*p = C.inicio->sig;p;p=p->sig)
       {
           fin->sig=new nodo(p->elto);
           fin=fin->sig;
       }
   }
}

template <typename T>
inline Cola<T>::Cola():inicio(0),fin(0){}


template <typename T>
inline Cola<T>::Cola(const Cola<T>& C): inicio(0),fin(0)
{
    copiar(C);
}

template <typename T>
inline Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
    if(this!= &C)
    {
        this->~Cola();
        copiar(C);
    }
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (inicio==0);
}

template <typename T>
inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo*p=inicio;
    inicio=p->sig;
    if(!inicio) fin =0;
    delete p;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    nodo *p = new nodo(x);
    if(inicio==0)
        inicio=fin=p;
    else
        fin=fin->sig=p;
}

template <typename T>
inline Cola<T>::~Cola()
{
    nodo*p;
    while(inicio)
    {
    p=inicio->sig;delete inicio;inicio=p;
    }
    fin=0;
}
#endif //EJ1TADCOLA_TADCOLADINAMICO_H
