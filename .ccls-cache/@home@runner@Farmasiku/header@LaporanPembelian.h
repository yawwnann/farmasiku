#ifndef LAPORANPEMBELIAN_H
#define LAPORANPEMBELIAN_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LaporanPembelianMenu {
public:
    static void displayMenu() {
        while (true) {
            cout << "\n===== Laporan Pembelian =====" << endl;
            cout << "1. Tambah Laporan Pembelian Obat" << endl;
            cout << "2. Tambah Laporan Pembelian Vitamin" << endl;
            cout << "3. Tampilkan Laporan Pembelian Obat" << endl;
            cout << "4. Tampilkan Laporan Pembelian Vitamin" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih menu: ";

            int menu;
            cin >> menu;

            switch (menu) {
                case 1:
                    tambahLaporanPembelian("laporanpembelianobat.txt");
                    break;
                case 2:
                    tambahLaporanPembelian("laporanpembelianvitamin.txt");
                    break;
                case 3:
                    tampilkanLaporanObat("laporanpembelianobat.txt");
                    break;
                case 4:
                    tampilkanLaporanVitamin("laporanpembelianvitamin.txt");
                    break;
                case 5:
                    return;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    }

private:
    static void tambahLaporanPembelian(const string &filename) {
        ofstream file;
        file.open(filename, ios::app);

        if (!file.is_open()) {
            cout << "Gagal membuka file laporan." << endl;
            return;
        }

        string tanggal, namaObat;
        int jumlah, totalHarga;

        cout << "Masukkan Tanggal Transaksi pembelian: ";
        cin.ignore();
        getline(cin, tanggal);
        cout << "Memasukkan Nama obat/vitamin yang dibeli pasien: ";
        getline(cin, namaObat);
        cout << "Memasukkan Jumlah obat/vitamin yang dibeli pasien: ";
        cin >> jumlah;
        cout << "Memasukkan Jumlah harga total pembelian pasien: ";
        cin >> totalHarga;

        file << "Tanggal: " << tanggal << "\n";
        file << "Nama Obat/Vitamin: " << namaObat << "\n";
        file << "Jumlah: " << jumlah << "\n";
        file << "Total Harga: " << totalHarga << "\n";
        file << "----------------------------------------\n";

        file.close();

        cout << "Laporan pembelian berhasil disimpan." << endl;
    }

    static void tampilkanLaporanObat(const string &obatFilename) {
        ifstream file(obatFilename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << "\n";
            }
            file.close();
        } else {
            cout << "Gagal membuka file laporan pembelian obat." << endl;
        }
    }

    static void tampilkanLaporanVitamin(const string &vitaminFilename) {
        ifstream file(vitaminFilename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << "\n";
            }
            file.close();
        } else {
            cout << "Gagal membuka file laporan pembelian vitamin." << endl;
        }
    }
};

#endif