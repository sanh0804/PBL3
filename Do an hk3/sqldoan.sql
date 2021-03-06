USE [doan]
GO
/****** Object:  Table [dbo].[ChucVu]    Script Date: 12/28/2020 2:53:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ChucVu](
	[MaChucVu] [varchar](15) NOT NULL,
	[ChucVu] [nvarchar](100) NOT NULL,
	[ThucLinh] [float] NOT NULL,
 CONSTRAINT [pk_machucvu] PRIMARY KEY CLUSTERED 
(
	[MaChucVu] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Luong]    Script Date: 12/28/2020 2:53:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Luong](
	[MaLuong] [varchar](15) NOT NULL,
	[LuongCoBan] [float] NULL,
	[HeSoLuong] [float] NULL,
	[Luong] [float] NULL,
 CONSTRAINT [pk_mhsluong] PRIMARY KEY CLUSTERED 
(
	[MaLuong] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NhanVien]    Script Date: 12/28/2020 2:53:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NhanVien](
	[MaNhanVien] [varchar](15) NOT NULL,
	[HovaTen] [nvarchar](100) NOT NULL,
	[NgaySinh] [date] NOT NULL,
	[GioiTinh] [bit] NOT NULL,
	[MaChucVu] [varchar](15) NULL,
	[DonVi] [nvarchar](200) NULL,
	[SoDienThoai] [nvarchar](10) NULL,
	[Gmail] [nvarchar](100) NULL,
	[DiaChi] [nvarchar](100) NULL,
 CONSTRAINT [pk_manhanvien] PRIMARY KEY CLUSTERED 
(
	[MaNhanVien] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PhuCap]    Script Date: 12/28/2020 2:53:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PhuCap](
	[MaPhuCap] [varchar](15) NOT NULL,
	[HeSoPhuCap] [float] NULL,
 CONSTRAINT [pk_maphucap] PRIMARY KEY CLUSTERED 
(
	[MaPhuCap] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ThucLinh]    Script Date: 12/28/2020 2:53:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ThucLinh](
	[ThucLinh] [float] NOT NULL,
	[MaPhuCap] [varchar](15) NULL,
	[MaLuong] [varchar](15) NULL,
	[PhuCap] [float] NULL,
	[MaChucVu] [varchar](15) NULL,
 CONSTRAINT [PK_ThucLinh] PRIMARY KEY CLUSTERED 
(
	[ThucLinh] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[ChucVu]  WITH CHECK ADD  CONSTRAINT [fk_chucvu_thuclinh] FOREIGN KEY([ThucLinh])
REFERENCES [dbo].[ThucLinh] ([ThucLinh])
GO
ALTER TABLE [dbo].[ChucVu] CHECK CONSTRAINT [fk_chucvu_thuclinh]
GO
ALTER TABLE [dbo].[NhanVien]  WITH CHECK ADD  CONSTRAINT [fk_machucvu2] FOREIGN KEY([MaChucVu])
REFERENCES [dbo].[ChucVu] ([MaChucVu])
GO
ALTER TABLE [dbo].[NhanVien] CHECK CONSTRAINT [fk_machucvu2]
GO
ALTER TABLE [dbo].[ThucLinh]  WITH CHECK ADD  CONSTRAINT [fk_machucvu1] FOREIGN KEY([MaPhuCap])
REFERENCES [dbo].[PhuCap] ([MaPhuCap])
GO
ALTER TABLE [dbo].[ThucLinh] CHECK CONSTRAINT [fk_machucvu1]
GO
ALTER TABLE [dbo].[ThucLinh]  WITH CHECK ADD  CONSTRAINT [fk_mhsluong1] FOREIGN KEY([MaLuong])
REFERENCES [dbo].[Luong] ([MaLuong])
GO
ALTER TABLE [dbo].[ThucLinh] CHECK CONSTRAINT [fk_mhsluong1]
GO
EXEC sys.sp_addextendedproperty @name=N'GD', @value=N'1' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'TABLE',@level1name=N'ThucLinh', @level2type=N'COLUMN',@level2name=N'MaChucVu'
GO
