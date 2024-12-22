// BukuResep.h
#ifndef BUKURESEP_H
#define BUKURESEP_H

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

struct ResepObat {
    std::string namaObat;
    std::string komposisi;
    std::string petunjukPenggunaan;
};

class BukuResepMenu {
private:
    static std::stack<ResepObat> bukuResepObat;

public:
    static void displayMenu() {

        int choice = 0;

        while (choice != 4) {
            std::cout << "Buku Resep Obat" << std::endl;
            std::cout << "-----------------" << std::endl;

            // Tampilkan menu tambah, lihat, hapus, dan keluar
            std::cout << "\nMenu Resep Obat:" << std::endl;
            std::cout << "1. Tambah Resep Obat" << std::endl;
            std::cout << "2. Lihat Resep" << std::endl;
            std::cout << "3. Hapus Resep" << std::endl;
            std::cout << "4. Keluar" << std::endl;

            std::cout << "Pilihan Anda: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    // Tambah Resep
                    tambahResepObat();
                    break;

                case 2:
                    // Lihat Resep
                    lihatResep();
                    break;

                case 3:
                    // Hapus Resep
                    hapusResepObatTeratas();
                    break;

                case 4:
                    // Keluar
                    return;

                default:
                    std::cout << "Pilihan tidak valid." << std::endl;
            }
        }
    }

    static void tambahResepObat() {
        ResepObat resepObat;
        std::cout << "Tambah Resep Obat" << std::endl;
        std::cout << "Nama Obat: ";
        std::cin >> resepObat.namaObat;
        std::cout << "Komposisi: ";
        std::cin >> resepObat.komposisi;
        std::cout << "Petunjuk Penggunaan: ";
        std::cin >> resepObat.petunjukPenggunaan;

        bukuResepObat.push(resepObat);

        std::ofstream file("bukuResep.txt", std::ios::app);
        if (file.is_open()) {
            file << resepObat.namaObat << "," << resepObat.komposisi << "," << resepObat.petunjukPenggunaan << "\n";
            file.close();
            std::cout << "Resep obat berhasil ditambahkan ke buku resep dan file." << std::endl;
        } else {
            std::cerr << "Gagal membuka file bukuResep.txt untuk penambahan resep obat." << std::endl;
        }
    }

    static void hapusResepObatTeratas() {
        // Menghapus resep obat teratas dari stack
        if (!bukuResepObat.empty()) {
            bukuResepObat.pop();
            std::cout << "Resep obat teratas berhasil dihapus dari buku resep obat." << std::endl;

            // Menyimpan ulang buku resep ke dalam file setelah menghapus
            simpanBukuResepKeFile();
        } else {
            std::cout << "Buku resep obat kosong. Tidak ada resep obat yang dapat dihapus." << std::endl;
        }
    }

    static void tampilkanResepDariFile() {
        std::ifstream file("dataResep.txt");
        std::string line;

        std::cout << "Daftar Resep Obat dari File:" << std::endl;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string namaObat, komposisi, petunjukPenggunaan;
            std::getline(iss, namaObat, ',');
            std::getline(iss, komposisi, ',');
            std::getline(iss, petunjukPenggunaan, ',');

            std::cout << "Nama Obat: " << namaObat << std::endl;
            std::cout << "Komposisi: " << komposisi << std::endl;
            std::cout << "Petunjuk Penggunaan: " << petunjukPenggunaan << std::endl;
            std::cout << "-----------------" << std::endl;
        }

        file.close();
    }

    static void lihatResep() {
        std::cout << "Lihat Resep Obat" << std::endl;

        // Menampilkan resep dari buku resep
        if (!bukuResepObat.empty()) {
            const ResepObat& resepObatTeratas = bukuResepObat.top();
            std::cout << "Resep Obat Teratas:" << std::endl;
            std::cout << "Nama Obat: " << resepObatTeratas.namaObat << std::endl;
            std::cout << "Komposisi: " << resepObatTeratas.komposisi << std::endl;
            std::cout << "Petunjuk Penggunaan: " << resepObatTeratas.petunjukPenggunaan << std::endl;
        } else {
            std::cout << "Buku resep obat kosong." << std::endl;
        }

        // Menampilkan resep dari file
        tampilkanResepDariFile();
    }

    static void simpanBukuResepKeFile() {
        std::ofstream file("dataResep.txt");
        while (!bukuResepObat.empty()) {
            const ResepObat& resepObat = bukuResepObat.top();
            file << resepObat.namaObat << "," << resepObat.komposisi << "," << resepObat.petunjukPenggunaan << "\n";
            bukuResepObat.pop();
        }
        file.close();
    }
};

std::stack<ResepObat> BukuResepMenu::bukuResepObat; // Inisialisasi statis

#endif // BUKURESEP_H
