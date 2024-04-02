#include <iostream>
#include <string>

using namespace std;

struct Sparepart {
    string nama;
    int harga;
    int jumlah;
};

const int MAX_SPAREPART = 100;

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Data Sparepart\n";
    cout << "2. Lihat Data Sparepart\n";
    cout << "3. Ubah Data Sparepart\n";
    cout << "4. Hapus Data Sparepart\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

bool login(string nama, string nim) {
    return (nama == "muhammad" && nim == "2309106078");
}

void tambahDataSparepart(Sparepart spareparts[], int& totalSparepart) {
    if (totalSparepart < MAX_SPAREPART) {
        cout << "Masukkan nama sparepart: ";
        cin >> spareparts[totalSparepart].nama;
        cout << "Masukkan harga sparepart: ";
        cin >> spareparts[totalSparepart].harga;
        cout << "Masukkan jumlah sparepart: ";
        cin >> spareparts[totalSparepart].jumlah;
        totalSparepart++;
    } else {
        cout << "Array penuh, tidak dapat menambahkan data lagi.\n";
    }
}

void lihatDataSparepart(Sparepart spareparts[], const int& totalSparepart) {
    cout << "Data Pembelian Sparepart Motor:\n";
    for (int i = 0; i < totalSparepart; ++i) {
        cout << "Indeks: " << i + 1 << ", Nama: " << spareparts[i].nama << ", Harga: " << spareparts[i].harga << ", Jumlah: " << spareparts[i].jumlah << endl;
    }
}

void ubahDataSparepart(Sparepart spareparts[], const int& totalSparepart) {
    int index;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> index;
    if (index >= 1 && index <= totalSparepart) {
        cout << "Masukkan nama sparepart baru: ";
        cin >> spareparts[index - 1].nama;
        cout << "Masukkan harga sparepart baru: ";
        cin >> spareparts[index - 1].harga;
        cout << "Masukkan jumlah sparepart baru: ";
        cin >> spareparts[index - 1].jumlah;
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

void hapusDataSparepart(Sparepart spareparts[], int& totalSparepart) {
    int deleteIndex;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> deleteIndex;
    if (deleteIndex >= 1 && deleteIndex <= totalSparepart) {
        for (int i = deleteIndex - 1; i < totalSparepart - 1; ++i) {
            spareparts[i] = spareparts[i + 1];
        }
        totalSparepart--;
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

void loginDenganDereference(bool& sudahLogin, int& salahLogin) {
    string nama, nim;
    while (!sudahLogin && salahLogin < 3) {
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        sudahLogin = login(nama, nim);
        if (!sudahLogin) {
            salahLogin++;
            cout << "Login gagal. Silakan coba lagi.\n";
        }
    }

    if (!sudahLogin) {
        cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
    }
}

void tambahDataSparepartDenganAddress(Sparepart spareparts[], int* totalSparepart) {
    if (*totalSparepart < MAX_SPAREPART) {
        cout << "Masukkan nama sparepart: ";
        cin >> spareparts[*totalSparepart].nama;
        cout << "Masukkan harga sparepart: ";
        cin >> spareparts[*totalSparepart].harga;
        cout << "Masukkan jumlah sparepart: ";
        cin >> spareparts[*totalSparepart].jumlah;
        (*totalSparepart)++;
    } else {
        cout << "Array penuh, tidak dapat menambahkan data lagi.\n";
    }
}

int main() {
    bool sudahLogin = false;
    int salahLogin = 0;
    Sparepart spareparts[MAX_SPAREPART];
    int totalSparepart = 0;

    loginDenganDereference(sudahLogin, salahLogin);

    if (!sudahLogin) {
        return 0;
    }

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataSparepart(spareparts, totalSparepart);
                break;
            case 2:
                lihatDataSparepart(spareparts, totalSparepart);
                break;
            case 3:
                ubahDataSparepart(spareparts, totalSparepart);
                break;
            case 4:
                hapusDataSparepart(spareparts, totalSparepart);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

return 0;
}