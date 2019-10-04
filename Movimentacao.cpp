#include "Movimentacao.h"

Movimentacao::Movimentacao(Date date, std::string d, char dC, double v){
  this-> dataMov = date;
  this-> descricao = d;
  this-> debitoCredito = dC;
  this-> valor = v;
}

Movimentacao::~Movimentacao(){}

void Movimentacao::setdataMov(int d, int m,int y){
  this->dataMov.SetDate(d,m,y);
}

void Movimentacao::setDescricao(std::string desc){
  descricao = desc;
}

void Movimentacao::setDebitoCredito(char debCred){
  debitoCredito = debCred;
}

void Movimentacao::setValor(double value){
  valor = value;
}

std::string Movimentacao::getDescricao(){
  return descricao;
}

char Movimentacao::getDebitoCredito(){
  return debitoCredito;
}

double Movimentacao::getValor(){
  return valor;
}

Date Movimentacao::getDate(){
  return dataMov;
}
