
#ifndef THUCLINH_H
#define THUCLINH_H

#include <QString>

#include "phucap.h"
#include "luong.h"


class THUCLINH
 {
protected:
    QString MPC;
    QString MaLuong;
    QString MaChucVu;
//    float ThucLinh;
//    float Phucap;
    PHUCAP* PC;
    LUONG* L;
public:
//    THUCLINH();
    THUCLINH(QString ="", QString ="", QString ="");        // truyền vào 2 đối tượng luong vs phu cap
    ~THUCLINH();
    QString getMaChucVu();
    QString getMaLuong();
    QString getMaPhuCap();
    void addLuong(LUONG* );
    void addPhuCap(PHUCAP* );
    LUONG* getLuong();
    PHUCAP* getPhuCap();
    float getPhucap();
    float getThuclinh();
};


#endif // THUCLINH_H
