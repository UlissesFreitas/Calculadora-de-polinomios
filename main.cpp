#include <iostream>
#include "Poly.h"

using namespace std;
/*
    ERRO AO IMPRIMIR
    NÃO EXIBE O NUMERO DE MAIOR GRAU
*/
int main(int argc, char** argv) {

	Poly P, P1(2), P2(3), P3(4);
    cin >> P1;
    cin >> P2;
    P3 = P1 + P2;
    cout << "P1: " << P1 << endl;
    cout << "P2: " << P2 << endl;
    cout << "P3: " << P3 << endl;

    cout << "===========" << endl;
    cout << "P3Grau: " << P3.getGrau() << endl;
    cout << "P3Coef0: " << P3.getCoef(0) << endl;
    cout << "P3Coef1: " << P3.getCoef(1) << endl;
    cout << "P3Coef2: " << P3.getCoef(2) << endl;
    cout << "P3Coef3: " << P3.getCoef(3) << endl;
    cout << "===========" << endl;
    cout << "P1Grau: " << P1.getGrau() << endl;
    cout << "P1Coef0: " << P1.getCoef(0) << endl;
    cout << "P1Coef1: " << P1.getCoef(1) << endl;
    cout << "P1Coef2: " << P1.getCoef(2) << endl;
    cout << "P1Coef3: " << P1.getCoef(3) << endl;
    cout << "===========" << endl;
    cout << "P2Grau: " << P2.getGrau() << endl;
    cout << "P2Coef0: " << P2.getCoef(0) << endl;
    cout << "P2Coef1: " << P2.getCoef(1) << endl;
    cout << "P2Coef2: " << P2.getCoef(2) << endl;
    cout << "P2Coef3: " << P2.getCoef(3) << endl;
	return 0;
}
