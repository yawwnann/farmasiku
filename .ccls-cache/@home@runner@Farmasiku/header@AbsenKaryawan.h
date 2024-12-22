#ifndef ABSENKARYAWAN_H
#define ABSENKARYAWAN_H

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Absen {
public:
  string tanggal;
  string waktuMasuk;
  string waktuPulang;
  string nama;
  double jamLembur;
  double bonusLembur;
  double dendaKeterlambatan;

  Absen() : jamLembur(0), bonusLembur(0), dendaKeterlambatan(0) {}
};

struct Node {
  Absen data;
  Node* next;
};

class AbsenKaryawanMenu {
private:
  Node* head;

public:
  AbsenKaryawanMenu() : head(nullptr) {
    // Membaca data dari file saat program dimulai
    bacaDariFile(); 
  }

  ~AbsenKaryawanMenu() {
    // Menyimpan data ke file saat program berakhir
    simpanKeFile(); 
    // Hapus semua data sebelum keluar
    hapusSemuaData(); 
  }

  void displayMenu() {
    while (true) {
      cout << "\n===== Absen Karyawan =====" << endl;
      cout << "1. Absen Masuk" << endl;
      cout << "2. Absen Pulang" << endl;
      cout << "3. Tampilkan Absen Karyawan" << endl;
      cout << "4. Hapus Absen" << endl;
      cout << "5. Keluar" << endl;
      cout << "Pilih menu: ";

      int menu;
      cin >> menu;

      switch (menu) {
        case 1: // Absen Masuk
          absenMasuk();
          break;
        case 2: // Absen Pulang
          absenPulang();
          break;
        case 3: // Tampilkan Absen Karyawan
          tampilkanAbsenKaryawan();
          break;
        case 4: // Hapus Absen
          hapusAbsen();
          break;
        case 5: // Keluar
          return;
        default:
          cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
      }
    }
  }

  void absenMasuk() {
    Absen absen;
    absen.tanggal = getCurrentDate();

    cout << "Nama Karyawan: ";
    cin.ignore(); // Membersihkan buffer
    // Membaca nama karyawan
    getline(cin, absen.nama); 

    cout << "Waktu Masuk (HH:MM) contoh 19.20: ";
    cin >> absen.waktuMasuk;

    if (absen.waktuMasuk < "09:00") {
      cout << "Absen masuk berhasil dicatat." << endl;
    } else {
      absen.dendaKeterlambatan = hitungDendaKeterlambatan(absen.waktuMasuk);
      cout << "Anda terlambat! Denda keterlambatan: Rp "
           << absen.dendaKeterlambatan << endl;
    }

    push(absen);
  }

  void absenPulang() {
    if (head == nullptr) {
      cout << "Anda belum melakukan absen masuk." << endl;
      return;
    }

    Node* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }

