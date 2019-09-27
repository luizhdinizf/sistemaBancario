#include <bits/stdc++.h>
#include <ctime>
#include <vector>

#include "Date.cpp"
#include "Cliente.cpp"
#include "Movimentacao.cpp"
#include "Conta.cpp"
#include "Banco.cpp"
using namespace std;



// class Interface{
// private:
//   Banco Banco1;
//   static int counter;
//
// public:
//   Interface(Banco &b){
//     counter++;
//     Banco1 = b;
//   }
//   void Menu(){
//     int selecao;
//     cout << endl << endl << endl << endl << "---=== Banco " << Banco1.getNome() << "===---" << endl
//          << "Selecione a opçao desejada: " << endl
//          << "1. Cadastrar novo Cliente" << endl // implementado
//          << "2. Cadastrar nova conta" << endl
//          << "3. Excluir Cliente" << endl
//          << "16. Mostrar Clientes" << endl
//          << "17. Mostrar Contas" << endl
//          << "Opcao Escolhida: ";
//     cin >> selecao;
//     switch(selecao){
//       case(1):
//         CadastrarCliente();
//         break;
//       case(2):
//         CadastrarConta();
//         break;
//       case(3):
//         ExcluirCliente();
//         break;
//       case(16):
//         MostrarClientes();
//         Menu();
//         break;
//       case(17):
//         MostrarContas();
//         Menu();
//         break;
//     }
//   }
//   void CadastrarCliente(){
//     string nomeCliente,cpf_cnpj,endereco,fone;
//     char confirmacao;
//
//
//
//     cout << "Nome do cliente: ";
//     cin.ignore();
//     getline(cin, nomeCliente); // Usa-se essa funcao para permitir espacos
//     cout << "CPF ou CNPJ: " ;
//     cin >> cpf_cnpj;
//     cout << "Endereco: " ;
//     cin.ignore();
//     getline(cin, endereco); // Usa-se essa funcao para permitir espacos
//     cout << "fone: "  ;
//     cin >> fone;
//     // cout << "Cliente Cadastrado" <<endl;
//     // cout << "Nome: " << Banco1.getClientes().back().getNome() << endl
//     //      << "Endereco: " << Banco1.getClientes().back().getEndereco() << endl
//     //      << "Fone: " << Banco1.getClientes().back().getFone() << endl;
//     cout << "Deseja confirmar o cadastro?[S/N]: ";
//     cin  >> confirmacao;
//     if(confirmacao == 'S'){
//
//       Banco1.NovoCliente(Cliente(nomeCliente,cpf_cnpj,endereco,fone));
//       cout << "Cliente "<< Banco1.getClientes().back().getNome() <<" Cadastrado" << endl;
//     } else if (confirmacao == 'N') {
//       cout << "Cliente removido" << endl;
//       Banco1.getClientes().pop_back();
//       cout << Banco1.getClientes().size() << endl;
//     }
//     Menu();
//   }
//   void MostrarClientes(){
//     for(int i = 0;i < Banco1.getClientes().size(); i++){
//       cout << i << ". " << Banco1.getClientes()[i].getNome() << endl;
//     }
//   }
//   void MostrarContas(){
//     for(int i = 0;i < Banco1.getContas().size(); i++){
//       cout << i << "." << Banco1.getContas()[i]->getCliente()->getNome() << " - Número da conta: " << Banco1.getContas()[i].getNumConta() << endl;
//     }
//     Banco1.getContas()[0].getCliente()->setNome("LALALOLO");
//   }
//   void CadastrarConta(){
//     int numCliente;
//     cout << "Escolha o Cliente do qual a conta será criada." << endl;
//     MostrarClientes();
//     cin >> numCliente;
//     Banco1.NovaConta(Banco1.getClientes()[numCliente]);
//     cout << "Conta do cliente " << Banco1.getContas()[numCliente]->getCliente()->getNome() << " criada" << endl;
//
//     Menu();
//   }
//   void ExcluirCliente(){
//     string cpf;
//     int indexCliente;
//     char confirmacao;
//     cout << "Digite o cpf/CNPJ do cliente a ser excluido " << endl;
//     cin >> cpf;
//     cout << "Cliente " << Banco1.RemoverCliente(cpf) << " removido" << endl;
//
//
//     MostrarClientes();
//     Menu();
//
//   }
//
//
//
// };

