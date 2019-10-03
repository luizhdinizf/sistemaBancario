#include <bits/stdc++.h>
#include <ctime>
#include <vector>

#include "date.h"
#include "cliente.h"
#include "Movimentacao.h"
#include "Conta.h"
#include "Banco.h"


using namespace std;


int Conta::counter = 0; // inicializa valor static
int Interface::counter = 0; // inicializa valor static

int main() {
  // ---===TESTE INTERFACE ===---
  Banco * Banco2 = new Banco("Bradesco");
  Interface * teste = new Interface(Banco2);
  teste->Menu();
  return 0;
}
