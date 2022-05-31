
#ifndef CHUCVU_H
#define CHUCVU_H

#include <QString>
#include <iostream>
#include "thuclinh.h"
using namespace std;

class CHUCVU {
    private:
    QString MaChucVu;
    QString ChucVu;
    THUCLINH* TL;
public:
    // tạo chức vụ -> truyền vào thực lĩnh, mã chức vụ và chức vụ
    CHUCVU(QString = " ", QString = " ");
    ~CHUCVU();

    QString getMaChucVu();
    QString getChucVu();
    THUCLINH* getThucLinh();
    void setMaChucVu(QString);
    void setChucVu(QString);
    void addThucLinh(THUCLINH* );
};

#endif // CHUCVU_H
