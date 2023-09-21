#pragma once
#define LuongCoBan 1800000
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class CB {
protected:
	string MSCB, HoTen, NgaySinh;
	float HeSoLuong;
public:
	virtual void Nhap() {
		cin.ignore();
		cout << "Ho ten: ";
		getline(cin, HoTen);
		cout << "Ma so: ";
		getline(cin, MSCB);
		cout << "Ngay sinh: ";
		getline(cin, NgaySinh);
		cout << "Ho so luong: ";
		cin >> HeSoLuong;
		cin.ignore();
	}
	virtual void Xuat() {
		cout << MSCB << "\t" << HoTen << "\t";
		cout << NgaySinh << "\t" << HeSoLuong << "\t";
	}
	CB() {};
	CB(string _maso, string _hoten, string _ngaysinh, float _hesoluong) {
		MSCB = _maso;
		HoTen = _hoten;
		NgaySinh = _ngaysinh;
		HeSoLuong = _hesoluong;
	};
	void setMSCB(string x) {
		MSCB = x;
	};
	void setHoTen(string x) {
		HoTen = x;
	};
	void setNgaySinh(string x) {
		NgaySinh = x;
	};
	void setHeSoLuong(float x) {
		HeSoLuong = x;
	};
	string getMSCB() {
		return MSCB;
	};
	string getHoTen() {
		return HoTen;
	};
	string getNgaySinh() {
		return NgaySinh;
	};
	float getHeSoLuong() {
		return HeSoLuong;
	};
	~CB() {};
	
};

class GiangVien : public CB {
private:
	string Khoa, TrinhDo;
	int SoTietGiangDay;
public:
	GiangVien();
	GiangVien(string _maso, string _hoten, string _ngaysinh, float _hesoluong, string _khoa, string _trinhdo, int _sotiet) {
		MSCB = _maso;
		HoTen = _hoten;
		NgaySinh = _ngaysinh;
		HeSoLuong = _hesoluong;
		Khoa = _khoa;
		TrinhDo = _trinhdo;
		SoTietGiangDay = _sotiet;
	}
	void Nhap() {
		CB::Nhap();
		cout << "Khoa: ";
		getline(cin, Khoa);
		cout << "Trinh do: ";
		getline(cin, TrinhDo);
		cout << "So tiet giang day: ";
		cin >> SoTietGiangDay;
		cin.ignore();
	};
	
	~GiangVien() {};
	void setMSCB(string x) {
		MSCB = x;
	};
	void setHoTen(string x) {
		HoTen = x;
	};
	void setNgaySinh(string x) {
		NgaySinh = x;
	};
	void setHeSoLuong(float x) {
		HeSoLuong = x;
	};
	void setSoTiet(int x) {
		SoTietGiangDay = x;
	}
	void setKhoa(string x) {
		Khoa = x;
	}
	void setTrinhDo(string x) {
		TrinhDo = x;
	}
	string getMSCB() {
		return MSCB;
	};
	string getHoTen() {
		return HoTen;
	};
	string getNgaySinh() {
		return NgaySinh;
	};
	float getHeSoLuong() {
		return HeSoLuong;
	};
	int getSoTiet() {
		return SoTietGiangDay;
	}
	string getKhoa() {
		return Khoa;
	}
	string getTrinhDo() {
		return TrinhDo;
	}
	int getPhuCap() {
		if (TrinhDo == "CuNhan" || TrinhDo == "KySu")
			return 12000000;
		if (TrinhDo == "ThacSi")
			return 25000000;
		if (TrinhDo == "TienSi")
			return 42000000;
	}
	float calcLuong() {

		return LuongCoBan * HeSoLuong + SoTietGiangDay * 150000 + GiangVien::getPhuCap();
	}
	void xepLoai() {
		if (SoTietGiangDay < 30)
			cout << "Khong hoan thanh nhiem vu";
		if (SoTietGiangDay >= 30 && SoTietGiangDay <= 100)
			cout << "Hoan thanh nhiem vu";
		if (SoTietGiangDay > 100)
			cout << "Hoan thanh xuat sac nhiem vu";
	}
	void Xuat() {
		CB::Xuat();
		cout << Khoa << "\t" << TrinhDo << "\t";
		cout << SoTietGiangDay << "\t" << GiangVien::calcLuong() << "\t";
		GiangVien::xepLoai();
	}
};

