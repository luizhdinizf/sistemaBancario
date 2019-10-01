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
    std::string nomeTemp = "-1";
    for(int i = 0; i < Contas.size();i++){
      if(Contas[i]->getNumConta() == numConta){
        nomeTemp = Contas[i]->NomeCliente();
        Contas.erase(Contas.begin()+i);
        return nomeTemp;
      }
    }
    // return "-1"; // retorna -1 caso nao encontre nada, o que quer dizer que nao tem nenhuma conta

  }
  void Banco::DepositarConta(int numConta, double valor, Date d){
    Contas[numConta-1]->CreditarValor(valor, "Deposito", d);
  }
  void Banco::SacarConta(int numConta, double valor, Date d){
    Contas[numConta-1]->DebitarValor(valor, "Saque", d);
  }

  void Banco::TransferirDePara(int contaOrigem,int contaDestino, double valor, Date d){
    std::string DescricaoOrigem = "Transferência PARA conta número "+ std::to_string(contaDestino);
    std::string DescricaoDestino = "Transferência DA conta número " + std::to_string(contaOrigem);
    Contas[contaOrigem-1]->DebitarValor(valor, DescricaoOrigem, d);
    Contas[contaDestino-1]->CreditarValor(valor, DescricaoDestino, d);
  }

  void Banco::CobrarTarifa(Date d){
    std::string Descricao = "Cobrança de Tarifa";
    double valorTarifa = 15.0;
    for(int i = 0; i < Contas.size();i++){
      Contas[i]->DebitarValorTarifa(valorTarifa, Descricao, d);
    }
  }

  double Banco::ObterSaldo(int numConta){
    return(Contas[numConta-1]->getSaldo());
  }

  std::vector<Movimentacao> Banco::ExtratoMensal(int numConta){
    return(Contas[numConta-1]->ExtratoMensal());

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit){
    return(Contas[numConta-1]->Extrato(DataInit));

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit, Date DataFinal){
    return(Contas[numConta-1]->Extrato(DataInit,DataFinal));
}


  void Banco::WriteToFile(){
    std::ofstream myfile;
    myfile.open("example.csv");
    myfile << "sep=;" << std::endl;
    for(int i = 0;i < Clientes.size();i++){
      myfile << Clientes[i]->getNome() << ";"
             << Clientes[i]->getCpf_cnpj() << ";"
             << Clientes[i]->getEndereco() << ";"
             << Clientes[i]->getFone() << std::endl;
      for(int j = 0;j < Contas.size();j++){
        if(Contas[j]->getCliente()->getCpf_cnpj() == Clientes[i]->getCpf_cnpj() ){ // se a conta estiver vinculada ao cpf anterior
          myfile << ";"; // 1 coluna para frente
          myfile << Contas[j]->getNumConta() << ";"
                 << Contas[j]->getSaldo() << std::endl;
          for(int k = 0; k < Contas[j]->Extrato().size(); k++){
            myfile <<";;"; // 2 colunas para frente
            myfile << Contas[j]->Extrato()[k].getDate().StringData() << ";"
                   << Contas[j]->Extrato()[k].getDescricao() << ";"
                   << Contas[j]->Extrato()[k].getDebitoCredito() << ";"
                   << Contas[j]->Extrato()[k].getValor() << std::endl;
          }
        }
      }
    }
  }
  void Banco::ReadFile(){
    std::ifstream myfile("example.csv");
    std::string linha;

    std::vector <std::string> dadosCliente;
    int numCliente = -1; // o numero do cliente para adicionar a conta(comeca do 0)
    std::vector <std::string> dadosConta;
    std::vector <std::string> dadosMovimentacao;
    std::getline(myfile,linha);
    if (linha == "sep=;"){ // Checar se o separador csv é o mesmo
      // nao fazer nada
    }




    while(getline(myfile,linha)){
      std::istringstream ss(linha);
      dadosCliente.clear();
      dadosConta.clear();
      if(linha[0] != ';'){ // A linha é um cliente, cadastra-lo
        while(ss){
          if (!getline( ss, linha, ';' )) break;
          dadosCliente.push_back(linha);
        }
        numCliente++;
        Banco::NovoCliente(new Cliente(dadosCliente[0],dadosCliente[1],dadosCliente[2],dadosCliente[3]));
      }
      else if( (linha[0] == ';') && (linha[1] != ';') ) {// a linha é uma conta, adiciona-la ao cliente
        while(ss){
          if (!getline( ss, linha, ';' )) break;
          dadosConta.push_back(linha);
        }
        Banco::NovaConta(getClientes()[numCliente]);
        numConta = dadosConta[0];

      }
      else if( (linha[0] == ';') && (linha[1] == ';') ) {// a linha é uma movimentacao, adiciona-la à contaOrigem
        while(ss){
          if (!getline( ss, linha, ';' )) break;
          dadosMovimentacao.push_back(linha);
        }
        if (dadosMovimentacao.back()[2] == "D"){ // fazer uma transacao tipo deposito
          DepositarConta(int numConta, double valor, Date d)
        }
      }
    }




    myfile.close();
  }
