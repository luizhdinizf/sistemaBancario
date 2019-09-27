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
  std::string &getNome();
  std::string RemoverCliente(std::string cpf_cnpj);
  std::vector<Cliente*> getClientes();
  void NovoCliente(Cliente* cliente);
  std::vector<Conta*> &getContas();
  void NovaConta(Cliente* cliente);
  std::string RemoverConta(int numConta);
  void DepositarConta(int numConta, double valor,Date d);
  void SacarConta(int numConta, double valor,Date d);
  void TransferirDePara(int contaOrigem,int contaDestino, double valor, Date d);
  void CobrarTarifa(Date d);
  
};

#endif
