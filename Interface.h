#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Banco.h"

class Interface{
private:
  Banco* Banco1;
  static int counter;
  Date * DataHoje = new Date();

public:
  Interface(Banco *b);
  ~Interface();
  void Menu();
  void CadastrarCliente();
  void MostrarClientes();
  void MostrarContas();
  void CadastrarConta();
  void ExcluirCliente();
  void ExcluirConta();
  void EfetuarDeposito();
  void EfetuarSaque();
  void EfetuarTransferencia();
  void CobrarTarifa();
  void CobrarCPMF();
  void MostrarSaldo();
  void ObterExtratoMensal();
  void ObterExtratoInicial();
  void ObterExtratoRange();
};
#endif
