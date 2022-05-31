#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// tên và icon app
    this->setWindowTitle("Employee management");
    this->setWindowIcon(QIcon("C:/Users/sanhg/OneDrive/Documents/pbl/img/app_icon.png"));
// tắt mimize
    setWindowFlags(windowFlags() &(~Qt::WindowMaximizeButtonHint));
// kết nối database
    myDB = QSqlDatabase::addDatabase("QODBC");
    QString connectString = "Driver={SQL Server Native Client 11.0};";
    connectString.append("Server=DESKTOP-F5NCIAK;");
    connectString.append("Database=doan;");
    connectString.append("Trusted_connection=yes;");
    myDB.setDatabaseName(connectString);
    if(myDB.open()){
        qDebug()<<"KẾT NỐI THÀNH CÔNG DATABASE";
    }
    else
        qDebug()<<"false";
    QSqlQuery q(myDB);
// truy vấn dữ liệu lên Luong
    q.exec("select MaLuong,Luong.LuongCoBan,Luong.HeSoLuong from Luong");
    while(q.next())
    {
        listluong.push_back(new LUONG(q.value(0).toString(), q.value(1).toFloat(), q.value(2).toFloat()));
    }
// truy vấn dữ liệu lên PhuCap
    q.exec("select * from PhuCap ");
    while(q.next())
    {
        listphucap.push_back(new PHUCAP(q.value(0).toString(), q.value(1).toFloat()));
    }
// truy vấn dữ liệu lên ThucLinh
    q.exec("select MaPhuCap, MaLuong, MaChucVu from ThucLinh");
    while(q.next())
    {
        listthuclinh.push_back(new THUCLINH(q.value(0).toString(), q.value(1).toString(), q.value(2).toString()));
    }
        for(int i=0; i<int (listthuclinh.size()); i++){
            for(int j=0; j< int (listphucap.size()); j++){
                if(listthuclinh[i]->getMaPhuCap()==listphucap[j]->getMPC())
                    listthuclinh[i]->addPhuCap(listphucap[j]);
            }
            for(int j=0; j< int (listluong.size()); j++){
                if(listthuclinh[i]->getMaLuong()==listluong[j]->getMaLuong())
                    listthuclinh[i]->addLuong(listluong[j]);
            }
        }
// truy vấn dữ liệu lên ChucVu
    q.exec("select MaChucVu, ChucVu from ChucVu");
    while(q.next())
    {
        listchucvu.push_back(new CHUCVU(q.value(0).toString(), q.value(1).toString()));
    }
    for(int i=0; i< int(listchucvu.size()); i++){
        for(int j=0; j< int(listthuclinh.size()); j++){
            if(listchucvu[i]->getMaChucVu()==listthuclinh[j]->getMaChucVu())
                listchucvu[i]->addThucLinh(listthuclinh[j]);
        }
    }

// truy vấn dữ liệu lên NhanVien
    q.exec("select MaNhanVien, HoVaTen, GioiTinh, day(NgaySinh), month(NgaySinh), year(NgaySinh), DonVi, MaChucVu, SoDienThoai, Gmail, DiaChi from NhanVien ");
    while(q.next())
    {
        listnv.push_back(new NHANVIEN(q.value(0).toString(), q.value(1).toString(), q.value(2).toBool(),Date(q.value(3).toInt(),q.value(4).toInt(), q.value(5).toInt()), q.value(6).toString(), q.value(7).toString(),q.value(8).toString(),q.value(9).toString(),q.value(10).toString()));
    }
    for(int i = 0; i < (int)listnv.size(); i++)
        {
            for(int j=0; j< int(listchucvu.size()); j++){
                if(listnv[i]->getMaChucVu()==listchucvu[j]->getMaChucVu())
                    listnv[i]->addChucVu(listchucvu[j]);
            }
        }


//trang đầu
    ui->main_page->setCurrentIndex(0);

//background home;
    QPixmap pixhome("C:/Users/sanhg/OneDrive/Documents/pbl/img/homepage");
    int w=ui->homepage->width();
    int h=ui->homepage->height();
    ui->homepage->setPixmap(pixhome.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));

