
#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <QString>
#include <iostream>
#include "chucvu.h"
#include "date.h"
using namespace std;

class NHANVIEN {
private:
    QString MaNhanVien;
    QString HoVaTen;
    Date NgaySinh;
    bool GioiTinh;
    QString MaChucVu;
    QString DonVi;
    QString SoDienThoai;
    QString Gmail;
    QString DiaChi;
    CHUCVU* cv;
public:
    NHANVIEN(QString = "",QString = "", bool = 1,Date = Date(), QString = "", QString ="", QString = "", QString = "", QString = "");
    ~NHANVIEN();

    void addChucVu(CHUCVU*);
    QString getMaNhanVien();
    QString getHoVaTen();
    Date getNgaySinh();
    bool getGioiTinh();
    QString getMaChucVu();
    QString getDonVi();
    QString getSoDienThoai();
    QString getGmail();
    QString getDiaChi();
    CHUCVU* getChucVu();
    void setMaNhanVien(QString);
    void setHoVaTen(QString);
    void setNgaySinh(QString );
    void setGioiTinh(bool);
    void setMaChucVu(QString);
    void setDonVi(QString);
    void setSoDienThoai(QString);
    void setGmail(QString);
    void setDiaChi(QString);
    void setChucVu(CHUCVU* cv);


};

#endif // NHANVIEN_H
