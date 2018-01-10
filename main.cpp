#include <iostream>
#include "tadbicola.h"
int main()
{
    using namespace std;
    Bicola<int> B;int i;
    for(i=1;i<5;i++)
    {
    B.pushA(i);
    }
    for(i=5;i<9;i++)
    {
        B.pushB(i);
    }
    while(!B.vacia())
    {
        cout<<B.frenteB()<<endl;
        B.popB();
    }
    return 0;
}