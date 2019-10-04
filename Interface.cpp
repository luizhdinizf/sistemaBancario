#include "Interface.h"

  Interface::Interface(Banco *b){
    counter++;
    Banco1 = b;
  }
  Interface::~Interface(){}

  void Interface::Menu(){
    int selecao;
    std::cout << std::endl << "---======== Banco " << Banco1->getNome() << "========---" << std::endl
         << "Selecione a opçao desejada: " << std::endl
         << "1. Cadastrar novo Cliente" << std::endl
         << "2. Cadastrar nova conta" << std::endl
         << "3. Excluir Cliente" << std::endl
         << "4. Excluir Conta" << std::endl
         << "5. Efetuar Deposito" << std::endl
         << "6. Efetuar Saque" << std::endl
         << "7. Efetuar Transferencia" << std::endl
         << "8. Cobrar Tarifa" << std::endl
         << "9. Cobrar CPMF" << std::endl
         << "10. Mostrar Saldo" << std::endl
         << "11. Obter Extrato Mensal" << std::endl
         << "12. Obter Extrato a partir de uma data" << std::endl
         << "13. Obter Extrato entre 2 datas" << std::endl
         << "16. Mostrar Clientes" << std::endl
         << "17. Mostrar Contas" << std::endl
         << "18. Gravar Dados" << std::endl
         << "19. Ler Dados" << std::endl
         << "Opcao Escolhida: ";
    std::cin >> selecao;
    switch(selecao){
      case(1):
        Interface::CadastrarCliente();
        break;
      case(2):
        Interface::CadastrarConta();
        break;
      case(3):
        Interface::ExcluirCliente();
        break;
      case(4):
        Interface::ExcluirConta();
        break;
      case(5):
        Interface::EfetuarDeposito();
        break;
      case(6):
        Interface::EfetuarSaque();
        break;
      case(7):
        Interface::EfetuarTransferencia();
        break;
      case(8):
        Interface::CobrarTarifa();
        break;
      case(9):
        Interface::CobrarCPMF();
        break;
      case(10):
        Interface::MostrarSaldo();
        break;
      case(11):
        Interface::ObterExtratoMensal();
        break;
      case(12):
        Interface::ObterExtratoInicial();
        break;
      case(13):
        Interface::ObterExtratoRange();
        break;
      case(16):
        Interface::MostrarClientes();
        Interface::Menu();
        break;
      case(17):
        Interface::MostrarContas();
        Interface::Menu();
        break;
      case(18):
        Banco1->WriteToFile();
        Interface::Menu();
        break;
      case(19):
        Banco1->ReadFile();
        Interface::Menu();
        break;
    }

  }
  void Interface::CadastrarCliente(){
    std::string nomeCliente,cpf_cnpj,endereco,fone;
    char confirmacao;



    std::cout << "Nome do cliente: ";
    std::cin.ignore();
    getline(std::cin, nomeCliente); // Usa-se essa funcao para permitir espacos
    if(nomeCliente == ""){ // Caso o usuario nao coloqueo client, considerar um espaco para a leitura correta do arquivo
      nomeCliente = " ";
    }
    std::cout << "CPF ou CNPJ: ";
    std::cin >> cpf_cnpj;
    std::cout << "Endereco: ";
    std::cin.ignore();
    getline(std::cin, endereco); // Usa-se essa funcao para permitir espacos
    std::cout << "fone: ";
    std::cin >> fone;
    std::cout << "Deseja confirmar o cadastro?[S/N]: ";
    std::cin  >> confirmacao;
    if(confirmacao == 'S'){

      Banco1->NovoCliente(new Cliente(nomeCliente,cpf_cnpj,endereco,fone));
      std::cout << "Cliente "<< Banco1->getClientes().back()->getNome() <<" Cadastrado" << std::endl;
    } else if (confirmacao == 'N') {
      std::cout << "Cliente removido" << std::endl;
    }
    Interface::Menu();
  }
  void Interface::MostrarClientes(){
    for(int i = 0;i < Banco1->getClientes().size(); i++){
      std::cout << i << ". " << Banco1->getClientes()[i]->getNome() << std::endl;
    }
  }

  void Interface::MostrarContas(){
    if (Banco1->getContas().size() == 0){
      std::cout << "Não há nenhuma conta cadastrada, cadastre uma conta antes." << std::endl;
    }
    for(int i = 0;i < Banco1->getContas().size(); i++){
      std::cout << Banco1->getContas()[i]->getNumConta() << "." << Banco1->getContas()[i]->getCliente()->getNome()  << std::endl;
    }
  }


  void Interface::CadastrarConta(){
    if (Banco1->getClientes().size() == 0){
      std::cout << "Não há nenhuma cliente cadastrado, cadastre um cliente para ser vinculado a conta antes." << std::endl;
      Interface::Menu();
    } else {
      int numCliente;
      std::cout << "Escolha o Cliente, a partir do seu número para a conta ser criada." << std::endl;
      Interface::MostrarClientes();
      std::cout << "Escolha: ";
      std::cin >> numCliente;
      if (numCliente > Banco1->getClientes().size()){
        std::cout << "Numero do cliente nao existente" << std::endl;
      }else{
        Banco1->NovaConta(Banco1->getClientes()[numCliente]);
        std::cout << "Conta do cliente " << Banco1->getContas().back()->getCliente()->getNome()
                  << " criada -> Numero da conta: " << Banco1->getContas().back()->getNumConta() << std::endl;
      }

    }
    Interface::Menu();
  }

  void Interface::ExcluirCliente(){
    std::string cpf;
    int indexCliente;
    char confirmacao;
    std::cout << "Digite o cpf/CNPJ do cliente a ser excluido " << std::endl;
    std::cin >> cpf;
    indexCliente = Banco1->ProcurarPorCPF(cpf);
    if(indexCliente == -1){
      std::cout << "CPF/CNPF informado não esta cadastrado na nossa base de dados, por favor insira um cpf válido." << std::endl;
      // ExcluirCliente(); // Fica em um loop infinito caso nao tenha nenhum cliente, melhor voltar ao menu
      Interface::Menu();
    } else {
      std::cout << "Deseja remover o cliente " << Banco1->getClientes()[indexCliente]->getNome() << "?[S/N]" << std::endl;
      std::cin >> confirmacao;
      if(confirmacao == 'S'){
        std::cout << "Cliente " << Banco1->RemoverCliente(cpf) << " removido" << std::endl;
      } else {
        std::cout << "Voltando ao menu..." << std::endl;
      }
    }
    Interface::Menu();

  }

  void Interface::ExcluirConta(){
    std::string nomeConta;
    int numConta;
    char confirmacao;
    std::cout << "Digite o nº da conta a ser excluido " << std::endl;
    std::cin >> numConta;

    if(Banco1->ExisteConta(numConta)){
      nomeConta = Banco1->getConta(numConta)->getCliente()->getNome();
      std::cout << "Deseja remover a conta " << numConta << " do cliente " << nomeConta << "?[S/N]" << std::endl;
      std::cin >> confirmacao;
      if(confirmacao == 'S'){
        std::cout << "Conta " << Banco1->RemoverConta(numConta) << " removido" << std::endl;
      } else {
        std::cout << "Voltando ao menu..." << std::endl;
      }
    } else {
      std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;

    }
    Interface::Menu();

  }



  void Interface::EfetuarDeposito(){
    int numConta;
    double valor;
    DataHoje->SetToday();
    std::cout << "Digite o numero da conta para efetuar o deposito:" << std::endl << "Numero:";
    std::cin >> numConta;

    if(Banco1->ExisteConta(numConta)){
      std::cout << "Quanto deseja depositar na conta " << numConta << " ?" << std::endl;
      std::cin >> valor;
      Banco1->DepositarConta(numConta,valor, *DataHoje);
      std::cout << valor << " depositados na conta " << numConta << std::endl;
    } else {
      std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
  }
  Interface::Menu();
}
void Interface::EfetuarSaque(){
  int numConta;
  double valor;
  DataHoje->SetToday();
  std::cout << "Digite o numero da conta para efetuar o saque:" << std::endl << "Numero:";
  std::cin >> numConta;
  if(Banco1->ExisteConta(numConta)){
    std::cout << "Quanto deseja sacar da conta " << numConta << " ?" << std::endl;
    std::cin >> valor;
    if(valor > Banco1->getConta(numConta)->getSaldo() ){
      std::cout << "Valor superior ao saldo da conta, saque não efetuado" <<  std::endl;
    } else {
      Banco1->SacarConta(numConta,valor, *DataHoje);
      std::cout << valor << " sacados da conta " << numConta << std::endl;
    }
  } else {
    std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;

}
Interface::Menu();
}

