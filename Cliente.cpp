#include "Cliente.h"

Cliente::Cliente(){
  nomeCliente = "";
  cpf_cnpj = "";
  endereco = "";
  fone = "";
}
Cliente::Cliente(std::string n, std::string c, std::string e, std::string f){
  // std::cout << "Construtor chamado" << std::endl;
  this ->nomeCliente = n;
  this ->cpf_cnpj = c;
  this ->endereco = e;
  this ->fone = f;
}
Cliente::~Cliente(){}

std::string Cliente::getNome(){
  return nomeCliente;
}
std::string Cliente::getCpf_cnpj(){
  return cpf_cnpj;
}
std::string Cliente::getEndereco(){
  return endereco;
}
std::string Cliente::getFone(){
  return fone;
}

void Cliente::setNome(std::string input){
  nomeCliente = input;
}
void Cliente::setCpf_cnpj(std::string input){
  cpf_cnpj = input;
}
void Cliente::setEndereco(std::string input){
  endereco = input;
}
void Cliente::setFone(std::string input){
  fone = input;
}
