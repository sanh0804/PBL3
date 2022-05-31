
#ifndef LUONG_H
#define LUONG_H

#include <QString>
#include <iostream>
using namespace std;

class LUONG
{
private:
    QString MaLuong;
    float Luong;
    float LCB;
    float HSL;
public:
    LUONG(QString = " "  , float =0  , float=0 );           //truyền vào mã Lương , Lương cơ bản , Hệ số lương
    ~LUONG();
    QString getMaLuong();
    float getLCB();
    float getHSL();
    void setML(QString);
    void setLCB(float);
    void setHSL(float);
    float getLuong(); // tính lương của 1 đối tượng

};
#endif // LUONG_H
