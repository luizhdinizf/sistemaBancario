#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime> //http://www.cplusplus.com/reference/ctime/tm/ ATENTAR AOS NUMEROS PADRAO


class Date{
private:
  int day;
  int month;
  int year;
public:
  Date();
  Date(int d, int m, int y);
  ~Date();
  void SetToday();
  void VoltarSemana(Date* Dinit);
  int NumInterno();
  bool operator==(const Date& d1);
  bool InRange(Date& Dinit, Date& Dfinal);
  int getDay();
  int getMonth();
  int getYear();
  void SetDate(int d, int m, int y);
  std::string StringData();
};

#endif
