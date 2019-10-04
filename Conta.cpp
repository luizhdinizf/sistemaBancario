#include "Conta.h"

Conta::Conta(Cliente* c){
  saldo = 0;
  counter++;
  numConta = counter;
  cliente = c;
}

Conta::Conta(Cliente* c,int nC){
  saldo = 0;
  counter++;
  this->numConta = nC;
  cliente = c;
}

Conta::~Conta(){}

void Conta::CreditarValor(double valor,std::string desc){
  Date * data1 = new Date();
  data1->SetToday();
  saldo = saldo + valor;
  movimentacoes.push_back(Movimentacao(*data1,desc,'C', valor));
}
void Conta::CreditarValor(double valor,std::string desc,Date d){
  saldo = saldo + valor;
  movimentacoes.push_back(Movimentacao(d,desc,'C', valor));
}

void Conta::DebitarValor(double valor,std::string desc){
  Date * data1 = new Date();
  data1->SetToday();
  if (saldo - valor >= 0){
    saldo = saldo - valor;
    movimentacoes.push_back(Movimentacao(*data1,desc,'D', valor));
  }
}


void Conta::DebitarValor(double valor,std::string desc,Date d){
  if (saldo - valor >= 0){
    saldo = saldo - valor;
    movimentacoes.push_back(Movimentacao(d,desc,'D', valor));
  }
}
void Conta::DebitarValorTarifa(double valor,std::string desc,Date d){ // Excecao,
  saldo = saldo - valor; // tarifa pode ficar com saldo negativo
  movimentacoes.push_back(Movimentacao(d,desc,'D', valor));
}

std::vector<Movimentacao> &Conta::Extrato(){
  return movimentacoes; // Retorna o vector com todas as movimentacoes
}

std::vector<Movimentacao> Conta::Extrato(Date DataInit, Date DataFinal){
  std::vector<Movimentacao> ExtratoVector;
  for (int i = 0; i < movimentacoes.size();i++){
    if (movimentacoes[i].getDate().InRange(DataInit,DataFinal)){ // Se a "linha" do vector, estiver dentro da range data, copiar essa "Linha" para um novo vector
      ExtratoVector.push_back(movimentacoes[i]);
    }
  }
  return ExtratoVector;
}
std::vector<Movimentacao> Conta::Extrato(Date DataInit){
  Date * DataFinal= new Date();
  DataFinal->SetToday();
  std::vector<Movimentacao> ExtratoVector;
  // cout << "TAMANHO VECTOR: " << movimentacoes.size() << endl;
  for (int i = 0; i < movimentacoes.size();i++){
    if (movimentacoes[i].getDate().InRange(DataInit,*DataFinal)){ // Se a "linha" do vector, estiver dentro da range data, copiar essa "Linha" para um novo vector
      ExtratoVector.push_back(movimentacoes[i]);
    }
  }
  return ExtratoVector;
}

std::vector<Movimentacao> Conta::ExtratoMensal(){
  Date * DataHoje= new Date();
  DataHoje->SetToday();
  Date * DataInit= new Date(1,DataHoje->getMonth(),DataHoje->getYear());
  std::vector<Movimentacao> ExtratoVector;
  for (int i = 0; i < movimentacoes.size();i++){
    if (movimentacoes[i].getDate().InRange(*DataInit,*DataHoje)){ // Se a "linha" do vector, estiver dentro da range data, copiar essa "Linha" para um novo vector
      ExtratoVector.push_back(movimentacoes[i]);
    }
  }
  // std::cout << "DEPURACAO, ANTES DO RETURN" << std::endl;
  return ExtratoVector;
}




void Conta::setNumConta(int nC){
  this->numConta = nC;
}
int Conta::getNumConta(){
  return numConta;
}
double Conta::getSaldo(){
  return saldo;
}
Cliente *Conta::getCliente(){
  return cliente;
}
std::string Conta::NomeCliente(){
  return cliente->getNome();
}