// background thông tin nhân viên
    QPixmap pixinf("C:/Users/sanhg/OneDrive/Documents/pbl/img/background");
    int i=ui->background->width();
    int j=ui->background->height();
    ui->background->setPixmap(pixinf.scaled(i,j,Qt::KeepAspectRatio,Qt::SmoothTransformation));
// background xóa nhân viên
    QPixmap pixinf2("C:/Users/sanhg/OneDrive/Documents/pbl/img/background");
    int m=ui->background_3->width();
    int n=ui->background_3->height();
    ui->background_3->setPixmap(pixinf2.scaled(m,n,Qt::KeepAspectRatio,Qt::SmoothTransformation));

// background thêm thông tin nhân viên
    QPixmap pixadd("C:/Users/sanhg/OneDrive/Documents/pbl/img/background");
    int k=ui->background_2->width();
    int l=ui->background_2->height();
    ui->background_2->setPixmap(pixadd.scaled(k,l,Qt::KeepAspectRatio,Qt::SmoothTransformation));

// độ dài các cột trong list
    for(int i = 0; i < 9; i ++){
        ui->listStaff->setColumnWidth(i, ui->listStaff->width()/9);
    }

// độ dài các cột trong remove
    for(int i = 0; i < 9; i ++){
        ui->listStaff_2->setColumnWidth(i, ui->listStaff_2->width()/9);
    }
// độ dài các cột trong satistic
    for(int i = 0; i < 9; i ++){
        ui->statistic_table->setColumnWidth(i, ui->statistic_table->width()/4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Đưa dữ liệu lên list
    void MainWindow::addDataToListStaff(){
            int row = ui->listStaff->rowCount();
                while(row)
                {
                    ui->listStaff->removeRow(row - 1);
                    row--;
                }  
                qDebug() << listnv.size();
            for(int i = 0; i < int(listnv.size()); i++){
                ui->listStaff->insertRow(row);
                ui->listStaff->setItem(row, 0, new QTableWidgetItem(listnv[i]->getMaNhanVien()));
                ui->listStaff->setItem(row, 1, new QTableWidgetItem(listnv[i]->getHoVaTen()));
                ui->listStaff->setItem(row, 2, new QTableWidgetItem(listnv[i]->getNgaySinh().getDate()));
                if(listnv[i]->getGioiTinh()){
                    ui->listStaff->setItem(row, 3, new QTableWidgetItem("Nam"));
                 } else
                    ui->listStaff->setItem(row, 3, new QTableWidgetItem("Nữ"));
                ui->listStaff->setItem(row, 4, new QTableWidgetItem(listnv[i]->getDonVi()));
                ui->listStaff->setItem(row, 5, new QTableWidgetItem(listnv[i]->getChucVu()->getChucVu()));
                ui->listStaff->setItem(row, 6, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getLuong()->getLuong())));
                ui->listStaff->setItem(row, 7, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getPhucap())));
                ui->listStaff->setItem(row, 8, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getThuclinh())));
                row ++;
            }
    }

//Đưa dữ liệu lên remove
    void MainWindow::addDataToRemoveStaff(){
        QSqlQuery query(myDB);
            int row = ui->listStaff_2->rowCount();
                while(row)
                {
                    ui->listStaff_2->removeRow(row - 1);
                    row--;
                }
            for(int i = 0; i < int(listnv.size()); i++){
                ui->listStaff_2->insertRow(row);
                ui->listStaff_2->setItem(row, 0, new QTableWidgetItem(listnv[i]->getMaNhanVien()));
                ui->listStaff_2->setItem(row, 1, new QTableWidgetItem(listnv[i]->getHoVaTen()));
                ui->listStaff_2->setItem(row, 2, new QTableWidgetItem(listnv[i]->getNgaySinh().getDate()));
                if(listnv[i]->getGioiTinh()){
                    ui->listStaff_2->setItem(row, 3, new QTableWidgetItem("Nam"));
                 } else
                    ui->listStaff_2->setItem(row, 3, new QTableWidgetItem("Nữ"));
                ui->listStaff_2->setItem(row, 4, new QTableWidgetItem(listnv[i]->getDonVi()));
                ui->listStaff_2->setItem(row, 5, new QTableWidgetItem(listnv[i]->getChucVu()->getChucVu()));
                ui->listStaff_2->setItem(row, 6, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getLuong()->getLuong())));
                ui->listStaff_2->setItem(row, 7, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getPhucap())));
                ui->listStaff_2->setItem(row, 8, new QTableWidgetItem(QString::number(listnv[i]->getChucVu()->getThucLinh()->getThuclinh())));
                row ++;
            }
    }


