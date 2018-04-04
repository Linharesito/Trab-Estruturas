#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "pilha.h"

class Data{
  private:
      Data* prox;
      int dia;
      int mes;
      int ano;
      Pilha_V2 *horarios;

  public:
      void getData() const{
          std::cout << dia << "/" << mes << "/" << ano << endl;
      }

      const Data* getProx() const{
          return prox;
      }

      Data(): prox(NULL), dia(0), mes(0), ano(0){}

    friend class LDE;
};

#endif // DATA_H
