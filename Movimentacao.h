#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H
#include <iostream>
#include "Date.h"


class Movimentacao
{
private:
  Date dataMov;
  std::string descricao;
  char debitoCredito;
  double valor;
public:
  Movimentacao(Date date, std::string d, char dC, double v);
  ~Movimentacao();
  void setdataMov(int d, int m,int y);
  void setDescricao(std::string desc);
  void setDebitoCredito(char debCred);
  void setValor(double value);
  std::string getDescricao();
  char getDebitoCredito();
  double getValor();
  Date getDate();
};
#endif
