#ifndef PENDATAANVITAMIN_H
#define PENDATAANVITAMIN_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N> class statisarrayy {
public:
  statisarrayy() { size = 0; }

  bool append(const T &item) {
    if (size < N) {
      arr[size++] = item;
      return true;
    }
    return false;
  }

  T &operator[](size_t index) {
    if (index < size) {
      return arr[index];
    }
    return arr[0];
  }

  const T &operator[](size_t index) const {
    if (index < size) {
      return arr[index];
    }
    return arr[0];
  }

  size_t getSize() const { return size; }

  T *getArray() { return arr; }

  void decrementSize() {
    if (size > 0) {
      size--;
    }
  }

private:
  T arr[N];
  size_t size;
};

template <typename T> class Vitamin {
public:
  string nama;
  T jenis;
  int stok;
  double harga;
};

class PendataanVitaminMenu {
public:
  static void displayMenu() {
    statisarrayy<Vitamin<string>, 100> daftarVitamin;
    loadDaftarVitamin(daftarVitamin);

    while (true) {
      cout << "\n===== Pendataan Vitamin =====" << endl;
      cout << "1. Tambah vitamin" << endl;
      cout << "2. Cari vitamin" << endl;
      cout << "3. Sorting vitamin" << endl;
      cout << "4. Tampilkan daftar vitamin" << endl;
      cout << "5. Edit vitamin" << endl;
      cout << "6. Hapus vitamin" << endl;
      cout << "7. Tampilkan Statistik" << endl;
      cout << "8. Simpan Data" << endl;
      cout << "9. Keluar" << endl;
      cout << "Pilih menu: ";

      int menu;
      cin >> menu;

      switch (menu) {
      case 1:
        tambahVitamin(daftarVitamin);
        break;
      case 2:
        cariVitamin(daftarVitamin);
        break;
      case 3:
        sortingVitamin(daftarVitamin);
        break;
      case 4:
        tampilkanDaftarVitamin(daftarVitamin);
        break;
      case 5:
        editVitamin(daftarVitamin);
        break;
      case 6:
        hapusVitamin(daftarVitamin);
        break;
      case 7:
        tampilkanStatistik(daftarVitamin);
        break;
      case 8:
        saveDaftarVitamin(daftarVitamin);
        break;
      case 9:
        return;
      default:
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
      }
    }
  }

private:
  static void tambahVitamin(statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    Vitamin<string> vitamin;
    cout << "Nama vitamin: ";
    cin.ignore();
    getline(cin, vitamin.nama);
    cout << "Jenis vitamin (A/B/C/D/E/K): ";
    cin >> vitamin.jenis;
    cout << "Stok vitamin: ";
    cin >> vitamin.stok;
    cout << "Harga vitamin: ";
    cin >> vitamin.harga;
    daftarVitamin.append(vitamin);
    cout << "Vitamin berhasil ditambahkan." << endl;
  }

