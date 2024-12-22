#ifndef MANAGEMENTKARYAWAN_H
#define MANAGEMENTKARYAWAN_H

#include <iostream>
#include <string>
#include <array>

template <typename T, size_t N>
class Karyawan {
public:
    std::array<T, N> idKaryawan;
    std::array<std::string, N> namaKaryawan;
    std::array<std::string, N> jabatanKaryawan;
    std::array<std::string, N> noHpKaryawan;
};

class ManagementKaryawanMenu {
public:
    static void displayMenu() {
        Karyawan<int, 5> karyawan;

        // Inisialisasi daftar karyawan
        karyawan.idKaryawan = {101, 102, 103, 104, 105};
        karyawan.namaKaryawan = {"Alice", "Bob", "Charlie", "David", "Eve"};
        karyawan.jabatanKaryawan = {"Apoteker", "Asisten Apoteker", "Kasir", "Staf", "Staf"};
        karyawan.noHpKaryawan = {"1234567890", "9876543210", "5555555555", "9999999999", "1111111111"};

        while (true) {
            std::cout << "\n===== Management Karyawan =====" << std::endl;
            std::cout << "1. Tampilkan Daftar Karyawan" << std::endl;
            std::cout << "2. Sorting Berdasarkan Nama" << std::endl;
            std::cout << "3. Cari Nama Karyawan" << std::endl;
            std::cout << "4. Keluar" << std::endl;
            std::cout << "Pilih menu: ";

            int menu;
            std::cin >> menu;

            switch (menu) {
                case 1: // Tampilkan Daftar Karyawan
                    tampilkanDaftarKaryawan(karyawan);
                    break;
                case 2: // Sorting Berdasarkan Nama
                    sortingBerdasarkanNama(karyawan);
                    break;
                case 3: // Cari Nama Karyawan
                    cariNamaKaryawan(karyawan);
                    break;
                case 4: // Keluar
                    return;
                default:
                    std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
            }
        }
    }

private:
    static void tampilkanDaftarKaryawan(const Karyawan<int, 5>& karyawan) {
        std::cout << "\nDaftar Karyawan:" << std::endl;
        for (size_t i = 0; i < karyawan.idKaryawan.size(); i++) {
            std::cout << "ID: " << karyawan.idKaryawan[i] << ", Nama: " << karyawan.namaKaryawan[i] << ", Jabatan: " << karyawan.jabatanKaryawan[i] << ", No. HP: " << karyawan.noHpKaryawan[i] << std::endl;
        }
    }

    static void sortingBerdasarkanNama(Karyawan<int, 5>& karyawan) {
        mergeSort(karyawan, 0, karyawan.namaKaryawan.size() - 1);

        std::cout << "\nDaftar Karyawan (Setelah Sorting):" << std::endl;
        for (size_t i = 0; i < karyawan.idKaryawan.size(); i++) {
            std::cout << "ID: " << karyawan.idKaryawan[i] << ", Nama: " << karyawan.namaKaryawan[i] << ", Jabatan: " << karyawan.jabatanKaryawan[i] << ", No. HP: " << karyawan.noHpKaryawan[i] << std::endl;
        }
    }

    static void cariNamaKaryawan(const Karyawan<int, 5>& karyawan) {
        std::string namaDicari;
        std::cout << "Masukkan nama karyawan yang dicari: ";
        std::cin >> namaDicari;

        bool ditemukan = false;

        for (size_t i = 0; i < karyawan.idKaryawan.size(); i++) {
            if (karyawan.namaKaryawan[i] == namaDicari) {
                std::cout << "Karyawan ditemukan - ID: " << karyawan.idKaryawan[i] << ", Nama: " << karyawan.namaKaryawan[i] << ", Jabatan: " << karyawan.jabatanKaryawan[i] << ", No. HP: " << karyawan.noHpKaryawan[i] << std::endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            std::cout << "Karyawan dengan nama '" << namaDicari << "' tidak ditemukan." << std::endl;
        }
    }

    static void merge(Karyawan<int, 5>& karyawan, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        Karyawan<int, 5> L, R;

        for (int i = 0; i < n1; i++) {
            L.idKaryawan[i] = karyawan.idKaryawan[left + i];
            L.namaKaryawan[i] = karyawan.namaKaryawan[left + i];
            L.jabatanKaryawan[i] = karyawan.jabatanKaryawan[left + i];
            L.noHpKaryawan[i] = karyawan.noHpKaryawan[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R.idKaryawan[j] = karyawan.idKaryawan[middle + 1 + j];
            R.namaKaryawan[j] = karyawan.namaKaryawan[middle + 1 + j];
            R.jabatanKaryawan[j] = karyawan.jabatanKaryawan[middle + 1 + j];
            R.noHpKaryawan[j] = karyawan.noHpKaryawan[middle + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L.namaKaryawan[i] <= R.namaKaryawan[j]) {
                karyawan.idKaryawan[k] = L.idKaryawan[i];
                karyawan.namaKaryawan[k] = L.namaKaryawan[i];
                karyawan.jabatanKaryawan[k] = L.jabatanKaryawan[i];
                karyawan.noHpKaryawan[k] = L.noHpKaryawan[i];
                i++;
            } else {
                karyawan.idKaryawan[k] = R.idKaryawan[j];
                karyawan.namaKaryawan[k] = R.namaKaryawan[j];
                karyawan.jabatanKaryawan[k] = R.jabatanKaryawan[j];
                karyawan.noHpKaryawan[k] = R.noHpKaryawan[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            karyawan.idKaryawan[k] = L.idKaryawan[i];
            karyawan.namaKaryawan[k] = L.namaKaryawan[i];
            karyawan.jabatanKaryawan[k] = L.jabatanKaryawan[i];
            karyawan.noHpKaryawan[k] = L.noHpKaryawan[i];
            i++;
            k++;
        }

        while (j < n2) {
            karyawan.idKaryawan[k] = R.idKaryawan[j];
            karyawan.namaKaryawan[k] = R.namaKaryawan[j];
            karyawan.jabatanKaryawan[k] = R.jabatanKaryawan[j];
            karyawan.noHpKaryawan[k] = R.noHpKaryawan[j];
            j++;
            k++;
        }
    }

    static void mergeSort(Karyawan<int, 5>& karyawan, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            mergeSort(karyawan, left, middle);
            mergeSort(karyawan, middle + 1, right);

            merge(karyawan, left, middle, right);
        }
    }
};

#endif