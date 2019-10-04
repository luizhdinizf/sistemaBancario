// #include <bits/stdc++.h>
// #include <ctime>
// #include <vector>
// using namespace std;


#ifndef CLIENTE_H
#define CLIENTE_H
#include <bits/stdc++.h>


class Cliente {
private:
  std::string nomeCliente;
  std::string cpf_cnpj;
  std::string endereco;
  std::string fone;

    // Access specifier
    public:
      Cliente();
      Cliente(std::string n, std::string c, std::string e, std::string f);
      ~Cliente(); // Destrutor Cliente
      std::string getNome();
      std::string getCpf_cnpj();
      std::string getEndereco();
      std::string getFone();
      void setNome(std::string input);
      void setCpf_cnpj(std::string input);
      void setEndereco(std::string input);
      void setFone(std::string input);
};

#endif