  static void
  cariVitamin(const statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    string jenis;
    cout << "Masukkan jenis vitamin (A/B/C/D/E/K): ";
    cin >> jenis;

    cout << "\nDaftar vitamin berdasarkan jenis '" << jenis << "':" << endl;
    for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
      const Vitamin<string> &vitamin = daftarVitamin[i];
      if (vitamin.jenis == jenis) {
        cout << "Nama: " << vitamin.nama << ", Stok: " << vitamin.stok
             << ", Harga: " << vitamin.harga << endl;
      }
    }
  }

  static void
  sortingVitamin(statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    cout << "1. Berdasarkan Jenis" << endl;
    cout << "2. Berdasarkan Stok" << endl;
    cout << "3. Berdasarkan Harga" << endl;
    cout << "Pilih kriteria sorting: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      sort(daftarVitamin.getArray(),
           daftarVitamin.getArray() + daftarVitamin.getSize(),
           [](const Vitamin<string> &a, const Vitamin<string> &b) {
             return a.jenis < b.jenis;
           });
      break;
    case 2:
      sort(daftarVitamin.getArray(),
           daftarVitamin.getArray() + daftarVitamin.getSize(),
           [](const Vitamin<string> &a, const Vitamin<string> &b) {
             return a.stok < b.stok;
           });
      break;
    case 3:
      sort(daftarVitamin.getArray(),
           daftarVitamin.getArray() + daftarVitamin.getSize(),
           [](const Vitamin<string> &a, const Vitamin<string> &b) {
             return a.harga < b.harga;
           });
      break;
    default:
      cout << "Pilihan tidak valid." << endl;
    }

    cout << "Data berhasil diurutkan." << endl;
  }

  static void tampilkanDaftarVitamin(
      const statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    cout << "Daftar vitamin:" << endl;
    for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
      const Vitamin<string> &vitamin = daftarVitamin[i];
      cout << "Nama: " << vitamin.nama << ", Jenis: " << vitamin.jenis
           << ", Stok: " << vitamin.stok << ", Harga: " << vitamin.harga
           << endl;
    }
  }

  static void editVitamin(statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    cout << "Masukkan nama vitamin yang akan diedit: ";
    string nama;
    cin.ignore();
    getline(cin, nama);

    bool found = false;
    for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
      Vitamin<string> &vitamin = daftarVitamin[i];
      if (vitamin.nama == nama) {
        cout << "Nama vitamin: ";
        getline(cin, vitamin.nama);
        cout << "Jenis vitamin (A/B/C/D/E/K): ";
        cin >> vitamin.jenis;
        cout << "Stok vitamin: ";
        cin >> vitamin.stok;
        cout << "Harga vitamin: ";
        cin >> vitamin.harga;
        cout << "Vitamin berhasil diubah." << endl;
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "Vitamin dengan nama '" << nama << "' tidak ditemukan." << endl;
    }
  }

  static void hapusVitamin(statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    cout << "Masukkan nama vitamin yang akan dihapus: ";
    string nama;
    cin.ignore();
    getline(cin, nama);

    for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
      Vitamin<string> &vitamin = daftarVitamin[i];
      if (vitamin.nama == nama) {
        for (size_t j = i; j < daftarVitamin.getSize() - 1; j++) {
          daftarVitamin[j] = daftarVitamin[j + 1];
        }
        daftarVitamin.decrementSize();
        cout << "Vitamin berhasil dihapus." << endl;
        return;
      }
    }

    cout << "Vitamin dengan nama '" << nama << "' tidak ditemukan." << endl;
  }

  static void
  tampilkanStatistik(const statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    double totalHarga = 0;
    int totalStok = 0;

    for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
      const Vitamin<string> &vitamin = daftarVitamin[i];
      totalHarga += vitamin.harga;
      totalStok += vitamin.stok;
    }

    cout << "Statistik vitamin:" << endl;
    cout << "Total stok vitamin: " << totalStok << endl;
    cout << "Total harga vitamin: " << totalHarga << endl;
  }

  static void
  loadDaftarVitamin(statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    ifstream file("daftar_vitamin.txt");
    if (file.is_open()) {
      while (!file.eof()) {
        Vitamin<string> vitamin;
        getline(file, vitamin.nama);
        file >> vitamin.jenis;
        file >> vitamin.stok;
        file >> vitamin.harga;
        daftarVitamin.append(vitamin);
      }
      file.close();
    } else {
      cout << "File daftar_vitamin.txt tidak ditemukan. Data kosong." << endl;
    }
  }

  static void
  saveDaftarVitamin(const statisarrayy<Vitamin<string>, 100> &daftarVitamin) {
    ofstream file("daftar_vitamin.txt");
    if (file.is_open()) {
      for (size_t i = 0; i < daftarVitamin.getSize(); i++) {
        const Vitamin<string> &vitamin = daftarVitamin[i];
        file << "=========================" << endl;
        file << vitamin.nama << endl;
        file << vitamin.jenis << endl;
        file << vitamin.stok << endl;
        file << vitamin.harga << endl;
        file << "=========================" << endl;
      }
      file.close();
      cout << "Data berhasil disimpan." << endl;
    } else {
      cout << "Gagal menyimpan data ke dalam file." << endl;
    }
  }
};

#endif