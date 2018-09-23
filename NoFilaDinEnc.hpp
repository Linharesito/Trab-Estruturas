#ifndef NO_FILA_DIN
#define NO_FILA_DIN

template <typename T>
class No;
#include "FilaDinEncadeada.hpp"

template<typename T>
class NoFDE{
private:
	No<T> *prox;
	T valor;
public:
	T getValor() const{
		return valor;
	}
	
	
	friend class FilaDinEnc<T>;
};

#endif
