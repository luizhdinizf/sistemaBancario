#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.h"
#include "Date.h"



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
  Conta(Cliente* c,int nC);
  ~Conta();
  void DebitarValor(double valor,std::string desc);
  void CreditarValor(double valor,std::string desc);
  void DebitarValor(double valor,std::string desc,Date d);
  void DebitarValorTarifa(double valor,std::string desc,Date d);
  void CreditarValor(double valor,std::string desc,Date d);
  std::vector<Movimentacao> &Extrato();
  std::vector<Movimentacao> ExtratoMensal();
  std::vector<Movimentacao> Extrato(Date DataInit);
  std::vector<Movimentacao> Extrato(Date DataInit, Date DataFinal);
  void setNumConta(int nC);
  int getNumConta();
  double getSaldo();
  Cliente *getCliente();
  std::string NomeCliente();
};
#endif