// nút tìm kiếm
    void MainWindow::on_search_btn_clicked()
    {
        QString name = ui->name_input->text();

//        this->addDataToListStaff();
    }
    // Lấy vị trí của nhân viên trên bảng
    template <class T>
    int MainWindow::Getposition(vector<T> nv, QString id){
        for(int i=0; i< int(nv.size()); i++){
            if(nv[i]->getMaNhanVien() == id) return i;
        }
        return -1;
    }
//vị trí chức vụ
//    template <class T>
//    int MainWindow::Getpositioncv(vector<T> cv, QString mcv){
//        for(int i=0; i< int(cv.size()); i++){
//            if(cv[i]->getMaChucVu() == mcv) return i;
//        }
//        return -1;
//    }
    // Đẩy thông tin chi tiết lên
        void MainWindow::InforStaff(NHANVIEN* nv)
        {
            ui->name_in->setText(nv->getHoVaTen());
            ui->age_in->setText(nv->getNgaySinh().getDate());
            if(nv->getGioiTinh()){
               ui->sex_in->setText( "Nam");
               QPixmap px = QPixmap("C:/Users/sanhg/OneDrive/Documents/pbl/img/maleava.png");
               ui->Avatar->setPixmap(px.scaled(ui->Avatar->size(), Qt::KeepAspectRatio));
            }
             else {
                ui->sex_in->setText( "Nữ");
                QPixmap px = QPixmap("C:/Users/sanhg/OneDrive/Documents/pbl/img/femaleava.jpg");
                ui->Avatar->setPixmap(px.scaled(ui->Avatar->size(), Qt::KeepAspectRatio));
            }
            ui->phone_in->setText(nv->getSoDienThoai());
            ui->gmail_in->setText(nv->getGmail());
            ui->address_in->setText(nv->getDiaChi());
        }

// Hiện thông tin chi tiết nhân viên
    void MainWindow::on_listStaff_cellDoubleClicked(int row, int column)
    {

           QString id = ui->listStaff->item(row, 0)->text();
           this->InforStaff(listnv[Getposition(listnv,id)]);
           ui->main_page->setCurrentIndex(6);

    }


//Hiện thông tin nhân viên để xóa
    void MainWindow::on_listStaff_2_cellDoubleClicked(int row, int column)
    {
        ui->main_page->setCurrentIndex(7);
        QString id = ui->listStaff_2->item(row, 0)->text();
        qDebug() << id << '\n';
        QSqlQuery query(myDB);
        query.exec("select HovaTen, NgaySinh, GioiTinh, SoDienThoai, Gmail, DiaChi from NhanVien where MaNhanVien = '" + id + "'");
        while(query.next()){
            ui->name_in_4->setText(query.value(0).toString());
            ui->age_in_4->setText(query.value(1).toString());
            if(query.value(2).toString()=="1"){
               ui->sex_in_6->setText( "Nam");
               QPixmap px = QPixmap("C:/Users/sanhg/OneDrive/Documents/pbl/img/maleava.png");
               ui->Avatar_4->setPixmap(px.scaled(ui->Avatar_4->size(), Qt::KeepAspectRatio));
            }
             else {
                ui->sex_in_6->setText( "Nữ");
                QPixmap px = QPixmap("C:/Users/sanhg/OneDrive/Documents/pbl/img/femaleava.jpg");
                ui->Avatar_4->setPixmap(px.scaled(ui->Avatar_4->size(), Qt::KeepAspectRatio));
            }
            ui->phone_in_4->setText(query.value(3).toString());
            ui->gmail_in_4->setText(query.value(4).toString());
            ui->address_in_4->setText(query.value(5).toString());
        }
    }


