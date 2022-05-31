#include "luong.h"
LUONG::LUONG(QString ml  , float lcb , float hsl )      //truyền vào mã Lương , Lương cơ bản , Hệ số lương
    :MaLuong(ml)
{
    this-> LCB= lcb;
    this-> HSL= hsl;
    this-> Luong = lcb*hsl;
}
LUONG::~LUONG()
{

}


QString LUONG::getMaLuong()
{
    return this->MaLuong;
}

float LUONG::getLCB()
{
    return this->LCB;
}
float LUONG::getHSL()
{
    return this->HSL;
}

void LUONG::setML(QString ml)
{
    this->MaLuong = ml;
}
void LUONG::setLCB(float lcb)
{
    this->LCB = lcb;
}
void LUONG::setHSL(float hsl)
{
    this->HSL = hsl;
}
float LUONG::getLuong()
{
    return this->Luong = this->LCB * this->HSL;
}
