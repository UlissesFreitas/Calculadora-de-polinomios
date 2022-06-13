#include "Poly.h"

// funcoes auxlicares
void Poly::recriar(const unsigned &G){
    //clean
    if(this->a != nullptr){
        delete[] this->a;
        this->a = nullptr;
    }
    //create
    this->D = G+1;
    this->a = new double[this->D];

    for(unsigned i=0; i<= G;i++){
        if(G == i && G !=0){
            this->a[i] = 1.0;
        }else {
            this->a[i] = 0.0;
        }
    }
}

void Poly::reduzir(){
    while( (this->getCoef(this->getGrau()) ==0.0) && (this->getGrau() >0)){
        Poly prov(this->getGrau() -1);
        for(int i=0;i<=prov.getGrau();i++){
            prov.a[i] = this->getCoef(i);
        }
        *this = prov;
    }
}
// construtor por c�pia
Poly::Poly(const Poly &P){
    this->D = P.getGrau() + 1;
    this->a = new double[this->D];

    for(int i =0; i<=P.getGrau(); i++){
        this->a[i] = P.getCoef(i);
    }
}
// construtor especifico
Poly::Poly(const unsigned &G){
    this->D = G+1;
    this->a = new double[this->D];

    for(unsigned i=0; i<=G;i++){
        if(G == i && G !=0){
            this->a[i] = 1.0;
        }else {
            this->a[i] = 0.0;
        }
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
    // evita a=a
    if(this != &P){
        //clean
        if(this->a != nullptr){
            delete[] this->a;
            this->a = nullptr;
        }
        //copy
        this->D = P.getGrau() + 1;
        this->a = new double[this->D];
        for(int i =0; i<=P.getGrau(); i++){
            this->a[i] = P.getCoef(i);
        }
    }
}

// metodos de consulta
bool Poly::isZero() const{
    if(this->a == nullptr)  return false;
    return ((this->getGrau() == 0 && this->getCoef(0) == 0.0) ? true: false);
}

double Poly::getCoef(const unsigned &I) const{
    if(this->empty())  return 0.0;
    return (I > unsigned(this->getGrau() ) ? 0.0: this->a[I]);
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
        std::cerr << "erro! grau nao existente ou polinomio vazio" << std::endl;
    }else if ( (int(I) == this->getGrau()) && (V == 0)) {
        std::cerr << "errro esse numero nao pode ser 0.0";
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
                }
            }
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
                }
            }
        }
    }
    return O;
}

std::istream &operator>>(std::istream &I, Poly &P){
    double V = 0.0;
    if(P.empty()){
        std::cerr <<"Erro polinomio vazio" << std::endl;
    }else {
        for( int i =P.getGrau(); i>=0; i--){
            std::cout << "X^" << i << ": ";
            I >> V;
            while(V ==0 && P.getGrau() == i && !P.isZero()){
                std::cout << "X^" << i << ": ";
                I >> V;
            }
            P.a[i] = V;
        }
    }
    return I;
}
// leitura e escrita de arquivos
bool Poly::ler(std::string nome_arq){
    int D;
    std::ifstream arq(nome_arq.c_str());
    if(!arq.is_open()) return false;

    std::string cabecalho;
    arq >> cabecalho;
    if(!arq.good() || cabecalho !="POLY"){
        arq.close();
        return false;
    }

    arq >> D;
    // sera que precisa disso
    if(!arq.good() || D ==0){
        arq.close();
        return false;
    }
    Poly prov(D-1);

    for(int i=0;i<=prov.getGrau();i++){
        if(!arq.good()){
            arq.close();
            return false;
        }
        arq >> prov.a[i];
    }

    *this = prov;

    arq.close();
    return true;
}

bool Poly::salvar(std::string nome_arq){
    std::ofstream arq(nome_arq.c_str());
    if(!arq.is_open()) return false;

    arq << "POLY " << this->getGrau() +1 << std::endl;
    if(!this->empty()){
        for(int i=0;i<=this->getGrau();i++){
            arq << this->getCoef(i) << " ";
        }
    }

    arq.close();
    return true;
}

Poly Poly::operator+(const Poly &P) const{

    if(P.empty() || P.isZero()) return *this;
    if(this->empty() || this->isZero()) return P;

    Poly prov(std::max(this->getGrau(), P.getGrau()));
    for(int i=0;i<=prov.getGrau(); i++){
        prov.a[i] = this->getCoef(i) + P.getCoef(i);
    }

    prov.reduzir();

    return prov;
}

Poly Poly::operator-(const Poly &P) const{
    if(P.empty() || P.isZero()) return *this;
    if(this->empty() || this->isZero()) return -P;

    Poly prov(std::max(this->getGrau(), P.getGrau()));
    for(int i=0;i<=prov.getGrau(); i++){
        prov.a[i] = this->getCoef(i) - P.getCoef(i);

    }
    prov.reduzir();

    return prov;
}

Poly Poly::operator*(const Poly &P) const{
    if(P.empty()) return P;
    if(this->empty()) return *this;
    if(P.isZero() && !this->empty()) return P;
    if(this->isZero() && !P.empty()) return *this;

    Poly prov( this->getGrau() + P.getGrau() );
    for(int k=0;k<=prov.getGrau();k++){
        prov.a[k] = 0.0;
    }

    for(int i=0; i<=this->getGrau() ; i++){
        for(int j=0; j<=P.getGrau(); j++){
            prov.a[i+j] = prov.a[i+j] + this->getCoef(i)*P.getCoef(j);
        }
    }
    return prov;
}

Poly Poly::operator-() const{
    if(this->empty()) return *this;
    if(this->isZero()) return *this;

    Poly prov(this->getGrau());

    for(int i=0;i<=this->getGrau();i++){
        prov.a[i] = -this->getCoef(i);
    }
    return prov;
}

