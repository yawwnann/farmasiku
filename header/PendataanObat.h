#ifndef PENDATAANOBAT_H
#define PENDATAANOBAT_H

#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct DataObat {
    std::string namaObat;
    std::string jenisObat;
    std::string petunjukPenggunaan;
    int stok;
    double harga;
};

class DaftarObatMenu {
private:
    static std::stack<DataObat> daftarObat;
static void simpanDaftarObatKeFile();

public:
    static void displayMenu() {
        int choice = 0;

        while (choice != 10) {
            std::cout << "Daftar Obat" << std::endl;
            std::cout << "-----------------" << std::endl;

            std::cout << "\nMenu Daftar Obat:" << std::endl;
            std::cout << "1. Tambah Data Obat" << std::endl;
            std::cout << "2. Sorting Obat" << std::endl;
            std::cout << "3. Tampilkan Daftar Obat" << std::endl;
            std::cout << "4. Edit Obat" << std::endl;
            std::cout << "5. Hapus Obat" << std::endl;
            std::cout << "6. Tampilkan Statistik" << std::endl;
            std::cout << "7. Simpan Data" << std::endl;
            std::cout << "8. Keluar" << std::endl;

            std::cout << "Pilihan Anda: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    tambahDataObat();
                    break;
              
                case 2:
                    sortingObat();
                    break;

                case 3:
                    tampilkanDaftarObat();
                    break;

                case 4:
                    editObat();
                    break;

                case 5:
                    hapusObat();
                    break;

                case 6:
                    tampilkanStatistik();
                    break;

                case 7:
                    simpanData();
                    break;

                case 8:
                    keluar();
                    return;

                default:
                    std::cout << "Pilihan tidak valid." << std::endl;
            }
        }
    }

    static void tambahDataObat() {
        DataObat dataObat;
        std::cout << "Tambah Data Obat" << std::endl;
        std::cout << "Nama Obat: ";
        std::cin >> dataObat.namaObat;
        std::cout << "Jenis Obat: ";
        std::cin >> dataObat.jenisObat;
        std::cout << "Petunjuk Penggunaan: ";
        std::cin >> dataObat.petunjukPenggunaan;
        std::cout << "Stok: ";
        std::cin >> dataObat.stok;
        std::cout << "Harga: ";
        std::cin >> dataObat.harga;

        daftarObat.push(dataObat);

        std::ofstream file("daftarObat.txt", std::ios::app);
        if (file.is_open()) {
            file << dataObat.namaObat << "," << dataObat.jenisObat << ","
                 << dataObat.petunjukPenggunaan << "," << dataObat.stok << ","
                 << dataObat.harga << "\n";
            file.close();
            std::cout << "Data obat berhasil ditambahkan ke daftar obat dan file." << std::endl;
        } else {
            std::cerr << "Gagal membuka file daftarObat.txt untuk penambahan data obat." << std::endl;
        }
    }


static void sortingObat() {
    std::cout << "Daftar obat berhasil diurutkan." << std::endl;

    // Copy elements from stack to vector for sorting
    std::vector<DataObat> tempVector;
    while (!daftarObat.empty()) {
        tempVector.push_back(daftarObat.top());
        daftarObat.pop();
    }

    // Sort the vector based on a criteria, e.g., namaObat
    std::sort(tempVector.begin(), tempVector.end(), [](const DataObat& a, const DataObat& b) {
        return a.namaObat < b.namaObat;
    });

    // Push the sorted elements back to the stack
    for (const auto& dataObat : tempVector) {
        daftarObat.push(dataObat);
    }
}


    static void tampilkanDaftarObat() {
        std::cout << "Daftar Obat:" << std::endl;

        if (!daftarObat.empty()) {
            std::stack<DataObat> tempStack = daftarObat;
            while (!tempStack.empty()) {
                const DataObat& dataObat = tempStack.top();
                std::cout << "Nama Obat: " << dataObat.namaObat << std::endl;
                std::cout << "Jenis Obat: " << dataObat.jenisObat << std::endl;
                std::cout << "Petunjuk Penggunaan: " << dataObat.petunjukPenggunaan << std::endl;
                std::cout << "Stok: " << dataObat.stok << std::endl;
                std::cout << "Harga: " << dataObat.harga << std::endl;
                std::cout << "-----------------" << std::endl;

                tempStack.pop();
            }
        } else {
            std::cout << "Daftar obat kosong." << std::endl;
        }
    }

