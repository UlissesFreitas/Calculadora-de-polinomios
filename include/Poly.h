#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <cmath>
// aula de arquivos
#include <fstream>
#include <string>
//acho quenao usei isso
#include <limits>
#include <stdlib.h>


class Poly
{
private:
	unsigned D;
	double *a;

    void reduzir();
public:
//os construtores, destrutores e operadores obrigat�rios:
 	// construtor default
    inline Poly(): D(0), a(nullptr){}
  	// construtor por c�pia
  	Poly(const Poly &P);
 	 // destrutor
    ~Poly();
 	 // operador de atribui��o
  	void operator=(const Poly &P);
	// construtor espec�fico que receba como par�metro GRAU
    explicit Poly(const unsigned &G);

    void recriar(const unsigned &G);
// fun��es de consulta:
    bool isZero() const;
    inline bool empty() const{ return (this->getGrau() == -1? true: false);}
    inline int getGrau() const {return int(this->D)-1;}
    // verificar se nao dara erro
    double getCoef(const unsigned &I) const;
    double getValor(const double &V) const;
    inline double operator[](const unsigned &I) const{ return this->getCoef(I);}
    inline double operator()(const double &I) const {return this->getValor(I);}

// fun��es de altera��o:
    // set, para alterar o valor de um elemento
    void setCoef(const unsigned &I,const double &V);

// m�todos de entrada e sa�da (<< e >>)
    friend std::ostream &operator<<(std::ostream &O, const Poly &P);
    friend std::istream &operator>>(std::istream &I, Poly &P);

// leitura e escrita de arquivos
    bool ler(std::string nome_arq);
    bool salvar(std::string nome_arq);

// as opera��es b�sicas:
    // soma e subtracao e multiplicacao
    Poly operator+(const Poly &P) const;
    Poly operator-(const Poly &P) const;
    Poly operator*(const Poly &P) const;
    // negativo de um vetor
    Poly operator-() const;


};

#endif
