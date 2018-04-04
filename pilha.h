#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "no.h"

using namespace std;

class Pilha_V2{
  public:
    No* primeiro;
    No* ultimo;
    int total;

  public:
    const No* getPrimeiro() const{
      return primeiro;
    }

    const No* getUltimo() const{
      return ultimo;
    }

    int getTotal() const{
        return total;
    }

    Pilha_V2(): primeiro(NULL), ultimo(NULL), total(0){}

    bool insert_pilha(int h, int m, string d){

      No *ptrAtual = primeiro;
      No *ptrAnt = NULL;
      No *n = new No;

      if(!n)
        return false;

      n->prox = NULL;
      n->hora = h;
      n->minuto = m;
      n->desc = d;

      while(ptrAtual && (n->hora < ptrAtual->hora && n->minuto < ptrAtual->minuto)){
        ptrAnt = ptrAtual;
        ptrAtual = ptrAtual->prox;
      }

      n->prox = ptrAtual;

      if(ptrAnt){
        ptrAnt->prox = n;
      }else{
        primeiro = n;
      }

      if(ptrAtual){
        ptrAtual->ant = n;
      }else{
        ultimo = n;
      }

      total++;
      return true;
    }

    bool remove(){
      if(!primeiro)
        return false;

      No* ptrAtual = primeiro;
      primeiro = ptrAtual->prox;
      primeiro->ant = NULL;
      delete ptrAtual;

      total--;
      return true;
    }

    virtual ~Pilha_V2(){
      while(primeiro){
        remove();
      }
    }
};

#endif // PILHA_H
