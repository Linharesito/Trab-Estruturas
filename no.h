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
private:
    No<T>* proximo;
    
public:
	T valor;
    T getValor() const{
        return valor;
    }
    const No<T>* getProx() const{
        return proximo;
    }

    friend class LDE<T>;

    friend std::ostream& operator << <> (std::ostream& out, const LDE<T>& t);
};

#endif // NO_H