// nút quay lui ở list
    void MainWindow::on_back_btn_clicked()
    {
        ui->main_page->setCurrentIndex(2);
         this->addDataToListStaff();
    }
// nút quay lui ở remove
    void MainWindow::on_back_btn_2_clicked()
    {
        ui->main_page->setCurrentIndex(4);
         this->addDataToRemoveStaff();
        ui->remove_btn->setText("XÓA");
    }

// thêm thông tin nv
    void MainWindow::on_pushButton_2_clicked()
    {
        Date d;
        bool gt;
        QString ten,day,gioitinh,sdt,gmail,diachi,machucvu,donvi,id;
        ten=ui->name_in_2->text();
        day=ui->age_in_2->text();
        d.setDate(day);
        gioitinh=ui->sex_in_2->text();
        sdt=ui->phone_in_2->text();
        gmail=ui->gmail_in_2->text();
        diachi=ui->address_in_2->text();
        machucvu=ui->sex_in_3->text();
        donvi=ui->sex_in_4->text();
        int tmp=1;
        if(gioitinh=="Nam"){
            gioitinh="1";
            gt = true;
        }
        else {
            gioitinh="0";
            gt = false;
        }

        QSqlQuery query(myDB);
        query.exec("select * from NhanVien");
        qDebug()<<"this";
//     đếm số cột trong db
        while(query.next())
              {
                  tmp++;
              }
        tmp++;
        if(tmp<10)
            id="NV000"+QString::number(tmp);//NV009
        else
            id="NV00"+QString::number(tmp);
        listnv.push_back(new NHANVIEN(id,ten,gt,d,donvi,machucvu,sdt,gmail,diachi));
    for(int i=0; i<int(listchucvu.size()); i++){
        if(listchucvu[i]->getMaChucVu()==machucvu)
        listnv[int(listnv.size() -1)]->addChucVu(listchucvu[i]);
    }

//  thêm vào db
        query.prepare("insert into NhanVien (MaNhanVien,HovaTen,NgaySinh,GioiTinh,MaChucVu,DonVi,SoDienThoai,Gmail,DiaChi)values('"+id+"',N'"+ten+"','"+day+"',N'"+gioitinh+"','"+machucvu+"',N'"+donvi+"','"+sdt+"','"+gmail+"',N'"+diachi+"')");
        if(query.exec())
        {
             ui->pushButton_2->setText("Đã lưu");
        }
        else ui->pushButton_2->setText("Nhập sai");

// đưa text về null
        ui->name_in_2->setText("");
        ui->age_in_2->setText("");
        ui->sex_in_2->setText("");
        ui->phone_in_2->setText("");
        ui->gmail_in_2->setText("");
        ui->sex_in_3->setText("");
        ui->sex_in_4->setText("");
        ui->address_in_2->setText("");
// placeholder text
        ui->name_in_2->setPlaceholderText("Nguyễn Văn A");
        ui->age_in_2->setPlaceholderText("yyyy-mm-dd");
        ui->sex_in_2->setPlaceholderText("Nam/Nữ");
        ui->phone_in_2->setPlaceholderText("0842770868");
        ui->gmail_in_2->setPlaceholderText("....@Gmail.com");
        ui->sex_in_3->setPlaceholderText("GD/PGD/TP/PTP/NV");
        ui->sex_in_4->setPlaceholderText("Quét Rác/ Vệ Sinh ....");
        ui->address_in_2->setPlaceholderText("Số Nhà - Đường - Quận");
    }

