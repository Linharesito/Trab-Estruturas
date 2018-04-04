#include <iostream>
#include <string>
#include "LDE.h"

using namespace std;

void MENU(){
  cout << "-----------------------------------------------------------------------" << endl;
  cout << "1 -> Inserir compromisso" << endl;
  cout << "2 -> Listar compromissos" << endl;
  cout << "3 -> Fechar Agenda" << endl;
  cout << "-----------------------------------------------------------------------" << endl;
}

int main() {

  int n, dia, mes, ano, hora, minuto;
  string str;
  LDE *Agenda = new LDE;

  MENU();

  while(cin >> n){

    if(n == 1){
      cout << "Digite o dia, mes, ano, hora, minuto e uma descricao do compromisso, na respectiva ordem" << endl;
      cout << "Dia: ";cin >> dia;
      cout << "Mes: ";cin >> mes;
      cout << "Ano: ";cin >> ano;
      cout << "Hora: ";cin >> hora;
      cout << "Minuto: ";cin >> minuto;
      cout << "Descricao: ";getline(cin, str);

      Agenda->insert(dia,mes,ano,hora,minuto,str);

    }
    else if(n == 2){
      int m;
      cout << "Deseja listar todos os compromissos:" << endl << "1 -> Do dia" << endl << "2 -> Do mes" << endl;
      cin >> m;

      if(m == 1){
        cout << "Digite o dia, mes, ano, na respectiva ordem" << endl;
        cout << "Dia: ";cin >> dia;
        cout << "Mes: ";cin >> mes;
        cout << "Ano: ";cin >> ano;
        Agenda->ListarDia(dia, mes, ano);
      }
      else{
        cout << "Digite o mes, ano, na respectiva ordem" << endl;
        cout << "Mes: ";cin >> mes;
        cout << "Ano: ";cin >> ano;
        Agenda->ListarMes(mes, ano);
      }

    }

    else if(n == 3){
      return 0;
    }

    MENU();

  }

  return 0;
}
