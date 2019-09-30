#include "Interface.h"

  Interface::Interface(Banco *b){
    counter++;
    Banco1 = b;
  }
  void Interface::Menu(){
    int selecao;
    std::cout << std::endl << std::endl << std::endl << std::endl << "---=== Banco " << Banco1->getNome() << "===---" << std::endl
         << "Selecione a opçao desejada: " << std::endl
         << "1. Cadastrar novo Cliente" << std::endl // implementado
         << "2. Cadastrar nova conta" << std::endl
         << "3. Excluir Cliente" << std::endl
         << "4. Excluir Conta" << std::endl
         << "16. Mostrar Clientes" << std::endl
         << "17. Mostrar Contas" << std::endl
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
      case(16):
        Interface::MostrarClientes();
        Interface::Menu();
        break;
      case(17):
        Interface::MostrarContas();
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
      std::cout << i + 1 << "." << Banco1->getContas()[i]->getCliente()->getNome()  << std::endl;
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
      Banco1->NovaConta(Banco1->getClientes()[numCliente]);
      std::cout << "Conta do cliente " << Banco1->getContas()[numCliente]->getCliente()->getNome() << " criada" << std::endl;
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

    if( (numConta > Banco1->getContas().size() ) || (numConta < 0)    ){
      std::cout << "Nº de conta informado não esta cadastrado na nossa base de dados, por favor insira um numero de conta válido." << std::endl;
      // ExcluirCliente(); // Fica em um loop infinito caso nao tenha nenhum cliente, melhor voltar ao menu
      Interface::Menu();
    } else {
      nomeConta = Banco1->getContas()[numConta-1]->getCliente()->getNome();
      std::cout << "Deseja remover a conta " << numConta << " do cliente " << nomeConta << "?[S/N]" << std::endl;
      std::cin >> confirmacao;
      if(confirmacao == 'S'){
        std::cout << "Conta " << Banco1->RemoverConta(numConta) << " removido" << std::endl;
      } else {
        std::cout << "Voltando ao menu..." << std::endl;
      }
    }
    Interface::Menu();

  }
