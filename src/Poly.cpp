#include "Poly.h"
#include <iostream>
#include <cmath>
/*
// construtor por cópia
Poly::Poly(const Poly &P){
    this->D = P.D;
    this->a = new double[this->D];

    for(int i =0; i<P.getGrau(); i++){
        //tá errado tem que usar P.getValor
        //this->a[i] = P.a[i]
    }

}
// destrutor
Poly::~Poly(){
    if(this->a != nullptr){
        delete[] this->a;
        this->a = nullptr;
        this->D = 0;
    }
}
// operador de atribuicao
void Poly::operator=(const Poly &P){

}
// construtor especifico
Poly::Poly(const unsigned &G){
    this->D = G + 1;
    this->a = new double[this->D];

    for (unsigned i =0; i<this->D;i++) {
        if(i == this->D || i!=0){
            this->a[i] = 1.0;
        }else {
            this->a[i] = 0.0;
        }
    }
}
*/


// metodos privados
void Poly::create(const unsigned &G){
    this->D = G + 1;
    this->a = new double[this->D];

    for (unsigned i =0; i<this->D;i++) {
        if(i == this->D || i!=0){
            this->a[i] = 1.0;
        }else {
            this->a[i] = 0.0;
        }
    }
}
void Poly::clean(){
    if(this->a != nullptr){
        delete[] this->a;
        this->a = nullptr;
        this->D = 0;
    }
}

void Poly::copy(const Poly &P){
    this->D = P.getGrau() + 1;
    if(this->a == nullptr){
        this->a = new double[this->D];
    }else{
        delete[] this->a;
        this->a = new double[this->D];
    }
    /*
    this->a != nullptr ? delete[] this->a : void ;
    this->a = new double[this->D];
    */
    for(int i =0; i<P.getGrau(); i++){
        this->a[i] = P.getCoef(i);
    }
}

void Poly::recriar(const unsigned &G){
    this->clean();
    this->create(G);
}

// construtor por cópia
Poly::Poly(const Poly &P){
    this->clean();
    this->copy(P);
}

// operador de atribuicao
void Poly::operator=(const Poly &P){
    if(this != &P){
        this->clean();
        this->copy(P);
    }
}

// metodos de consulta
bool Poly::isZero() const{
    if(this->a == nullptr)  return false;
    return (this->getGrau() == 0 ? true: false);
}

double Poly::getCoef(const unsigned &I) const{
    if(this->a == nullptr)  return 0.0;
    return (this->getGrau()>=0 ? this->a[I]: 0.0);
}

double Poly::getValor(const double &V) const{
    double valor = 0.0;
    if(this->empty())   valor = 0.0;
    else {
        for (int i = 0;i<=this->getGrau();i++)
            valor +=(this->getCoef(unsigned(i)) * pow(V,i));
    }
    return valor;
}

// metodo de alteracao
void Poly::setCoef(const unsigned &I, const double &V){
    if(int(I) > this->getGrau() || this->getGrau() == -1){
        std::cerr << "erro! grau nao existente ou polinomio vazio";
    }else if ( (int(I) == this->getGrau()) && (this->getGrau() != 0)) {
        this->a[I] = 1.0;
    }else {
        this->a[I] = V;
    }
}

// entrada e saida
std::ostream &operator<<(std::ostream &O, const Poly &P){
    for(int i= P.getGrau(); i>=0;i--){
        if(P[i] == 0.0){
            if(i==0 && P.getGrau() ==0){
                O << P[i];
            }
        }else{
            if(P[i] < 0.0){
                O << '-';
            }else{
                if(i != P.getGrau()){
                    O << '+';
                } // fim se
            } // fim se
            if(fabs(P[i]) !=1.0 || i==0){
                O << fabs(P[i]);
            }
            if(i!=0){
                if(fabs(P[i])!=1.0){
                    O << '*';
                }
                O << 'x';
                if(i>1){
                    O << '^';
                    O << i;
                }// fim se
            } // fim se
        } // fim se
    } // fim para

    return O;
}

//X >> P.a[i];
std::istream &operator>>(std::istream &I, Poly &P){
    double V = 0.0;
    if(P.empty()){
        std::cerr <<"Erro polinomio vazio";
    }else {
        for( int i =P.getGrau(); i>=0; i--){
            std::cout << "X^" << i << ": ";
            I >> V;
            while(V ==0 && P.getGrau() == i && !P.isZero()){
                std::cout << "X^" << i << ": ";
                I >> V;
            }
            P.setCoef(i, V);
        }
    }
    return I;
}
