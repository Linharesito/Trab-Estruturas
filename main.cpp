#include <iostream>
#include "lde.h"
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
	bool menu = 1;

	printf(
		"\n\t1 - Criar Reserva"
		"\n\t2- Remover Reservas"
		"\n\t3- Pesquisar Reservas"
		"\n\t4- Fecha Menu"
		"\n\n"
		"\n\tInsira aqui:"
	);
	int comando;
	while (menu == 1){
	cin >> comando;
	
		if(comando == 1){
		
		printf("\n\tDigite o primeiro nome do cliente:");	
      	cin >> nome;
        reserva.insere(nome);
       // cout << "\t" << nome;

		
		printf("Digite o CPF do cliente com pontos:");	
      	cin >> cpf;
        reserva.insere(cpf);
       // cout<< "\t" << cpf;
		
		
		printf("Digite o numero de dias da estadia:");	
      	cin >> duracao;
        reserva.insere(duracao);
       // cout << "\t" << duracao;
       
       	printf("Digite o horario de check-in (hh:mm):");	
      	cin >> checkin;
        reserva.insere(checkin);
       // cout << "\t" << checkin;
       
       printf("Digite o horario de check-out (hh:mm):");	
      	cin >> checkout;
        reserva.insere(checkout);
       // cout << "\t" << checkin;
      cout << "\n\tReserva criada com sucesso! Voce reservou o quarto " <<  quarto+1 << "!";
      cout << "\n\tInsira o proximo comando:  ";
      
	  }
      
      
      if(comando == 2){
      	
      	 printf("Digite numero do seu quarto:");
      	 cin >> quarto;
      	 if(quarto = 1){
      	 	reserva.remove(0);
      
      	 	cout << "\t" << nome;
      	
      	puts("Reserva removida com sucesso!");
      	cout << "\n\tInsira o proximo comando:  ";
		   } 
		  
		  }
      	 
		if(comando == 3){
      	 
      	 printf("Digite numero do seu quarto:");
      	 cin >> quarto;
      	 if(quarto == 1){
      	 	cout << "\n\tNome: " << reserva.busca(nome)->valor;
      	 	cout << "\n\tCPF: " << reserva.busca(cpf)->valor;
      	 	cout << "\n\tDuracao da Estadia: " << reserva.busca(duracao)->valor;
      	 	cout << "\n\tHorario de Check-In: " << reserva.busca(checkin)->valor;
      	 	cout << "\n\tHorario de Check-Out: " << reserva.busca(checkout)->valor;
      	 	cout << "\n\tInsira o proximo comando:  ";
      	 	
      	 	
		   }
		
		
      	
		}
	
    }
        
			
	

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
