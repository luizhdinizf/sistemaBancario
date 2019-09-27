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
  int Banco::ProcurarPorCPF(std::string cpf_cnpj){ // retorna o numero do cliente pelo cpf
    int numCliente = -1;
    for(int i = 0; i < Clientes.size();i++){
      if(Clientes[i]->getCpf_cnpj() == cpf_cnpj){
        numCliente = i;
        return numCliente;
      }

    }
    return numCliente;
  }
  std::string Banco::RemoverCliente(std::string cpf_cnpj){ // BUG: Caso nao ache, vai retornar 0, resolucao, comecar NumCliente com -1, se for -1 cliente nao foi achado pelo cpf e nao apaga
    std::string nomeTemp;
    int numCliente = -1;
    numCliente = ProcurarPorCPF(cpf_cnpj);
    // if (numCliente == -1){ // Nao achou cliente NAO É NECESSARIO, uma vez que corrija-se o problema na interface
    //   return "Nada";
    // } else{
      nomeTemp = Clientes[numCliente]->getNome();
      Clientes.erase(Clientes.begin()+numCliente);
      return nomeTemp;
    // }
    }


  std::vector<Cliente*> &Banco::getClientes(){
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
    Contas[numConta]->CreditarValor(valor, "Deposito", d);
  }
  void Banco::SacarConta(int numConta, double valor, Date d){
    Contas[numConta]->DebitarValor(valor, "Saque", d);
  }

  void Banco::TransferirDePara(int contaOrigem,int contaDestino, double valor, Date d){
    std::string DescricaoOrigem = "Transferência PARA conta número "+ std::to_string(contaOrigem);
    std::string DescricaoDestino = "Transferência DA conta número " + std::to_string(contaOrigem);
    Contas[contaOrigem]->DebitarValor(valor, DescricaoOrigem, d);
    Contas[contaDestino]->CreditarValor(valor, DescricaoDestino, d);
  }

  void Banco::CobrarTarifa(Date d){
    std::string Descricao = "Cobrança de Tarifa";
    double valorTarifa = 15.0;
    for(int i = 0; i < Contas.size();i++){
      Contas[i]->DebitarValor(valorTarifa, Descricao, d);
    }
  }

  double Banco::ObterSaldo(int numConta){
    return(Contas[numConta]->getSaldo());
  }

  std::vector<Movimentacao> Banco::ExtratoMensal(int numConta){
    return(Contas[numConta]->ExtratoMensal());

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit){
    return(Contas[numConta]->Extrato(DataInit));

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit, Date DataFinal){
    return(Contas[numConta]->Extrato(DataInit,DataFinal));

  }
