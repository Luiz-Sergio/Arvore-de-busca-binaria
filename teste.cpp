#include <bits/stdc++.h>
using namespace std;

 int calcQtdDigitos(int numero){
        if ((numero / 10) == 0){ 
            return 1;
        }
        else{
            // efetua mais uma chamada recursiva
            return 1 + calcQtdDigitos(numero / 10);
        }
    }

int main (){
    cout<<calcQtdDigitos(155)<<endl;

    return 0;
}