// nút xóa, xóa trong databse
    void MainWindow::on_remove_btn_clicked()
    {
        QString id;
        QMessageBox msg;
        msg.setText("Bạn có thật sự muốn xóa không ?");
        msg.setWindowTitle("Xác Nhận ");
        msg.setWindowIcon(QIcon("C:/Users/sanhg/OneDrive/Documents/pbl/img/app_icon.png"));
        QPushButton *yesbutton=msg.addButton(tr("Có"),QMessageBox::YesRole);
        msg.addButton(tr("Không"),QMessageBox::NoRole);
        msg.exec();
        if(msg.clickedButton()==yesbutton){
            int row = ui->listStaff_2->currentRow();
            id = ui->listStaff_2->item(row, 0)->text();
            QSqlQuery query(myDB);
            query.exec("delete from NhanVien where MaNhanVien = '" + id + "'");
            ui->remove_btn->setText("Đã xóa");
        }
        this->Getposition(listnv,id);
        listnv.erase(listnv.begin() + this->Getposition(listnv,id));

    }

// xóa nhân viên có độ tuổi lớn hơn 50
    void MainWindow::on_pushButton_clicked()
    {
        QSqlQuery query(myDB);
        query.exec("delete from NhanVien where (year(getdate())-year(NgaySinh)) > 50");
        ui->pushButton->setText("Đã Xóa !");
        for(int i=0; i< int(listnv.size()); i++){
            if(listnv[i]->getNgaySinh().getYear()<"1970"){
                 listnv.erase(listnv.begin() + i);
            }
        }
        this->addDataToRemoveStaff();
    }
// hỏi thoát app
    void MainWindow::closeEvent(QCloseEvent *event)
    {
        QMessageBox msg;
        msg.setText("Bạn có thật sự muốn thoát khỏi chương trình không ?");
        msg.setWindowTitle("Xác Nhận ");
        msg.setWindowIcon(QIcon("C:/Users/sanhg/OneDrive/Documents/pbl/img/app_icon.png"));
        QPushButton *nobutton=msg.addButton(tr("Không"),QMessageBox::NoRole);
        msg.addButton(tr("Có"),QMessageBox::YesRole);
        msg.exec();
        if(msg.clickedButton()==nobutton)
        {
            event->ignore();
        }
    }
