//
//  main.cpp
//  exp_rápida
//
//  Created by jonas on 25/04/13.
//  Copyright (c) 2013 jonas. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> binario;

void decimal2binario(int dec){
    if (dec!=0)
    {
        decimal2binario(dec/2);
        binario.push_back(dec%2);
    }
}
int expRap(int n, int exp, int mod){
    decimal2binario(exp);
    for (int i = 0; i < binario.size(); i++) {
        cout << binario[i];
    }
    cout << endl;
    int x = 1;
    int resultado = 0;
    for (int i = 0; i < binario.size(); i++) {
        if (binario[i] == 1) {
            resultado = ((x*x)*n)%mod;
            cout << "i= " << i << ", b" << i << "= " << binario[i] << " x= " << x << "^" << n << "mod" << mod << " = " << resultado << endl;
        } else if (binario[i] == 0) {
            resultado = (x*x)%mod;
            cout << "i= " << i << ", b" << i << "= " << binario[i] << " x= " << x << "^" << n << "mod" << mod << " = " << resultado << endl;
        }
        x = resultado;
    }
    return resultado;
}


int main()
{
    int exp, n, mod;
    cout << "Exponenciación rápida: " << endl;
    cout << "Número: "; cin >> n;
    cout << "Elevado a: "; cin >> exp;
    cout << "Módulo: "; cin >> mod;
    cout << "Resultado: " << endl << expRap(n, exp, mod) << endl;
    return 0;
}

