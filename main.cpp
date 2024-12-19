#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdint>

using namespace std;

// Struktur untuk menyimpan informasi barang
struct Barang {
    string nama;
    int jumlah;   // Menggunakan int biasa untuk jumlah barang
    double harga;
};

// Fungsi untuk menampilkan informasi barang
void tampilkanBarang(Barang barang) {
    cout << "Nama Barang: " << barang.nama << endl;
    cout << "Jumlah Stok: " << barang.jumlah << " unit" << endl;
    cout << "Harga: Rp " << barang.harga << endl;
}

// Fungsi untuk menambah jumlah stok barang
void restockBarang(Barang &barang, int jumlahRestock) {
    if (jumlahRestock < 0) {
        cout << "Jumlah yang di-restock tidak valid!" << endl;
        return;
    }
    barang.jumlah += jumlahRestock;
    cout << "Barang " << barang.nama << " berhasil di-restock sebanyak " << jumlahRestock << " unit." << endl;
}

// Fungsi untuk menampilkan waktu saat restock dilakukan
void tampilkanWaktu() {
    time_t now = time(0);  // Mendapatkan waktu sekarang
    char* dt = ctime(&now);  // Mengubah waktu menjadi format string
    cout << "Waktu Restock: " << dt;
}

int main() {
    // Membuat barang contoh untuk supermarket
    Barang tehBotol = {"Teh Botol", 50, 4000.0};
    Barang indomie = {"Indomie", 100, 3000.0};

    int pilihan, jumlahRestock;

    do {
        // Menampilkan menu
        cout << "\n=== Restocking Barang Supermarket ===\n";
        cout << "1. Tampilkan Daftar Barang\n";
        cout << "2. Restock Barang\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nDaftar Barang yang Tersedia:\n";
                tampilkanBarang(tehBotol);
                tampilkanBarang(indomie);
                break;
            case 2:
                // Input nama barang dan jumlah restock
                cout << "Masukkan nama barang yang ingin di-restock: ";
                cin.ignore();  // Membersihkan buffer input
                string namaBarang;
                getline(cin, namaBarang);

                cout << "Masukkan jumlah barang yang ingin di-restock: ";
                cin >> jumlahRestock;

                if (namaBarang == "Teh Botol") {
                    restockBarang(tehBotol, jumlahRestock);
                    tampilkanWaktu();  // Menampilkan waktu saat restock dilakukan
                } else if (namaBarang == "Indomie") {
                    restockBarang(indomie, jumlahRestock);
                    tampilkanWaktu();  // Menampilkan waktu saat restock dilakukan
                } else {
                    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan.\n";
                }
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

    } while (pilihan != 3);

    return 0;
}
