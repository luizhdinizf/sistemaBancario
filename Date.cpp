#include "Date.h"


Date::Date(){
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d,int m,int y){
  this-> day = d;
  this-> month = m;
  this-> year = y;
}

Date::~Date(){}

void Date::SetToday(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = ltm->tm_mon + 1; // Obs.: Mes Janeiro = 0
    year = ltm->tm_year + 1900; // Obs.: Comeca a contagem a partir de 1900

}
void Date::VoltarSemana(Date* Dinit){ // cria uma data com 7 dias atras da data marcada
  int rSub; // Resultado Subtracao
  if(Dinit->getDay() <= 7){
    rSub = abs(Dinit->getDay() - 7); // Pega o modulo da subtracao para diminuir de 31,30 ou 28 dias
    if( (Dinit->getMonth() == 2) || (Dinit->getMonth() == 4) || (Dinit->getMonth() == 6) || (Dinit->getMonth() == 9) || (Dinit->getMonth() == 11)){ // meses anteriores com 31 dias
      day = 31-rSub;
      month = Dinit->getMonth()-1;
      year = Dinit->getYear();
      return;
    }

    else if( (Dinit->getMonth() == 5) || (Dinit->getMonth() == 7) || (Dinit->getMonth() == 8) || (Dinit->getMonth() == 10) || (Dinit->getMonth() == 2) ){ // meses com 30 dias
      day = 30-rSub;
      month = Dinit->getMonth()-1;
      year = Dinit->getYear();
      return;
    }
    else if (Dinit->getMonth() == 3){ // Fevereiro - considerar 28 dias
      day = 28-rSub;
      month = Dinit->getMonth()-1;
      year = Dinit->getYear();
      return;
    }
    else if ((Dinit->getMonth() == 1)){ // Janeiro - 31 dias porem tem que voltar 1 ano e setar o mes para 12
      day = 31-rSub;
      month = 12;
      year = Dinit->getYear()-1;
      return;
    }
  } else{
    day = Dinit->getDay()-rSub;
    month = Dinit->getMonth();
    year = Dinit->getYear();
    return;
  }
}

int Date::NumInterno(){
  int temp;
  temp = (year * 10000) + (month * 100) + day;
  return temp;
}
bool Date::operator==(const Date& d1){
  if( (d1.day == day) && (d1.month == month) && (d1.year == year)){
    return true;
  } else{
    return false;
  }
}
bool Date::InRange(Date& Dinit, Date& Dfinal){
  if ( (NumInterno() >= Dinit.NumInterno()) && (NumInterno() <= Dfinal.NumInterno()) ) {
    return true;
  } else {
    return false;
  }
}

int Date::getDay(){
  return day;
}
int Date::getMonth(){
  return month;
}
int Date::getYear(){
  return year;
}
void Date::SetDate(int d, int m, int y){
  day = d;
  month = m;
  year = y;
}
std::string Date::StringData(){
  std::string dataString = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
  return dataString;
}
