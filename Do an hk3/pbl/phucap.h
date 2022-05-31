#ifndef PHUCAP_H
#define PHUCAP_H

#include <QString>
#include <iostream>
using namespace std;


class PHUCAP
{
protected:
    QString MPC;
    float HSPC;
public:
//    PHUCAP();
    PHUCAP(QString = " ", float = 1 );        // truyền vào 2 tham số "mã phụ cấp" và "HSCP"
    ~PHUCAP();

    QString getMPC();
    float getHSPC();
    void setMPC(QString);
    void setHSPC(float);
};

#endif // PHUCAP_H
