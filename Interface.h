#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Banco.h"

class Interface{
private:
  Banco* Banco1;
  static int counter;
public:
  Interface(Banco *b);
  void Menu();
  void CadastrarCliente();
  void MostrarClientes();
  void MostrarContas();
  void CadastrarConta();
  void ExcluirCliente();
};
#endif
