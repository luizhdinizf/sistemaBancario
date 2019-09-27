#include "Banco.h"
  Banco::Banco(){
    nomeBanco = "";
  }
  Banco::Banco(std::string nB){
    this-> nomeBanco = nB;
  }
  std::string &Banco::getNome(){
    return nomeBanco;
  }
  std::string Banco::RemoverCliente(std::string cpf_cnpj){
    std::string nomeTemp;
    for(int i = 0; i < Clientes.size();i++){
      if(Clientes[i]->getCpf_cnpj() == cpf_cnpj){
        nomeTemp = Clientes[i]->getNome();
        Clientes.erase(Clientes.begin()+i);
        return nomeTemp;
      }
    }
  }
  std::vector<Cliente*> Banco::getClientes(){
    return Clientes;
  }
  void Banco::NovoCliente(Cliente* cliente){
    Clientes.push_back(cliente);
  }
  std::vector<Conta*> &Banco::getContas(){
    return Contas;
  }
  void Banco::NovaConta(Cliente* cliente){
    Contas.push_back(new Conta(cliente));
  }
  std::string Banco::RemoverConta(int numConta){
    std::string nomeTemp;
    for(int i = 0; i < Contas.size();i++){
      if(Contas[i]->getNumConta() == numConta){
        nomeTemp = Contas[i]->NomeCliente();
        Contas.erase(Contas.begin()+i);
        return nomeTemp;
      }
    }
  }
  void Banco::DepositarConta(int numConta, double valor, Date d){
    Contas[numConta]->DebitarValor(valor, "Deposito",d);
  }