class ChuyenVien : public CB {
private:
	string PhongBan, ChucVu;
	int SoNgayCong;
public:
	ChuyenVien() {};
	ChuyenVien(string _maso, string _hoten, string _ngaysinh, float _hesoluong, string _phongban, string _chucvu, int _songaycong) {
		MSCB = _maso;
		HoTen = _hoten;
		NgaySinh = _ngaysinh;
		HeSoLuong = _hesoluong;
		PhongBan = _phongban;
		ChucVu = _chucvu;
		SoNgayCong = _songaycong;
	}
	~ChuyenVien() {};
	void Nhap() {
		CB::Nhap();
		cout << "Phong ban: ";
		getline(cin, PhongBan);
		cout << "Chuc vu: ";
		getline(cin, ChucVu);
		cout << "So ngay cong: ";
		cin >> SoNgayCong;
		cin.ignore();
	};
	
	void setMSCB(string x) {
		MSCB = x;
	};
	void setHoTen(string x) {
		HoTen = x;
	};
	void setNgaySinh(string x) {
		NgaySinh = x;
	};
	void setHeSoLuong(float x) {
		HeSoLuong = x;
	};
	void setSoNgayCong(int x) {
		SoNgayCong = x;
	}
	void setChucVu(string x) {
		ChucVu = x;
	}
	void setPhongBan(string x) {
		PhongBan = x;
	}
	string getMSCB() {
		return MSCB;
	};
	string getHoTen() {
		return HoTen;
	};
	string getNgaySinh() {
		return NgaySinh;
	};
	float getHeSoLuong() {
		return HeSoLuong;
	};
	int getSoNgayCong() {
		return SoNgayCong;
	}
	string getChucVu() {
		return ChucVu;
	}
	string getPhongBan() {
		return PhongBan;
	}
	int getPhuCap() {
		if (ChucVu == "ChuyenVien")
			return 12000000;
		if (ChucVu == "PhoPhong")
			return 25000000;
		if (ChucVu == "TruongPhong")
			return 42000000;
	}
	float calcLuong() {

		return LuongCoBan * HeSoLuong + SoNgayCong * 130000 + ChuyenVien::getPhuCap();
	}
	void xepLoai() {
		if (SoNgayCong < 20)
			cout << "Khong hoan thanh nhiem vu";
		if (SoNgayCong >= 20 && SoNgayCong <= 25)
			cout << "Hoan thanh nhiem vu";
		if (SoNgayCong > 25)
			cout << "Hoan thanh xuat sac nhiem vu";
	}
	void Xuat() {
		CB::Xuat();
		cout << PhongBan << "\t" << ChucVu << "\t";
		cout << SoNgayCong << "\t" << ChuyenVien::calcLuong() << "\t";
		ChuyenVien::xepLoai();
	}
};

class QLCB {
private:
	vector<CB*> arr;
public:
	QLCB() {};
	friend istream& operator>>(istream& is, QLCB& t);
	friend ostream& operator<<(ostream& os, QLCB& t);
	//void XuatHoanThanhXuatSac();
	// void XuatLuongGiamDan;
};

istream& operator>>(istream& is, QLCB& t) {
	cout << "0: Ket thuc\n";
	cout << "1: Giang vien\n";
	cout << "2: Chuyen vien\n";
	while (1) {
		int lc;
		cout << "Nhap lua chon: ";
		is >> lc;
		if (!lc) break;
		if (lc == 1) {
			CB* newCB = new GiangVien;
			newCB->Nhap();
			t.arr.push_back(newCB);
		}
		if (lc == 2) {
			CB* newCB = new ChuyenVien;
			newCB->Nhap();
			t.arr.push_back(newCB);
		}
	}
	return is;
}

ostream& operator<<(ostream& os, QLCB& a) {
	os << "Nhan vien tien tien:\n";
	for (int i = 0; i < a.arr.size(); i++) {
		a.arr[i]->Xuat();
	}
	return os;
}

//void QLCB::XuatLuongGiamDan() Ơ