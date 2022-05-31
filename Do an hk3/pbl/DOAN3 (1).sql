create table NHANVIEN 
(
	iDNhVien nvarchar (10)  ,
	HovaTen nvarchar (50)  ,
	NgaySinh date ,
	GioiTinh bit ,
	DonVi nvarchar (10) ,
	MaChucVu nvarchar (10),
	SoDienThoai nvarchar(10),
	Gmail nvarchar(10),
	Diachi nvarchar(10),
	
	PRIMARY KEY (iDNhVien) ,

	--foreign key (iDDonVi) references dbo.DONVI(iDDonVi) ,
	--foreign key (ChucVu) references dbo.CHUCVU(ChucVu) ,
	--foreign key (TL) references dbo.LUONG(TL) ,
	
)

--bảng chức vụ: cố định
create table CHUCVU 
(
	MaChucVu nvarchar(10),
	ChucVu nvarchar (10) NOT NULL,
	ThucLinh float ,

	PRIMARY KEY (MaChucVu) ,

	--foreign key (TenDonVi) references dbo.DONVI(TenDonVi) ,
	--foreign key (iDNhVien, HovaTen) references dbo.NHANVIEN(iDNhVien, HovaTen),
)
--bảng hệ số lương
--create table HSL
--(
--	HeSoLuong float NOT NULL,
--
--	PRIMARY KEY (HeSoLuong),
--)
--bảng hệ số phụ cấp
--create table HSPC
--(
--	HeSoPC float NOT NULL , 
--
--	PRIMARY KEY (HeSoPC) ,
--)
--bảng tổng hợp tính lương dựa trên chức vụ 

--bảng lương cơ bản :1000$

--bảng tính lương: 
create table THUCLINH
(
	ThucLinh float,
	MaPhuCap nvarchar(10),
	MaLuong nvarchar(10),

	PRIMARY KEY (ThucLinh),
)
create table PHUCAP
(
	MaPhuCap nvarchar(10),
	HeSoPhuCap float,

	PRIMARY KEY (MaPhuCap),
)
create table LUONG
(
	MaLuong nvarchar(10),
	LuongCoBan float,
	HeSoLuong float,
	Luong float,

	PRIMARY KEY (MaLuong),
)


ALTER TABLE dbo.NHANVIEN ADD foreign key (MaChucVu) references dbo.ChucVu(MaChucVu) 
ALTER TABLE dbo.CHUCVU ADD foreign key (ThucLinh) references dbo.THUCLINH(ThucLinh) 
ALTER TABLE dbo.ThucLinh ADD foreign key (MaPhuCap) references dbo.PHUCAP(MaPhuCap)
ALTER TABLE dbo.THUCLINH ADD foreign key (MaLuong) references dbo.LUONG(MaLuong) 



--ALTER TABLE dbo.DONVI ADD foreign key (ChucVu) references dbo.CHUCVU( ChucVu)