// thống kê
    void MainWindow :: statistic()
   {
        addDataToListStaff();
        int row = ui->statistic_table->rowCount();
        while(row){
            ui->statistic_table->removeRow(row - 1);
            row --;
        }
        for(int i=0; i< int(listnv.size()); i++){
            int nam=0;
            int nu=0;
            float tl=0;
            bool check=1;

            QString dv=listnv[i]->getDonVi();
            for(int k=0; k<i; k++){
                if(listnv[i]->getDonVi()==listnv[k]->getDonVi()) check=0;
            }
            if(check==0) continue;
            else{
                ui->statistic_table->insertRow(row);
                ui->statistic_table->setItem(row,0,new QTableWidgetItem(dv));
                for(int j=0; j< int(listnv.size()); j++){
                    if(listnv[j]->getGioiTinh() && listnv[j]->getDonVi()==dv){
                        nam++;
                    }
                    if(listnv[j]->getGioiTinh() == 0 && listnv[j]->getDonVi() == dv) nu++;
                    if(listnv[j]->getDonVi()==dv) tl+= listnv[j]->getChucVu()->getThucLinh()->getThuclinh();
                    }
                ui->statistic_table->setItem(row, 1, new QTableWidgetItem(QString::number(nam)));
                ui->statistic_table->setItem(row, 2, new QTableWidgetItem(QString::number(nu)));
                ui->statistic_table->setItem(row, 3, new QTableWidgetItem(QString::number(tl)));
            }

        }
}

    void MainWindow::on_toolButton_clicked()
    {
        ui->main_page->setCurrentIndex(2);
    }

    //nhan nut dang nhap
        void MainWindow::on_logined_btn_clicked()
        {
            QString user = ui->user_name->text();
            QString password = ui->password->text();
                if(user == "sanh" && password == "1"){
                    logined = 1;
                    ui->main_page->setCurrentIndex(1);
                    ui->user_name->setText("");
                    ui->password->setText("");
                    ui->notify_text->setText("");
                }
                else{
                    ui->notify_text->setText("Tên đăng nhập hoặc mật khẩu sai!!!");
                }
        }
        void MainWindow::on_pushButton_h_1_clicked()
        {
            ui->main_page->setCurrentIndex(1);
        }
        void MainWindow::on_pushButton_h_2_clicked()
        {

            ui->main_page->setCurrentIndex(2);
            this->addDataToListStaff();
        }

        void MainWindow::on_pushButton_h_3_clicked()
        {
                ui->main_page->setCurrentIndex(3);
        }

        void MainWindow::on_pushButton_h_4_clicked()
        {
                ui->main_page->setCurrentIndex(4);
                this->addDataToRemoveStaff();

        }
        void MainWindow::on_pushButton_h_5_clicked()
        {
            ui->main_page->setCurrentIndex(5);
            this->statistic();
        }

        void MainWindow::on_pushButton_h_6_clicked()
        {
            ui->main_page->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_l_1_clicked()
        {
            ui->main_page->setCurrentIndex(1);
        }

        void MainWindow::on_pushButton_l_2_clicked()
        {
            ui->main_page->setCurrentIndex(2);
            this->addDataToListStaff();
        }

        void MainWindow::on_pushButton_l_3_clicked()
        {
            ui->main_page->setCurrentIndex(3);
        }

        void MainWindow::on_pushButton_l_4_clicked()
        {
            ui->main_page->setCurrentIndex(4);
             this->addDataToRemoveStaff();
        }

        void MainWindow::on_pushButton_l_5_clicked()
        {
            ui->main_page->setCurrentIndex(5);
            this->statistic();
        }
        void MainWindow::on_pushButton_l_6_clicked()
        {
            ui->main_page->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_a_1_clicked()
        {
             ui->main_page->setCurrentIndex(1);
        }

        void MainWindow::on_pushButton_a_2_clicked()
        {
            ui->main_page->setCurrentIndex(2);
            this->addDataToListStaff();
        }

        void MainWindow::on_pushButton_a_3_clicked()
        {
             ui->main_page->setCurrentIndex(3);
        }

        void MainWindow::on_pushButton_a_4_clicked()
        {
            ui->main_page->setCurrentIndex(4);
             this->addDataToRemoveStaff();
        }

        void MainWindow::on_pushButton_a_5_clicked()
        {
            ui->main_page->setCurrentIndex(5);
            this->statistic();
        }
        void MainWindow::on_pushButton_a_6_clicked()
        {
            ui->main_page->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_r_1_clicked()
        {
             ui->main_page->setCurrentIndex(1);
        }

        void MainWindow::on_pushButton_r_2_clicked()
        {
            ui->main_page->setCurrentIndex(2);
            this->addDataToListStaff();
        }

        void MainWindow::on_pushButton_r_3_clicked()
        {
             ui->main_page->setCurrentIndex(3);
        }

        void MainWindow::on_pushButton_r_4_clicked()
        {
            ui->main_page->setCurrentIndex(4);
             this->addDataToRemoveStaff();
        }

        void MainWindow::on_pushButton_r_5_clicked()
        {
             ui->main_page->setCurrentIndex(5);
             this->statistic();
        }
        void MainWindow::on_pushButton_r_6_clicked()
        {
            ui->main_page->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_s_1_clicked()
        {
             ui->main_page->setCurrentIndex(1);
        }

        void MainWindow::on_pushButton_s_2_clicked()
        {
                ui->main_page->setCurrentIndex(2);
                this->addDataToListStaff();
        }

        void MainWindow::on_pushButton_s_3_clicked()
        {
                ui->main_page->setCurrentIndex(3);
        }

        void MainWindow::on_pushButton_s_4_clicked()
        {
                ui->main_page->setCurrentIndex(4);
                 this->addDataToRemoveStaff();
        }

        void MainWindow::on_pushButton_s_5_clicked()
        {
             ui->main_page->setCurrentIndex(5);
             this->statistic();
        }
        void MainWindow::on_pushButton_s_6_clicked()
        {
            ui->main_page->setCurrentIndex(0);
        }


