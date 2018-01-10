#include <iostream>
#include "tadbicola.h"
int main()
{
    using namespace std;
    Bicola<int> B;int i;
    for(i=1;i<5;i++)
    {
    B.pushB(i);
    }
    while(!B.vacia())
    {
        cout<<B.frenteA()<<endl;
        B.popA();
    }
    cout<<"Hola";
    return 0;
}