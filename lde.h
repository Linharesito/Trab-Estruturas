#ifndef LDE_H
#define LDE_H

#include <iostream>
#include "data.h"
#include "no.h"

using namespace std;

class LDE{
  private:
    Data *primeiro;
    int total;

  public:

    LDE(): primeiro(NULL), total(0){}

    bool insert(int dia, int mes, int ano,int hora, int min, string desc){

      Data *atual = primeiro, *anterior = NULL;
      Data *novo = new Data;

      if(!novo)
        return false;

      novo->prox = NULL;
      novo->dia = dia;
      novo->mes = mes;
      novo->ano = ano;

      while(atual && (atual->ano <= ano && atual->mes <= mes && atual->dia < dia)){
        if(atual->ano == ano && atual->mes == mes && atual->dia == dia){
          atual->horarios->insert_pilha(hora, min, desc);
        }

        anterior = atual;
        atual = atual->prox;
      }

      novo->horarios->insert_pilha(hora, min, desc);
      novo->prox = atual;

      if(anterior){
        anterior->prox = novo;
      }else{
        primeiro = novo;
      }

      total++;
      return true;
    }

    Data* Busca(int dia, int mes, int ano){
      Data* atual = primeiro;

      while(atual && (atual->ano <= ano && atual->mes <= mes && atual->dia < dia)){
        if(atual->ano == ano && atual->mes == mes && atual->dia == dia)
          return atual;
      }

      return NULL;
    }

    Data* Busca(int mes, int ano){
      Data* atual = primeiro;

      while(atual && (atual->ano <= ano && atual->mes <= mes)){
        if(atual->ano == ano && atual->mes == mes)
          return atual;
      }

      return NULL;
    }

    virtual ~LDE(){
      Data* atual = primeiro, *proximo = NULL;
      while(atual){
        proximo = atual->prox;
        delete atual;
        atual = proximo;
      }
    }

    void ListarDia(int dia, int mes, int ano){
      Data* n = Busca(dia, mes, ano);

      if(!n)
        cout << "Este dia nao possui compromissos" << endl;

      No* n2 = n->horarios->primeiro, *n3;
      while(n2){
        cout << n2->hora << ":" << n2->minuto << endl;
        cout << "Compromisso: " << n2->desc << endl;
        n3 = n2->prox;
        n2 = n2;
      }
    }

    void ListarMes(int mes, int ano){
      Data* atual = Busca(mes, ano), *proximo = NULL;

      if(!atual)
        cout << "Nao existem compromissos nesse mes" << endl;

      else{
        while(atual){
          cout << atual->dia << "/" << atual->mes << "/" << atual->ano << endl;

          if(!(atual->horarios->primeiro))
              cout << "Nao existem compromissos nesse dia" << endl;

          else{
            No *ptrAtual = atual->horarios->primeiro, *Prox;
            while(ptrAtual){
              cout << ptrAtual->hora << ":" << ptrAtual->minuto << endl;
              cout << "Compromisso: " << ptrAtual->desc << endl;
              Prox = ptrAtual;
              ptrAtual = ptrAtual->prox;
            }

          }

          proximo = atual->prox;
          atual = proximo;
        }
      }
    }
};


#endif // LDE_H
