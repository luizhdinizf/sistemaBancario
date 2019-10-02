#include <bits/stdc++.h>
#include <ctime>
#include <vector>

#include "Banco.h"
#include "Interface.h"
#include "Date.h"
using namespace std;





int Conta::counter = 0; // inicializa valor static
int Interface::counter = 0; // inicializa valor static
int main(){
  // ---===TESTE INTERFACE ===---
  Banco * Banco2 = new Banco("Bradesco");
  Interface * teste = new Interface(Banco2);
  teste->Menu();

  // //TESTE DATA
  // Date* Data1 = new Date(06,05,2015);
  // Date* Data2 = new Date();
  // Data2->VoltarSemana(Data1);
  // cout << "Dia: " << Data2->getDay() << " Mes: " << Data2->getMonth() << " Ano: " << Data2->getYear() << endl;


  // // TESTE Conta
  // Banco * Banco1 = new Banco("Bradesco");
  // Banco1->NovoCliente(new Cliente("nome","cpf","endereco","fone"));
  // Banco1->NovaConta(Banco1->getClientes()[0]);
  // cout << Banco1->getConta(1)->getCliente()->getNome();

  return 0;
}
