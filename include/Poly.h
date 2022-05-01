#ifndef POLY_H
#define POLY_H
#include <iostream>

class Poly
{
private:
	unsigned D;
	double *a;

	void create(const unsigned &G);
	void clean();
	void copy(const Poly &P);
	void recriar(const unsigned &G);
public:
//os construtores, destrutores e operadores obrigat�rios:
 	// construtor default
    inline Poly(): D(0), a(nullptr){}
  	// construtor por c�pia
  	Poly(const Poly &P);
 	 // destrutor
  	inline ~Poly(){this->clean();}
 	 // operador de atribui��o
  	void operator=(const Poly &P);
	// construtor espec�fico que receba como par�metro GRAU
	inline explicit Poly(const unsigned &G){this->create(G);}

// fun��es de consulta:
    bool isZero() const;
    inline bool empty() const{ return (this->D == 0? true: false);}
    inline int getGrau() const {return int(this->D)-1;}
    // verificar se nao dara erro
    double getCoef(const unsigned &I) const;
    double getValor(const double &V) const;
    inline double operator[](const unsigned &I) const{ return this->getCoef(I);}
    inline double operator()(const unsigned &I) const {return this->getValor(I);}


// fun��es de altera��o:
    // set, para alterar o valor de um elemento
    void setCoef(const unsigned &I,const double &V);

// m�todos de entrada e sa�da (<< e >>)
    friend std::ostream &operator<<(std::ostream &O, const Poly &P);
    friend std::istream &operator>>(std::istream &I, Poly &P);

// as opera��es alg�bricas b�sicas:
    // soma e subtracao e multiplicacao
    Poly operator+(const Poly &P) const;
    Poly operator-(const Poly &P) const;
    Poly operator*(const Poly &P) const;
    // negativo de um vetor
    Poly operator-() const;

};

#endif
