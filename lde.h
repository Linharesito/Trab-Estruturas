#ifndef LDE_H
#define LDE_H
 #include "no.h"
#include <iostream>
using namespace  std;
 template<typename T>
class LDE;
 template<typename T>
class LDE{
private:
    No<T>* primeiro;
    int total;
public:
    LDE(): primeiro(NULL), total(0){
     }
     bool insere(T nome, T cpf, T duracao, T checkin, T checkout, T quarto){
        No<T>* ptrAtual=primeiro, *ptrAnterior = NULL;
        No<T>* novo = new No<T>;
        if(novo==NULL)
            return false;
        novo->proximo = NULL;
        novo->nome = nome;
        novo->cpf = cpf;
        novo->duracao = duracao;
        novo->checkin = checkin;
        novo->checkout = checkout;
	novo->quarto = quarto;
        
         while(ptrAtual && ptrAtual->nome < nome){
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
  
     const No<T>* busca(T quarto){
        No<T>* atual = primeiro;
        while(atual && atual->quarto <= quarto){
            if(atual->quarto == quarto)
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
};

#endif // LDE_H
