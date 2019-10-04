#ifndef BANCO_H
#define BANCO_H
#include <bits/stdc++.h>
#include "Cliente.h"
#include "Conta.h"
#include "Date.h"

class Banco{
private:
  std::string nomeBanco;
  std::vector<Cliente*> Clientes;
  std::vector<Conta*> Contas;
public:
  Banco();
  Banco(std::string nB);
  ~Banco();
  std::string &getNome();
  int ProcurarPorCPF(std::string cpf_cnpj);
  std::string RemoverCliente(std::string cpf_cnpj);
  std::vector<Cliente*> &getClientes();
  void NovoCliente(Cliente* cliente);
  std::vector<Conta*> &getContas();
  Conta *getConta(int numConta);
  void NovaConta(Cliente* cliente);
  void NovaConta(Cliente* cliente,int numConta);
  bool ExisteConta(int numConta);
  std::string RemoverConta(int numConta);
  void DepositarConta(int numConta, double valor,Date d);
  void SacarConta(int numConta, double valor,Date d);
  void TransferirDePara(int contaOrigem,int contaDestino, double valor, Date d);
  void CobrarTarifa(Date d);
  void CobrarCPMF();
  double ObterSaldo(int numConta);
  std::vector<Movimentacao> ExtratoMensal(int numConta);
  std::vector<Movimentacao> Extrato(int numConta,Date DataInit);
  std::vector<Movimentacao> Extrato(int numConta,Date DataInit, Date DataFinal);
  void WriteToFile();
  void ReadFile();

};

#endif
