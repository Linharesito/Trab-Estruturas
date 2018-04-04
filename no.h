#ifndef NO_H
#define NO_H

#include <iostream>

using namespace std;

class No{
  public:
    No* prox;
    No* ant;
    int hora;
    int minuto;
    string desc;

  public:
    const No* getProx() const{
          return prox;
    }

    const No* getAnt() const{
          return ant;
    }

    void getTime() const{
          std::cout << hora << ":" << minuto << endl;
    }

    No(): prox(NULL), ant(NULL), hora(0), minuto(0), desc(""){}

    friend class Pilha;
};

#endif // NO_H
