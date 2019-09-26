#include "date.h"


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
void Date::SetToday(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = ltm->tm_mon + 1; // Obs.: Mes Janeiro = 0
    year = ltm->tm_year + 1900; // Obs.: Comeca a contagem a partir de 1900

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
