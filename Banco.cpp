#include "Banco.h"
  Banco::Banco(){
    nomeBanco = "";
  }
  Banco::Banco(std::string nB){
    this-> nomeBanco = nB;
  }

  Banco::~Banco(){}
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
  Conta *Banco::getConta(int numConta){
    for(int i = 0; i < Contas.size();i++){
      if(numConta == Contas[i]->getNumConta()){
        return Contas[i];
      }
    }
  }


  void Banco::NovaConta(Cliente* cliente){
    if(getContas().size() == 0){
      Contas.push_back(new Conta(cliente,1));
    } else {
      Contas.push_back(new Conta(cliente,getContas().back()->getNumConta() + 1));
    }
  }

  void Banco::NovaConta(Cliente* cliente,int numConta){
    Contas.push_back(new Conta(cliente,numConta));
  }

  bool Banco::ExisteConta(int numConta){
    for(int i = 0; i <  getContas().size();i++ ){
      if(numConta == getContas()[i]->getNumConta()){
        return true;
      }
    }
    return false;
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
    getConta(numConta)->CreditarValor(valor, "Deposito", d);
  }
  void Banco::SacarConta(int numConta, double valor, Date d){
    getConta(numConta)->DebitarValor(valor, "Saque", d);
  }

  void Banco::TransferirDePara(int contaOrigem,int contaDestino, double valor, Date d){
    std::string DescricaoOrigem = "Transferência PARA conta número "+ std::to_string(contaDestino);
    std::string DescricaoDestino = "Transferência DA conta número " + std::to_string(contaOrigem);
    getConta(contaOrigem)->DebitarValor(valor, DescricaoOrigem, d);
    getConta(contaDestino)->CreditarValor(valor, DescricaoDestino, d);
  }

  void Banco::CobrarTarifa(Date d){
    std::string Descricao = "Cobrança de Tarifa";
    double valorTarifa = 15.0;
    for(int i = 0; i < Contas.size();i++){
      Contas[i]->DebitarValorTarifa(valorTarifa, Descricao, d);
    }
  }
  void Banco::CobrarCPMF(){
    Date* DataHoje = new Date();
    DataHoje->SetToday();
    Date* SemanaPassada = new Date();
    SemanaPassada->VoltarSemana(DataHoje);
    double valorTotal = 0; // Soma todos os valores de debito para fazer o calculo
    for(int i = 0; i < Contas.size();i++){
      valorTotal = 0;
      for(int j = 0; j < Contas[i]->Extrato(*SemanaPassada,*DataHoje).size();j++ ){
        if(Contas[i]->Extrato(*SemanaPassada,*DataHoje)[j].getDebitoCredito() == 'D'){
          valorTotal = valorTotal + Contas[i]->Extrato(*SemanaPassada,*DataHoje)[j].getValor();
        }
      }
      if (valorTotal > 0){
        valorTotal = valorTotal * 0.0038;
        Contas[i]->DebitarValorTarifa(valorTotal, "Cobranca CPMF", *DataHoje);
      }

    }


  }
  double Banco::ObterSaldo(int numConta){
    return(getConta(numConta)->getSaldo());
  }

  std::vector<Movimentacao> Banco::ExtratoMensal(int numConta){
    return(getConta(numConta)->ExtratoMensal());

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit){
    return(getConta(numConta)->Extrato(DataInit));

  }
  std::vector<Movimentacao> Banco::Extrato(int numConta,Date DataInit, Date DataFinal){
    return(getConta(numConta)->Extrato(DataInit,DataFinal));
}


  void Banco::WriteToFile(){
    std::ofstream myfile;
    myfile.open("DadosBanco.csv", std::ofstream::out | std::ofstream::trunc);
    myfile  << "sep=;" << std::endl;
    // << "ArquivoBancoELE078" << std::endl; // checar para ver se o arquivo é suportado
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
    std::ifstream myfile("DadosBanco.csv");
    std::string linha;

    char nomeCliente[100], cpfCliente[100], enderecoCliente[100],foneCliente[100];
    int numCliente = -1; // o numero do cliente para adicionar a conta(comeca do 0)

    // Organizacao para Conta
    int numConta, saldoConta;
    // Organizacao para Movimentacao
    int dia,mes,ano;
    double valor;
    char dc;
    char descricao[100];

    std::getline(myfile,linha); // pula o separador

      while(getline(myfile,linha)){
        // std::cout << "LINHA: " << linha << std::endl;
        if(linha[0] != ';'){ // A linha é um cliente, cadastra-lo
          std::sscanf(linha.c_str(),"%[^;];%[^;];%[^;];%[^;]",nomeCliente,cpfCliente,enderecoCliente,foneCliente);
          numCliente++;
          Banco::NovoCliente(new Cliente(nomeCliente,cpfCliente,enderecoCliente,foneCliente));
        }
        else if( (linha[0] == ';') && (linha[1] != ';') ) {// a linha é uma conta, adiciona-la ao cliente
          std::sscanf(linha.c_str(), ";%int;int", &numConta,&saldoConta);

          Banco::NovaConta(getClientes().back(), numConta); // como esta feito em sequencia, a conta é pro ultimo cliente cadastrado
        }
        else if( (linha[0] == ';') && (linha[1] == ';') ) {// a linha é uma movimentacao, adiciona-la à conta
          std::sscanf(linha.c_str(),";;%d/%d/%d;%[^;];%c;%lf",&dia,&mes,&ano,descricao,&dc, &valor); // metodo separacao
          if (dc == 'C'){ // Creditar na conta
            getConta(numConta)->CreditarValor(valor,descricao,Date(dia,mes,ano));
          }
          else if (dc == 'D'){ // Debitar na conta
            getConta(numConta)->DebitarValor(valor,descricao,Date(dia,mes,ano));
          }
        }
      }
    std::cout << "Terminou de ler" << std::endl;

    myfile.close();
  }