    if (current->data.waktuPulang.empty()) {
      cout << "Nama Karyawan: " << current->data.nama << endl;
      cout << "Waktu Pulang (HH:MM) contoh 19.20: ";
      cin >> current->data.waktuPulang;

      double jamPulang = stod(current->data.waktuPulang.substr(0, 2));

      if (jamPulang > 20.0) { 
        // Hitung jam lembur jika pulang setelah jam 8 malam
        current->data.jamLembur = jamPulang - 20.0;
        current->data.bonusLembur = current->data.jamLembur * 50000;
      } else {
        current->data.jamLembur = 0;
        current->data.bonusLembur = 0;
      }

      cout << "Absen pulang berhasil dicatat." << endl;
    } else {
      cout << "Anda sudah melakukan absen pulang hari ini." << endl;
    }
  }

  void hapusAbsen() {
    if (head == nullptr) {
      cout << "Belum ada data absen karyawan." << endl;
      return;
    }

    string tanggalHapus;
    cout << "Masukkan tanggal absen yang akan dihapus (dd-mm-yyyy): ";
    cin >> tanggalHapus;

    Node* current = head;
    Node* previous = nullptr;
    bool found = false;

    while (current != nullptr) {
      if (current->data.tanggal == tanggalHapus) {
        found = true;
        if (previous == nullptr) {
          // Menghapus node pertama
          head = current->next;
          delete current;
        } else {
          previous->next = current->next;
          delete current;
        }
        cout << "Absen pada tanggal " << tanggalHapus << " berhasil dihapus." << endl;
        return;
      }

      previous = current;
      current = current->next;
    }

    if (!found) {
      cout << "Tidak ada data absen pada tanggal " << tanggalHapus << "." << endl;
    }
  }

  void tampilkanAbsenKaryawan() {
    if (head == nullptr) {
      cout << "Belum ada data absen karyawan." << endl;
    } else {
      Node* current = head;
      while (current != nullptr) {
        cout << "Tanggal: " << current->data.tanggal << endl;
        cout << "Nama Karyawan: " << current->data.nama << endl;
        cout << "Waktu Masuk: " << current->data.waktuMasuk << endl;
        if (!current->data.waktuPulang.empty()) {
          cout << "Waktu Pulang: " << current->data.waktuPulang << endl;
          cout << "Jam Lembur: " << current->data.jamLembur << " jam" << endl;
          cout << "Bonus Lembur: Rp " << current->data.bonusLembur << endl;
          cout << "Denda Keterlambatan: Rp " << current->data.dendaKeterlambatan << endl;
        }
        cout << "====================================" << endl;
        current = current->next;
      }
    }
  }

  void push(const Absen& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
    } else {
      Node* current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }

  string getCurrentDate() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    return buf;
  }

  double hitungDendaKeterlambatan(const string& waktuMasuk) {
    double jamMasuk = stod(waktuMasuk.substr(0, 2));
    double menitMasuk = stod(waktuMasuk.substr(3, 2));
    double jamBatas = 9.0;
    double menitBatas = 0.0;
    double dendaPerJam = 30000.0;

    double denda = 0.0;

    if (jamMasuk > jamBatas) {
      double selisihJam = jamMasuk - jamBatas;
      double selisihMenit = menitMasuk - menitBatas;

      if (selisihMenit < 0) {
        selisihJam -= 1;
        selisihMenit += 60;
      }

      denda = (selisihJam + (selisihMenit / 60)) * dendaPerJam;
    }

    return denda;
  }

void simpanKeFile() {
    ofstream file("data_absen.txt");
    if (!file) {
        cout << "Gagal membuka file data_absen.txt." << endl;
        return;
    }

    Node* current = head;

    file << "====================================================================================================================\n";
    file << "| Tanggal     | Nama Karyawan       | Waktu Masuk | Waktu Pulang | Jam Lembur | Bonus Lembur | Denda Keterlambatan |\n";
    file << "====================================================================================================================\n";

    while (current != nullptr) {
        file << "| " << setw(11) << current->data.tanggal << " | " << setw(19) << current->data.nama << " | " << setw(11) << current->data.waktuMasuk << " | ";

        if (!current->data.waktuPulang.empty()) {
            file << setw(13) << current->data.waktuPulang << " | " << setw(10) << current->data.jamLembur << " | " << setw(12) << current->data.bonusLembur << " | " << setw(19) << current->data.dendaKeterlambatan << " |\n";
        } else {
            file << "           |           |            |            |              |\n";
        }

        current = current->next;
    }

    file << "====================================================================================================================\n";
    file.close();
    cout << "Data absen berhasil disimpan ke dalam file data_absen.txt." << endl;
}


  void bacaDariFile() {
    ifstream file("data_absen.txt");
    if (!file) {
      cout << "File data_absen.txt tidak ditemukan atau tidak dapat dibaca." << endl;
      return;
    }

    string line;
    while (getline(file, line)) {
      istringstream ss(line);
      string tanggal, nama, waktuMasuk, waktuPulang;
      double jamLembur, bonusLembur, dendaKeterlambatan;

      getline(ss, tanggal, ',');
      getline(ss, nama, ',');
      getline(ss, waktuMasuk, ',');
      getline(ss, waktuPulang, ',');
      ss >> jamLembur;
      ss.ignore();
      ss >> bonusLembur;
      ss.ignore();
      ss >> dendaKeterlambatan;

      Absen absen;
      absen.tanggal = tanggal;
      absen.nama = nama;
      absen.waktuMasuk = waktuMasuk;
      absen.waktuPulang = waktuPulang;
      absen.jamLembur = jamLembur;
      absen.bonusLembur = bonusLembur;
      absen.dendaKeterlambatan = dendaKeterlambatan;

      push(absen);
    }

    file.close();
    cout << "Data absen berhasil dibaca dari file data_absen.txt." << endl;
  }

  void hapusSemuaData() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};

#endif