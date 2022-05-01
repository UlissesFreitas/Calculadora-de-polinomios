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
//os construtores, destrutores e operadores obrigatórios:
 	// construtor default
    inline Poly(): D(0), a(nullptr){}
  	// construtor por cópia
  	Poly(const Poly &P);
 	 // destrutor
  	inline ~Poly(){this->clean();}
 	 // operador de atribuição
  	void operator=(const Poly &P);
	// construtor específico que receba como parâmetro GRAU
	inline explicit Poly(const unsigned &G){this->create(G);}

// funções de consulta:
    bool isZero() const;
    inline bool empty() const{ return (this->D == 0? true: false);}
    inline int getGrau() const {return int(this->D)-1;}
    // verificar se nao dara erro
    double getCoef(const unsigned &I) const;
    double getValor(const double &V) const;
    inline double operator[](const unsigned &I) const{ return this->getCoef(I);}
    inline double operator()(const unsigned &I) const {return this->getValor(I);}


// funções de alteração:
    // set, para alterar o valor de um elemento
    void setCoef(const unsigned &I,const double &V);

// métodos de entrada e saída (<< e >>)
    friend std::ostream &operator<<(std::ostream &O, const Poly &P);
    friend std::istream &operator>>(std::istream &I, Poly &P);

// as operações algébricas básicas:
    // soma e subtracao e multiplicacao
    Poly operator+(const Poly &P) const;
    Poly operator-(const Poly &P) const;
    Poly operator*(const Poly &P) const;
    // negativo de um vetor
    Poly operator-() const;

};

#endif
