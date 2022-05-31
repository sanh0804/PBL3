#include "chucvu.h"


CHUCVU::CHUCVU(QString mcv, QString cv)
    :MaChucVu(mcv), ChucVu(cv)
{
    TL= new THUCLINH;
}
CHUCVU::~CHUCVU(){

}

QString CHUCVU::getMaChucVu()
{
    return this->MaChucVu;
}
void CHUCVU::setMaChucVu(QString mcv)
{
    this->MaChucVu = mcv;
}
QString CHUCVU::getChucVu()
{
    return this->ChucVu;
}
void CHUCVU::setChucVu(QString cv)
{
    this->ChucVu = cv;
}
THUCLINH* CHUCVU::getThucLinh(){
    return this->TL;
}
void CHUCVU::addThucLinh(THUCLINH* tl){
    this->TL = tl;
}
