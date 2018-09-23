#ifndef FILA_DIN_ENC
#define FILA_DIN_ENC

#include <cstdlib>

template <typename T>
class FilaDinEnc;
#include "NoFilaDinEnc.hpp"

template<typename T>
class FilaDinEnc{

	private:
		NoFDE<T> *primeiro;
		NoFDE<T> *ultimo;
		int total;
	public:
		FilaDinEnc():
			primeiro(NULL),
			ultimo(NULL),
			total(0){	}
			
		bool enfileira(T valor){
			NoFDE<T>* novo = new NoFDE<T>;
			if (!novo)
			    return false;

			novo->valor = valor;
			novo->prox = NULL;
			
			if(!primeiro)
				primeiro=novo;
			else
				ultimo->prox = novo;

			ultimo = novo;
			total++;
			    
   			return true;
		}

		bool desenfileira(T& saida){
		    if(!primeiro)
		        return false;
		        
			saida = primeiro->valor;
			NoFDE<T>* temp = primeiro->prox;
			delete primeiro;
			primeiro = temp;
			total--;
			
			if(!primeiro)
			    ultimo=NULL;
			
			return true;
		}
		
		~FilaDinEnc(){
			T temp;
			while(desenfileira(temp));
		}


};


#endif
