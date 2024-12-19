#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdint>

using namespace std;

struct Barang {
    string nama;
    int jumlah;
    double harga;
};

void tampilkanBarang(Barang barang) {
    cout << "Nama Barang: " << barang.nama << endl;
    cout << "Jumlah Stok: " << barang.jumlah << " unit" << endl;
    cout << "Harga: Rp " << barang.harga << endl;
}

void tampilkanWaktu() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Waktu sekarang: " << dt << endl;
}

void restockBarang(Barang &barang, int jumlah) {
    barang.jumlah += jumlah;
    cout << "Barang " << barang.nama << " telah di-restock sebanyak " << jumlah << " unit." << endl;
}

int main() {
    Barang tehBotol = {"Teh Botol", 50, 3000.0};
    Barang indomie = {"Indomie", 100, 2500.0};
    string namaBarang;
    int jumlahRestock;
    int pilihan;

    do {
        cout << "Pilih opsi:\n";
        cout << "1. Restock barang\n";
        cout << "2. Tampilkan waktu\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama barang: ";
                cin >> namaBarang;
                cout << "Masukkan jumlah restock: ";
                cin >> jumlahRestock;

                if (namaBarang == "Teh Botol") {
                    restockBarang(tehBotol, jumlahRestock);
                    tampilkanWaktu();
                } else if (namaBarang == "Indomie") {
                    restockBarang(indomie, jumlahRestock);
                    tampilkanWaktu();
                } else {
                    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan.\n";
                }
                break;
            case 2:
                tampilkanWaktu();
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
