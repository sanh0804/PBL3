#include "nhanvien.h"

NHANVIEN::NHANVIEN(QString mnv, QString hvt, bool gt,Date day, QString dv, QString mcv ,QString sdt, QString gmail, QString dc)
{
    this->MaNhanVien = mnv;
    this->HoVaTen = hvt;
    this->NgaySinh = day;
    this->GioiTinh =gt;
    this->DonVi = dv;
    this->SoDienThoai =sdt;
    this->Gmail= gmail;
    this->DiaChi= dc;
    this->MaChucVu=mcv;
//    this->CV= new CHUCVU;
}
NHANVIEN::~NHANVIEN()
{

}
void NHANVIEN::addChucVu(CHUCVU* cv){
    this->cv=cv;
}

CHUCVU* NHANVIEN::getChucVu(){
    return cv;
}
QString NHANVIEN::getMaNhanVien()
{
    return this->MaNhanVien;
}
QString NHANVIEN::getHoVaTen()
{
    return this->HoVaTen;
}
Date NHANVIEN::getNgaySinh()
{
    return this->NgaySinh;
}
bool NHANVIEN::getGioiTinh()
{
    return this->GioiTinh;
}
QString NHANVIEN::getMaChucVu(){
    return this->MaChucVu;
}
QString NHANVIEN::getDonVi()
{
    return this->DonVi;
}
QString NHANVIEN::getSoDienThoai(){
    return this->SoDienThoai;
}
QString NHANVIEN::getGmail(){
    return this->Gmail;
}
QString NHANVIEN::getDiaChi(){
    return this->DiaChi;
}

void NHANVIEN::setMaNhanVien(QString mnv)
{
    this->MaNhanVien= mnv;
}
void NHANVIEN::setHoVaTen(QString hvt)
{
    this->HoVaTen = hvt;
}
void NHANVIEN::setNgaySinh(QString d)
{
    this->NgaySinh.setDate(d);
}
void NHANVIEN::setGioiTinh(bool gt)
{
    this->GioiTinh = gt;
}
void NHANVIEN::setMaChucVu(QString mcv){
    this->cv->setMaChucVu(mcv);
}
void NHANVIEN::setDonVi(QString dv){
    this->DonVi = dv;
}
void NHANVIEN::setSoDienThoai(QString sdt) {
    this->SoDienThoai = sdt;
}
void NHANVIEN::setGmail(QString gmail) {
    this->Gmail = gmail;
}
void NHANVIEN::setDiaChi(QString dc){
    this->DiaChi= dc;
}

void NHANVIEN::setChucVu(CHUCVU *cv){
    this->cv = cv;
}
