#ifndef NO_H
#define NO_H
 #include "lde.h"
#include <iostream>
template<typename T>
class LDE;
 template<typename T>
std::ostream& operator <<  (std::ostream&, const LDE<T>&);
 template<typename T>
class No{
public:
    No<T>* proximo;
    T nome;
    T cpf;
    T duracao;
    T checkin;
    T checkout;
    T quarto;

    const No<T>* getProx() const{
        return proximo;
    }
     friend class LDE<T>;
};
 #endif // NO_H
