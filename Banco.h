#ifndef BANCO_H
#define BANCO_H
#include <bits/stdc++.h>
#include "Cliente.h"
#include "Conta.h"

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
  void DepositarConta(int numConta, int valor, Date d);
};

#endif
