#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "lde.h"
#include "FilaDinEncadeada.hpp"
using namespace std;
int main()
{
	LDE<string> reserva;
	int quarto = 0;
	string nome;
	string cpf;
	string duracao;
	string checkin;
	string checkout;
	int numReserv;
	bool menu = 1;
 	printf(
		"\n\t1 - Criar Reserva"
		"\n\t2- Remover Reservas"
		"\n\t3- Pesquisar Reservas"
	//	"\n\t4- Numero de Reservas"
		"\n\n"
		"\n\tInsira aqui:"
	);
	int comando;
	while (menu == 1){
	cin >> comando;
	
		if(comando == 1){
			
		numReserv = numReserv+1;
		printf("\n\tDigite o primeiro nome do cliente:");	
      	cin >> nome;
       // cout << "\t" << nome;
 		
		printf("Digite o CPF do cliente com pontos:");	
      	cin >> cpf;
       // cout<< "\t" << cpf;
		
		
		printf("Digite o numero de dias da estadia:");	
      	cin >> duracao;
       // cout << "\t" << duracao;
       
       	printf("Digite o horario de check-in (hh:mm):");	
      	cin >> checkin;
       // cout << "\t" << checkin;
       
       printf("Digite o horario de check-out (hh:mm):");	
      	cin >> checkout;
       // cout << "\t" << checkin;
      cout << "\n\tReserva criada com sucesso! Voce reservou o quarto " <<  quarto+1 << "!";
      string Result;

	ostringstream convert;

	convert << (quarto+1);

	Result = convert.str();
      reserva.insere(nome, cpf, duracao, checkin, checkout, Result);
      cout << "\n\tInsira o proximo comando:  ";
      
	  }
      
      
      if(comando == 2){
      	
      	 printf("Digite numero do seu quarto:");
      	 cin >> quarto;
      	 string Result;

	ostringstream convert;

	convert << (quarto+1);

	Result = convert.str();
      	 
      	 	nome = reserva.busca(Result)->nome;
      	 	reserva.remove(quarto);
      
      	 	cout << "\t" << nome;
      	
      	puts("Reserva removida com sucesso!");
      	cout << "\n\tInsira o proximo comando:  ";
		   
		  
		  }
      	 
		if(comando == 3){
      	 
      	 printf("Digite numero do seu quarto:");
      	 cin >> quarto;
      	 string Result;

		ostringstream convert;

		convert << (quarto);

		Result = convert.str();
      	 
      	 	cout << "\n\tNome: " << reserva.busca(Result)->nome;
      	 	cout << "\n\tCPF: " << reserva.busca(Result)->cpf;
      	 	cout << "\n\tDuracao da Estadia: " << reserva.busca(Result)->duracao;
      	 	cout << "\n\tHorario de Check-In: " << reserva.busca(Result)->checkin;
      	 	cout << "\n\tHorario de Check-Out: " << reserva.busca(Result)->checkout;
      	 	cout << "\n\tInsira o proximo comando:  ";
      	 	
      	 	
		   
		
		
      	
		}
	
    }
        
    //FilaDinEnc<string>GuardaReserva;
    //GuardaReserva.enfileira(nome);
			
	
    // t.insere(10);
   // t.insere(20);
    //t.insere(50);
   //  t.remove(0);
   // t.remove(1);
    // LDE<int> t2;
   // t2.insere(92);
  //  t2.insere(910);
  //  t2.insere(920);
  //  t2.insere(950);
    // cout << t2;
//
    //LDE<int> t3;
  //  t3 = t + t2;
 //   cout << t3;
    // const No<char>* a = t.busca(10);
   // cout << a->getValor() << endl;
     //cout << t.getPrimeiro()->getProx()->getValor() << endl;
     return 0;
}
