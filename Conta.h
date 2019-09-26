#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.h"



class Conta{
private:
  static int counter;
  int numConta; //OBS STATIC???
  double saldo;
  Cliente* cliente; //= new Cliente();
  std::vector<Movimentacao> movimentacoes;
  static int proxNumConta;
public:
  Conta(Cliente* c);
  void DebitarValor(double valor,std::string desc,Date d);
  void CreditarValor(double valor,std::string desc,Date d);
  std::vector<Movimentacao> &Extrato();
  std::vector<Movimentacao> Extrato(Date DataInit, Date DataFinal);
  int getNumConta();
  double getSaldo();
  Cliente *getCliente();
  std::string NomeCliente();
};
#endif
