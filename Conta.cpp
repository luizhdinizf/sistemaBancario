#include "Conta.h"

Conta::Conta(Cliente* c){
  saldo = 0;
  counter++;
  numConta = counter;
  cliente = c;

}
void Conta::DebitarValor(double valor,std::string desc,Date d){
  if (saldo - valor >= 0){
    saldo = saldo - valor;
    movimentacoes.push_back(Movimentacao(d,desc,'D', valor));
  }
}
void Conta::CreditarValor(double valor,std::string desc,Date d){
  saldo = saldo + valor;
  movimentacoes.push_back(Movimentacao(d,desc,'C', valor));


}
std::vector<Movimentacao> &Conta::Extrato(){
  return movimentacoes; // Retorna o vector com todas as movimentacoes
}
std::vector<Movimentacao> Conta::Extrato(Date DataInit, Date DataFinal){
  std::vector<Movimentacao> ExtratoVector;
  // cout << "TAMANHO VECTOR: " << movimentacoes.size() << endl;
  for (int i = 0; i < movimentacoes.size();i++){
    if (movimentacoes[i].getDate().InRange(DataInit,DataFinal)){ // Se a "linha" do vector, estiver dentro da range data, copiar essa "Linha" para um novo vector
      ExtratoVector.push_back(movimentacoes[i]);
    }
  }
  return ExtratoVector;
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