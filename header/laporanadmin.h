#ifndef LAPORANADMIN_H
#define LAPORANADMIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// Template class for dynamic static array
template <typename T, size_t N>
class StaticArray {
public:
    StaticArray() {
        size = 0;
    }

    bool append(const T& item) {
        if (size < N) {
            arr[size++] = item;
            return true;
        }
        return false; // Cannot append, array is full
    }

    T& operator[](size_t index) {
        if (index < size) {
            return arr[index];
        }
        // Handle index out of bounds, for simplicity, returning the first element
        return arr[0];
    }

    size_t& getSize() { // Mutable getSize()
        return size;
    }

private:
    T arr[N];
    size_t size;
};

struct AdminReport {
    string username;
    string report;
    string waktu; // Add timestamp to the report
};

class LaporanAdminMenu {
public:
    LaporanAdminMenu(const string& berkas);
    void tambahkanLaporan(const string& username, const string& report);
    void tampilkanLaporan();
    void simpanLaporanKeBerkas();
    void displayMenu();
    void hapusLaporan(const string& username);

private:
    string berkasLaporan;
    StaticArray<AdminReport, 100> dataLaporan; // Use StaticArray with a maximum capacity of 100
};

LaporanAdminMenu::LaporanAdminMenu(const string& berkas) : berkasLaporan(berkas) {
    ifstream file(berkasLaporan);
    if (file.is_open()) {
        AdminReport report;
        while (file >> report.username >> report.report >> report.waktu) {
            dataLaporan.append(report);
        }
        file.close();
    }
}

void LaporanAdminMenu::tambahkanLaporan(const string& username, const string& report) {
    AdminReport newReport;
    newReport.username = username;
    newReport.report = report;

    // Get the current time and add it to the report
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    newReport.waktu = buffer;

    dataLaporan.append(newReport);
}

void LaporanAdminMenu::tampilkanLaporan() {
    cout << "Laporan Admin:\n";
    for (size_t i = 0; i < dataLaporan.getSize(); i++) {
        const AdminReport& report = dataLaporan[i];
        cout << "Username: " << report.username << "\n";
        cout << "Waktu: " << report.waktu << "\n";
        cout << "" << report.report << "\n";
        cout << "-----------------------------\n";
    }
}

void LaporanAdminMenu::simpanLaporanKeBerkas() {
    ofstream file(berkasLaporan);
    if (file.is_open()) {
        for (size_t i = 0; i < dataLaporan.getSize(); i++) {
            const AdminReport& report = dataLaporan[i];
            file << report.username << "\n" << report.report << "\n" << report.waktu << "\n" << "--------------------------\n";
        }
        file.close();
    }
}

void LaporanAdminMenu::hapusLaporan(const string& username) {
    size_t size = dataLaporan.getSize();
    size_t i = 0;
    while (i < size) {
        if (dataLaporan[i].username == username) {
            for (size_t j = i; j < size - 1; j++) {
                dataLaporan[j] = dataLaporan[j + 1];
            }
            size--; // Decrease the size
        } else {
            i++; // Only increment if no deletion occurred
        }
    }
    // Update the size
    dataLaporan.getSize() = size; 
}

void LaporanAdminMenu::displayMenu() {
    int choice;
    string username, report;
    string kritik_saran;

    while (true) {
        cout << "Menu Admin:\n";
        cout << "1. Berikan Kritik\n";
        cout << "2. Berikan Saran\n";
        cout << "3. Tampilkan Laporan\n";
        cout << "4. Hapus Laporan\n";
        cout << "5. Simpan Laporan\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                kritik_saran = "Kritik";
                break;
            case 2:
                kritik_saran = "Saran";
                break;
            case 3:
                tampilkanLaporan();
                break;
            case 4:
                cout << "Masukkan Username untuk menghapus laporan: ";
                getline(cin, username);
                hapusLaporan(username);
                cout << "Laporan dari " << username << " telah dihapus.\n";
                break;
            case 5:
                simpanLaporanKeBerkas();
                cout << "Laporan disimpan ke berkas.\n";
                break;
            case 6:
                return;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }

        if (choice == 1 || choice == 2) {
            cout << "Masukkan Username: ";
            getline(cin, username);
            cout << "Masukkan " << kritik_saran << ": ";
            getline(cin, report);
            tambahkanLaporan(username, kritik_saran + ": " + report);
        }
    }
}

#endif