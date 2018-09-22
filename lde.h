#ifndef LDE_H
#define LDE_H


#include "no.h"
#include <iostream>
using namespace  std;

template<typename T>
class LDE;

template<typename T>
ostream& operator << (ostream& out, const LDE<T>& l){
    No<T>* atual = l.primeiro;
    while(atual){
        cout << atual->valor << " ";
        atual = atual->proximo;
    }

    out << endl;
    return out;
}


template <typename T>
class LDE{
private:
    No<T>* primeiro;
    int total;
public:
    LDE(): primeiro(NULL), total(0){

    }

    bool insere(T valor){
        No<T>* ptrAtual=primeiro, *ptrAnterior = NULL;
        No<T>* novo = new No<T>;
        if(novo==NULL)
            return false;
        novo->proximo = NULL;
        novo->valor = valor;

        while(ptrAtual && ptrAtual->valor < valor){
            ptrAnterior = ptrAtual;
            ptrAtual = ptrAtual->proximo;
        }

        novo->proximo = ptrAtual;
        if(ptrAnterior){
            ptrAnterior->proximo = novo;
        }else{
            primeiro=novo;
        }
         total++;
         return true;
    }

bool remove(int idx){
        No<T>* ptrAtual=primeiro, *ptrAnterior=NULL;
        int i;
        for(i=0;i<idx && ptrAtual!=NULL;i++){
            ptrAnterior = ptrAtual;
            ptrAtual = ptrAtual->proximo;
        }
        if(ptrAtual==NULL)
            return false;

        if(ptrAnterior)
            ptrAnterior->proximo = ptrAtual->proximo;
        else
            primeiro = ptrAtual->proximo;
            
    
        delete ptrAtual;
        return true;
		}

    const No<T>* busca(T valor){
        No<T>* atual = primeiro;
        while(atual && atual->valor <= valor){
            if(atual->valor == valor)
                return atual;
            atual=atual->proximo;
        }
        return NULL;
    }


    const No<T>* getPrimeiro() const{
        return primeiro;
    }



    virtual ~LDE(){
        No<T>* atual = primeiro, *prox = NULL;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

    LDE<T> operator+(const LDE<T>& other){
        LDE<T> temp;
        No<T>* ptrAtual = primeiro;
        while(ptrAtual){
            temp.insere(ptrAtual->valor);
            ptrAtual=ptrAtual->proximo;
        }
        ptrAtual = other.primeiro;
        while(ptrAtual){
            temp.insere(ptrAtual->valor);
            ptrAtual=ptrAtual->proximo;
        }
        return temp;
    }

    LDE<T>& operator=(const LDE<T>& other){
        No<T>* atual = other.primeiro;
        No<T>* anterior = NULL;
        while(atual){
            No<T>* novo = new No<T>;
            novo->proximo = NULL;
            novo->valor = atual->valor;
            if(anterior==NULL){
                primeiro = novo;
            }else{
                anterior->proximo = novo;
            }
            anterior = novo;
            total++;
            atual = atual->proximo;
        }
        return *this;
    }

    friend ostream& operator << <> (ostream& out, const LDE<T>& t);
};




#endif // LDE_H
