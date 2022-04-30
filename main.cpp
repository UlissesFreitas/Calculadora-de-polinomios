#include <iostream>
#include "Poly.h"

using namespace std;
/*
    ERRO AO IMPRIMIR
    NÃO EXIBE O NUMERO DE MAIOR GRAU
*/
int main(int argc, char** argv) {

	Poly P, P1(0), P2(3);
    cin >> P2;
    //cin >> P1;
    //cout << P << endl;
    //cout << P1 << endl;
    cout << P2 << endl;
    cout << "===================" << endl;
    cout << "P NULO default" << endl;
	cout << "Pgrau: "  <<P.getGrau() << endl;
	cout << "Pempty: "  <<P.empty()<< endl;
    cout << "PisZero: "  <<P.isZero()<< endl;
    cout << "PgetCoef: " << P.getCoef(0) << endl;
    cout << endl;
    cout << "P1 VAZIO especifico" << endl;
	cout << "P1grau: " <<P1.getGrau() << endl;
	cout << "P1empty: " <<P1.empty()<< endl;
    cout << "P1isZero: " <<P1.isZero()<< endl;
    cout << "P1getCoef: " << P1.getCoef(0) << endl;
    cout << endl;
    cout << "P2 G2 p copia" << endl;
	cout << "P2grau: " <<P2.getGrau() << endl;
	cout << "P2empty: " <<P2.empty()<< endl;
    cout << "P2isZero: " <<P2.isZero()<< endl;
    cout << "P2getCoef: " << P2.getCoef(0) << endl;
    cout << "P2getCoef: " << P2.getCoef(1) << endl;
    cout << "P2[]: " << P2[2] << endl;
    cout << "P2(): " << P2(2) << endl;
    P2.setCoef(0, 9);
    cout << "P2novoCOEF: " << P2.getCoef(0) << endl;

	return 0;
}
