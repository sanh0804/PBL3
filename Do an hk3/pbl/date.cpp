#include "date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date(){

}

QString Date::getDay(){
    return QString::number(this->day);
}

QString Date::getMonth(){
    return QString::number(this->month);
}

QString Date::getYear(){
    return QString::number(this->year);
}

void Date::setDay(int day){
    this->day = day;
}

void Date::setMonth(int month){
    this->month = month;
}

void Date::setYear(int year){
    this->year = year;
}
void Date::setDate(QString d){

        QStringList tmp = d.split('-');
        this->day = tmp[0].toInt();
        this->month = tmp[1].toInt();
        this->year = tmp[2].toInt();

}
QString Date::getDate(){

   return this->getDay() + "-" + this->getMonth() +"-"+ this->getYear();
}

