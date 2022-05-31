#include "thuclinh.h"


//THUCLINH::THUCLINH(){

//}
THUCLINH::THUCLINH(QString mpc, QString ml, QString mcv)
    : MPC(mpc), MaLuong(ml), MaChucVu(mcv)
{
        this->PC = new PHUCAP;
        this->L = new LUONG;
}
THUCLINH::~THUCLINH()
{

}
QString THUCLINH::getMaLuong(){
    return this->MaLuong;
}
QString THUCLINH::getMaPhuCap(){
    return this->MPC;
}
float THUCLINH::getPhucap(){
    return this->PC->getHSPC()* this->L->getLuong();
}
//LUONG THUCLINH::getLuong(){
//    return this->L;
//}
float THUCLINH::getThuclinh()
{
    return this->PC->getHSPC()* this->L->getLuong() + this->L->getLuong();
}
QString THUCLINH::getMaChucVu(){
    return this->MaChucVu;
}
LUONG* THUCLINH::getLuong(){
    return this->L;
}
void THUCLINH::addLuong(LUONG* l){
    this->L= l;
}
void THUCLINH::addPhuCap(PHUCAP* pc){
    this->PC= pc;
}