void Interface::EfetuarTransferencia(){
  int numContaOrigem;
  int numContaDestino;
  double valor;
  DataHoje->SetToday();
  std::cout << "Digite o numero da conta de origem:" << std::endl << "Numero:";
  std::cin >> numContaOrigem;
  if(Banco1->ExisteConta(numContaOrigem)){
    std::cout << "Digite o numero da conta de destino:" << std::endl << "Numero:";
    std::cin >> numContaDestino;
    if(Banco1->ExisteConta(numContaDestino)){
      std::cout << "Quanto deseja transferir para a conta " << numContaDestino << " ?" << std::endl;
      std::cin >> valor;
      if(valor > Banco1->getConta(numContaOrigem)->getSaldo() ){
        std::cout << "Valor superior ao saldo da conta, transferencia não efetuada" <<  std::endl;
      }else {
        Banco1->TransferirDePara(numContaOrigem, numContaDestino,valor ,*DataHoje);
        std::cout << "Transferidos R$" << valor << " da conta " << numContaOrigem << " para a conta " << numContaDestino << std::endl;
      }
    } else {
      std::cout << "Nº da conta destino não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;

    }
  } else {
    std::cout << "Nº da conta origem não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
  }
Interface::Menu();
}

void Interface::CobrarTarifa(){
  char confirmacao;
  std::cout << "Deseja cobrar a tarifa de R$15 para todas as contas? [S/N]: ";
  std::cin >> confirmacao;
  if (confirmacao == 'S'){
    DataHoje->SetToday();
    Banco1->CobrarTarifa(*DataHoje);
    std::cout << "Tarifa cobrada de todas as contas" << std::endl;
  } else if (confirmacao == 'N'){
    std:: cout << "Tarifa nao foi cobrada, retornando ao menu..." << std::endl;
  }
  Interface::Menu();


}

