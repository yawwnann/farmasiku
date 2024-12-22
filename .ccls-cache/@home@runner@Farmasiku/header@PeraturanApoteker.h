#include <iostream>
#include <stack>
using namespace std;

class PeraturanApotekerMenu {
public:
  static void displayMenu() {
    while (true) {
      cout << "\n===== Peraturan Apoteker =====" << endl;
      cout << "1. Peraturan dalam Bekerja" << endl;
      cout << "2. Peraturan dalam Melayani" << endl;
      cout << "3. Keluar" << endl;
      cout << "Pilih menu: ";

      int menu;
      cin >> menu;

      switch (menu) {
      case 1:
        peraturanDalamBekerja();
        break;
      case 2:
        peraturanDalamMelayani();
        break;
      case 3:
        return;
      default:
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
      }
    }
  }

private:
  static void peraturanDalamBekerja() {
    stack<string> peraturanBekerja; // Stack untuk peraturan bekerja

    peraturanBekerja.push("1. Selalu periksa keaslian resep sebelum memberikan "
                          "obat kepada pasien.");
    peraturanBekerja.push("2. Pastikan obat disimpan dengan baik dan sesuai "
                          "peraturan penyimpanan.");
    peraturanBekerja.push("3. Apoteker harus menjaga tingkat etika dan "
                          "profesionalisme yang tinggi dalam semua interaksi "
                          "dengan pasien, pelanggan, dan rekan kerja.");
    peraturanBekerja.push(
        "4. Apoteker harus selalu mengutamakan kesejahteraan pasien dan "
        "menjaga kerahasiaan informasi kesehatan pasien.");
    peraturanBekerja.push(
        "5. Apoteker harus memastikan bahwa obat yang dijual di apotek adalah "
        "berkualitas tinggi, bebas dari kontaminasi, dan sesuai dengan standar "
        "kesehatan yang berlaku.");
    peraturanBekerja.push(
        "6. Apoteker harus menjaga stok obat agar tetap dalam kondisi yang "
        "baik dan bebas dari kerusakan atau kadar yang kadaluarsa.");
    peraturanBekerja.push(
        "7. Obat harus disimpan sesuai dengan petunjuk penyimpanan yang tepat, "
        "seperti suhu, kelembaban, dan pencahayaan yang sesuai.");
    peraturanBekerja.push("8. Apoteker harus memeriksa resep dari dokter "
                          "sebelum mengeluarkan obat kepada pasien.");
    peraturanBekerja.push(
        "9. Apoteker harus memberikan instruksi kepada pasien tentang "
        "penggunaan obat, dosis yang benar, dan potensi efek samping.");
    peraturanBekerja.push(
        "10. Apoteker harus memberikan konsultasi dan informasi yang jelas "
        "kepada pasien tentang obat, dosis, dan aturan minum obat.");
    peraturanBekerja.push("11. Apoteker harus menjaga kebersihan dan keamanan "
                          "di lingkungan apotek.");
    peraturanBekerja.push(
        "12. Apoteker harus memastikan bahwa peralatan dan perangkat medis "
        "yang digunakan steril dan terawat dengan baik.");
    peraturanBekerja.push(
        "13. Apoteker harus melaporkan efek samping obat kepada otoritas yang "
        "berwenang sesuai dengan peraturan yang berlaku.");
    peraturanBekerja.push("14. Apoteker harus terus meningkatkan pengetahuan "
                          "dan keterampilan mereka melalui pendidikan dan "
                          "pelatihan yang berkaitan dengan farmasi.");
    peraturanBekerja.push(
        "15. Apoteker harus mematuhi semua hukum dan peraturan yang berlaku "
        "dalam praktik farmasi dan penjualan obat.");
    peraturanBekerja.push(
        "16. Apoteker harus menjaga catatan yang akurat tentang persediaan "
        "obat, resep, dan interaksi dengan pasien.");

    cout << "===== Peraturan dalam Bekerja =====" << endl;
    while (!peraturanBekerja.empty()) {
      cout << peraturanBekerja.top() << endl;
      peraturanBekerja.pop();
    }
  }

  static void peraturanDalamMelayani() {
    stack<string> peraturanMelayani; // Stack untuk peraturan melayani

    peraturanMelayani.push("1. Apoteker harus memberikan sambutan ramah dan "
                           "sopan kepada setiap pasien yang datang ke apotek.");
    peraturanMelayani.push(
        "2. Apoteker harus bersikap sabar dan mendengarkan dengan cermat "
        "setiap pertanyaan atau kebutuhan yang disampaikan oleh pasien.");
    peraturanMelayani.push(
        "3. Apoteker harus menjaga kerahasiaan informasi pribadi pasien, "
        "termasuk informasi medis dan obat-obatan yang digunakan.");
    peraturanMelayani.push("4. Apoteker harus menghindari pembicaraan tentang "
                           "pasien dengan orang lain tanpa izin pasien.");
    peraturanMelayani.push(
        "5. Apoteker harus melakukan konsultasi yang komprehensif dengan "
        "setiap pasien yang mengambil obat atau vitamin.");
    peraturanMelayani.push(
        "6. Apoteker harus menjelaskan dengan jelas dosis obat, efek samping "
        "yang mungkin terjadi, dan cara penggunaan yang benar.");
    peraturanMelayani.push("7. Apoteker harus bersedia menjawab semua "
                           "pertanyaan pasien dengan jelas dan informatif.");
    peraturanMelayani.push(
        "8. Apoteker harus memberikan penjelasan tambahan tentang obat atau "
        "vitamin jika diminta oleh pasien.");
    peraturanMelayani.push(
        "9. Apoteker harus mengidentifikasi potensi interaksi obat jika pasien "
        "menggunakan beberapa obat sekaligus.");
    peraturanMelayani.push(
        "10. Apoteker harus memberi tahu pasien tentang risiko interaksi obat "
        "dan memberikan saran jika diperlukan.");
    peraturanMelayani.push(
        "11. Apoteker harus mematuhi semua hukum dan peraturan yang berlaku "
        "dalam layanan farmasi dan kepatuhan terhadap resep dokter.");
    peraturanMelayani.push(
        "12. Apoteker harus merespons dengan cepat dan profesional terhadap "
        "keluhan atau masukan dari pasien.");
    peraturanMelayani.push(
        "13. Keluhan pasien harus didokumentasikan dan diurus dengan baik.");
    peraturanMelayani.push(
        "14. Apoteker harus menjaga apotek dalam keadaan bersih dan teratur "
        "untuk memastikan kenyamanan pasien.");
    peraturanMelayani.push(
        "15. Apoteker harus memberikan penyuluhan kesehatan tambahan jika "
        "diperlukan, seperti tentang makanan seimbang, gaya hidup sehat, atau "
        "perawatan penyakit tertentu.");

    cout << "===== Peraturan dalam Melayani =====" << endl;
    while (!peraturanMelayani.empty()) {
      cout << peraturanMelayani.top() << endl;
      peraturanMelayani.pop();
    }
  }
};