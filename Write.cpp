#include <bits/stdc++.h>
using namespace std;



string data = ";;3/10/2019;Transferência PARA conta número 2;D;50";
int dia,mes,ano;
double valor;
char dc;
char descricao[100];






int main(){


sscanf(data.c_str(),";;%d/%d/%d;%[^;];%c;%lf",&dia,&mes,&ano,descricao,&dc, &valor);
cout << dia << mes << ano << descricao << "DC: " << dc << " VALOR: " <<valor;

  return 0;
}