void Interface::CobrarCPMF(){
  Banco1->CobrarCPMF();
  std::cout<< " CPMF cobrado de todas as contas" << std::endl;
  Interface::Menu();
}

void Interface::MostrarSaldo(){
  int numConta;
  std::cout << "Digite o número da conta: ";
  std::cin >> numConta;
  if(Banco1->ExisteConta(numConta)){
    std::cout << "Saldo: R$" << Banco1->ObterSaldo(numConta);
  } else {
    std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
  }
  Interface::Menu();
}

void Interface::ObterExtratoMensal(){
  int numConta;
  std::cout << "Digite o numero da conta: ";
  std::cin >> numConta;
  if(Banco1->ExisteConta(numConta)){
    for(int i = 0; i < Banco1->ExtratoMensal(numConta).size();i++){
      std::cout << "Data: " << Banco1->ExtratoMensal(numConta)[i].getDate().StringData()
                << " Tipo: " << Banco1->ExtratoMensal(numConta)[i].getDebitoCredito()
                << " Valor: " << Banco1->ExtratoMensal(numConta)[i].getValor()
                << " Descricao: " << Banco1->ExtratoMensal(numConta)[i].getDescricao() << std::endl;
    }
    std::cout << "Saldo: " << Banco1->getConta(numConta)->getSaldo() << std::endl;
  } else {
    std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
}
  Interface::Menu();
}

void Interface::ObterExtratoInicial(){
  int numConta;
  std::string Data;
  int day,month,year;
  std::cout << "Digite o numero da conta: ";
  std::cin >> numConta;
  std::cout << "Digite a Data inicial para obter o extrato( Formato: 'xx/xx/xxxx')" <<std::endl;
  std::cin >> Data;
  std::sscanf(Data.c_str(),"%d/%d/%d",&day,&month,&year);
  Date* Dinit = new Date(day,month,year);

  if(Banco1->ExisteConta(numConta)){
    for(int i = 0; i < Banco1->Extrato(numConta, *Dinit).size();i++){
      std::cout << "Data: " << Banco1->Extrato(numConta, *Dinit)[i].getDate().StringData()
                << " Tipo: " << Banco1->Extrato(numConta, *Dinit)[i].getDebitoCredito()
                << " Valor: " << Banco1->Extrato(numConta, *Dinit)[i].getValor()
                << " Descricao: " << Banco1->Extrato(numConta, *Dinit)[i].getDescricao() << std::endl;
    }
    std::cout << "Saldo: " << Banco1->getConta(numConta)->getSaldo() << std::endl;
  } else {
    std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
}
delete Dinit;
  Interface::Menu();
}

void Interface::ObterExtratoRange(){
  int numConta;
  std::string Data;
  int day,month,year;
  std::cout << "Digite o numero da conta: ";
  std::cin >> numConta;
  std::cout << "Digite a Data inicial para obter o extrato( Formato: 'xx/xx/xxxx')" <<std::endl;
  std::cin >> Data;
  std::sscanf(Data.c_str(),"%d/%d/%d",&day,&month,&year);
  std::cout << "DIAMESANOINICIAL = " << day << month << year <<std::endl;
  Date* Dinit = new Date(day,month,year);
  std::cout << "Digite a Data Final para obter o extrato( Formato: 'xx/xx/xxxx')" <<std::endl;
  std::cin >> Data;
  std::sscanf(Data.c_str(),"%d/%d/%d",&day,&month,&year);
  std::cout << "DIAMESANOFINAL = " << day << month << year <<std::endl;
  Date* Dfinal = new Date(day,month,year);

  if(Banco1->ExisteConta(numConta)){
    for(int i = 0; i < Banco1->Extrato(numConta, *Dinit, *Dfinal).size();i++){
      std::cout << "Data: " << Banco1->Extrato(numConta, *Dinit, *Dfinal)[i].getDate().StringData()
                << " Tipo: " << Banco1->Extrato(numConta, *Dinit, *Dfinal)[i].getDebitoCredito()
                << " Valor: " << Banco1->Extrato(numConta, *Dinit, *Dfinal)[i].getValor()
                << " Descricao: " << Banco1->Extrato(numConta, *Dinit, *Dfinal)[i].getDescricao() << std::endl;
    }
    std::cout << "Saldo: " << Banco1->getConta(numConta)->getSaldo() << std::endl;
  } else {
    std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
}
delete Dinit;
delete Dfinal;
  Interface::Menu();
}