int Conta::counter = 0; // inicializa valor static
// int Interface::counter = 0; // inicializa valor static
int main() {
  // ---===TESTE BANCO ===---
  Cliente * cliente1 = new Cliente("João","54321","Rua X, n 43","23123131");
  Cliente * cliente2 = new Cliente("Pedro","12345","Rua X, n 43","23123131");
  //std::cout<< "Hello World" <<std::endl;
  Banco * Banco1 = new Banco("Bradesco");
  cout << Banco1->getNome() << endl; 
  

  Banco1->NovoCliente(cliente1);
  Banco1->NovoCliente(cliente2);
  Banco1->NovaConta(cliente1);
  Banco1->NovaConta(cliente2);
  Date * DataHoje= new Date();  
  DataHoje->SetToday();

  //Conta * conta1 = new Conta(cliente1);
  Conta * conta1 = Banco1->getContas()[0];
  conta1->CreditarValor(50.0,"salario");
  cout << Banco1->getClientes().back()->getNome()<< endl;
  conta1->CreditarValor(50.0,"salario");
  conta1->DebitarValor(20.0,"gasto");  
  Date * dataInicial = new Date(2,9,2019);
  Date * dataFinal = new Date(2,10,2019);
  std::vector<Movimentacao> mov = conta1->Extrato(*dataInicial,*dataFinal);
  Banco1->DepositarConta(0,20,*DataHoje);
  Banco1->TransferirDePara(0,1,20,*DataHoje);
  Banco1->CobrarTarifa(*DataHoje);
  double saldo = Banco1->ObterSaldo(0);
  std::vector<Movimentacao> mov1 = Banco1->Extrato(0,*dataInicial);
  std::vector<Movimentacao> mov2 = Banco1->Extrato(0,*dataInicial,*dataFinal);
  std::vector<Movimentacao> mov3 = Banco1->ExtratoMensal(0);
  std::vector<Cliente*> clientes =Banco1->getClientes();
  std::vector<Conta*> contas = Banco1->getContas();
  /*
  conta1->DebitarValor(20.0,"Casa",data1);
  conta1->DebitarValor(10.0,"Casa",data1);  
  cout << conta1->getSaldo() << endl;

  cout << Banco1->getClientes().back()->getNome() <<endl;


  cout << Banco1->getContas()[0]->getNumConta() << endl;
  cout << "Cliente " << Banco1->RemoverCliente("123321") << " Removido"<< endl;
  cout << "Conta do cliente " << Banco1->RemoverConta(2) << " Removida"<< endl;
  */
 /*


  
// ---===TESTE INTERFACE ===---
// Banco Banco2("Bradesco");
// Interface teste(Banco2);
// teste.Menu();

// cout << conta1->NomeCliente();
// Date das;
// conta1.CreditarValor(50, "salario",das);
// conta1.DebitarValor(20, "Casa",04,04,2015);
// conta1.DebitarValor(10, "Casa",05,05,2017);
// cout << conta1.getSaldo() << endl;
//
// cout << conta1.Extrato()[1].getValor() << endl;
// cout << conta1.Extrato()[2].getValor() << endl;
//
// Date Data1(01,01,2010);
// Date Data2(01,01,2020);
// Date DataHoje;
// DataHoje.SetToday();
// cout << "DIA: " << DataHoje.getDay() << " MES: "<< DataHoje.getMonth() << " ANO: " << DataHoje.getYear() << endl;
//
// cout << conta1.Extrato(Data1,Data2)[0].NumInterno() << endl;
//
//
//
// cout << conta1.Extrato()[1].getDate().NumInterno() << endl;

// conta1.DebitarValor(40, "mochila");
// conta1.printExtrato();
// Conta conta2;
// Conta conta3;
// Conta conta4;
// Conta conta5;
// Conta conta6;
// Conta conta7;

//
// cout << conta1.getSaldo() << endl;


// cout << conta6.getNumConta() << endl;

    // // Declare an object of class geeks
    // Geeks obj1;
    //
    // // accessing data member
    // obj1.geekname = "Abhi";
    //
    // // accessing member function
    // obj1.printname();
    */
    return 0;
}