static void editObat() {
    std::string targetNamaObat;
    std::cout << "Masukkan nama obat yang akan diubah: ";
    std::cin >> targetNamaObat;

    std::stack<DataObat> tempStack;  // Temporary stack to hold modified elements

    while (!daftarObat.empty()) {
        DataObat currentObat = daftarObat.top();
        daftarObat.pop();

        if (currentObat.namaObat == targetNamaObat) {
            // Modify the desired obat
            std::cout << "Masukkan data obat yang baru:" << std::endl;
            std::cout << "Jenis Obat: ";
            std::cin >> currentObat.jenisObat;
            std::cout << "Petunjuk Penggunaan: ";
            std::cin >> currentObat.petunjukPenggunaan;
            std::cout << "Stok: ";
            std::cin >> currentObat.stok;
            std::cout << "Harga: ";
            std::cin >> currentObat.harga;
        }

        tempStack.push(currentObat);  // Push modified or unmodified element to temporary stack
    }

    // Push elements back to the original stack
    while (!tempStack.empty()) {
        daftarObat.push(tempStack.top());
        tempStack.pop();
    }

    std::cout << "Data obat berhasil diubah." << std::endl;
}

static void hapusObat() {
    std::string targetNamaObat;
    std::cout << "Masukkan nama obat yang akan dihapus: ";
    std::cin >> targetNamaObat;

    std::stack<DataObat> tempStack;  // Temporary stack to hold non-matching elements

    while (!daftarObat.empty()) {
        DataObat currentObat = daftarObat.top();
        daftarObat.pop();

        if (currentObat.namaObat != targetNamaObat) {
            tempStack.push(currentObat);  // Push non-matching elements to temporary stack
        }
    }

    // Push non-matching elements back to the original stack
    while (!tempStack.empty()) {
        daftarObat.push(tempStack.top());
        tempStack.pop();
    }

    std::cout << "Data obat berhasil dihapus." << std::endl;
}

static void tampilkanStatistik() {
    int totalObat = 0;
    double totalHarga = 0;
    int obatDenganStokTerbanyak = 0;
    int stokTerbanyak = 0;

    // Calculate statistics based on the obat data
    while (!daftarObat.empty()) {
        const DataObat& currentObat = daftarObat.top();
        totalObat++;
        totalHarga += currentObat.harga;

        if (currentObat.stok > stokTerbanyak) {
            stokTerbanyak = currentObat.stok;
            obatDenganStokTerbanyak = totalObat;
        }

        daftarObat.pop();
    }

    // Display statistics
    std::cout << "Statistik Obat:" << std::endl;
    std::cout << "Total Obat: " << totalObat << std::endl;
    std::cout << "Total Harga Obat: " << totalHarga << std::endl;
    std::cout << "Obat dengan Stok Terbanyak (Obat ke-" << obatDenganStokTerbanyak << "): " << stokTerbanyak << " unit" << std::endl;

    std::cout << "Statistik obat berhasil ditampilkan." << std::endl;
}

static void simpanData() {
    std::ofstream file("daftarObat_saved.txt");
    std::stack<DataObat> tempStack;

    // Save the current state of daftarObat to a file
    while (!daftarObat.empty()) {
        const DataObat& currentObat = daftarObat.top();
        file << currentObat.namaObat << "," << currentObat.jenisObat << ","
             << currentObat.petunjukPenggunaan << "," << currentObat.stok << ","
             << currentObat.harga << "\n";
        tempStack.push(currentObat);
        daftarObat.pop();
    }

    // Restore the original state of daftarObat
    while (!tempStack.empty()) {
        daftarObat.push(tempStack.top());
        tempStack.pop();
    }

    file.close();
    std::cout << "Data obat berhasil disimpan." << std::endl;
}

static void keluar() {
    std::cout << "Terima kasih! Program selesai." << std::endl;

    simpanData();

    // Additional exit logic if needed
}

};

std::stack<DataObat> DaftarObatMenu::daftarObat;

#endif // PENDATAANOBAT_H
