#include "assets/logo.h"
#include "header/PeraturanApoteker.h"
#include "header/ManagementKaryawan.h"
#include "header/PendataanObat.h"
#include "header/PendataanVitamin.h"
#include "header/LaporanPembelian.h"
#include "header/AbsenKaryawan.h"
#include "header/laporanadmin.h"
#include "header/bukuresep.h"
// #include "header/BeliObat.h"
#include <fstream>
#include <iomanip>
#include <iostream>

bool adminLogin() {
  string username, password;
  cout << "Admin Login\n";
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;

  // Ganti dengan logika validasi login sesuai dengan kebutuhan Anda.
  if (username == "admin" && password == "admin123") {
    return true;
  } else {
    cout << "Login gagal. Username atau password salah.\n";
    return false;
  }
}

int main() {
  tampilkanPola();
  int choice;
  while (true) {
    cout << "====================================================" << endl;
    cout << "||" << setw(25) << "MENU" << setw(25) << "||" << endl;
    cout << "====================================================" << endl;
    cout << "|| 1. Admin" << setw(41) << "||" << endl;
    cout << "|| 2. Pasien" << setw(40) << "||" << endl;
    cout << "|| 3. Keluar" << setw(40) << "||" << endl;
    cout << "====================================================" << endl;
    cout << "|| Masukkan pilihan anda: ";
    cin >> choice;
    cout << "====================================================" << endl;

    switch (choice) {
    case 1: {
      int adminChoice;
      cout << "================================" << endl;
      cout << "| 1. Login sebagai Admin       |" << endl;
      cout << "| 2. Kembali ke Menu Utama     |" << endl;
      cout << "================================" << endl;
      cout << "Pilih: ";
      cin >> adminChoice;

      if (adminChoice == 1) {
        if (adminLogin()) {
          // Admin login berhasil
          while (true) {
            cout << endl;
            cout << "================================" << endl;
            cout << "|          MENU ADMIN          |" << endl;
            cout << "================================" << endl;
            cout << "| 1. Peraturan Apoteker        |" << endl;
            cout << "| 2. Management Karyawan       |" << endl;
            cout << "| 3. Pendataan Obat            |" << endl;
            cout << "| 4. Pendataan Vitamin         |" << endl;
            cout << "| 5. Laporan Pembelian Harian  |" << endl;
            cout << "| 6. Absen Apoteker            |" << endl;
            cout << "| 7. laporan kritik saran      |" << endl;
            cout << "| 8. Buku Resep                |" << endl;
            cout << "| 9. Keluar                    |" << endl;
            cout << "================================" << endl;
            int menuadmin;
            cout << "Pilih : ";
            cin >> menuadmin;

            switch (menuadmin) {
            case 1:
              polaperaturan();
              PeraturanApotekerMenu::displayMenu();
              break;
            case 2:
              polamanajemenkaryawan();
              ManagementKaryawanMenu::displayMenu();
              break;
            case 3: {
              polaobat();
              DaftarObatMenu::displayMenu();
            } break;
            case 4: {
              polavitamin();
              PendataanVitaminMenu::displayMenu();
            } break;
            case 5:
              polalaporan();
              LaporanPembelianMenu::displayMenu();
              break;
            case 6: {
              polaabsenkaryawan();
              AbsenKaryawanMenu absenMenu; // Membuat objek AbsenKaryawanMenu
              absenMenu
                  .displayMenu(); // Memanggil metode displayMenu() dari objek
            } break;
            case 7: {
              string berkasLaporan = "laporan_admin.txt";

              LaporanAdminMenu laporanAdmin(berkasLaporan);
              laporanAdmin.displayMenu();

              break;
            }
              case 8 :{
                BukuResepMenu::displayMenu();
                BukuResepMenu::hapusResepObatTeratas();
                BukuResepMenu::displayMenu();
                break;
              }
            case 9:
              break;
            default:
              cout << "Pilihan layanan tidak valid." << endl;
            }

            if (menuadmin == 9) {
              break;
            }
          }
        }
      }
      break;
    }

    case 2: {
      // Menu Pasien
      cout << endl;
      cout << "================================" << endl;
      cout << "|        MENU PASIEN           |" << endl;
      cout << "================================" << endl;
      cout << "| 1. Pembelian Obat            |" << endl;
      cout << "| 2. Pembelian Vitamin         |" << endl;
      cout << "| 3. Pembayaran                |" << endl;
      cout << "| 4. Kritik dan Saran          |" << endl;
      cout << "| 5. Kembali ke Menu Utama     |" << endl;
      cout << "================================" << endl;
      int menupasien;
      cout << "Pilih menu : ";
      cin >> menupasien;

        switch (menupasien) {
          case 1: {
              // BeliObat beliObat;
              // beliObat.displayMenu();
            cout<<"Belum ada";
              break;
          }
          case 2:
              cout << "Belum Ada";
              break;
          case 3:
              cout << "Belum Ada";
              break;
          case 4:
              cout << "Belum Ada";
              break;
      case 5:
        break;
      default:
        cout << "Pilihan layanan tidak valid." << endl;
      }
      break;
    }

    case 3:
      cout << "Terima kasih telah mengunjungi Fitur Farmasi!" << endl;
      return 0;

    default:
      cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }
  }
  return 0;
}