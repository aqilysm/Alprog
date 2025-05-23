#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    Buku* prev;
    Buku* next;
};

Buku* head = nullptr;
Buku* tail = nullptr;

Buku* buatNode(string judul, string penulis) {
    Buku* baru = new Buku;
    baru->judul = judul;
    baru->penulis = penulis;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}

void tambahDepan(string judul, string penulis) {
    Buku* baru = buatNode(judul, penulis);
    if (!head) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Buku berhasil ditambahkan di depan.\n";
}

void tambahBelakang(string judul, string penulis) {
    Buku* baru = buatNode(judul, penulis);
    if (!tail) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Buku berhasil ditambahkan di belakang.\n";
}

void tampilkanBuku() {
    if (!head) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    Buku* temp = head;
    cout << "\nDaftar Buku:\n";
    while (temp) {
        cout << "- Judul: " << temp->judul << ", Penulis: " << temp->penulis << endl;
        temp = temp->next;
    }
}

void hapusBuku(string judul) {
    if (!head) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    Buku* temp = head;
    while (temp && temp->judul != judul) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Buku tidak ditemukan.\n";
        return;
    }

    if (temp == head && temp == tail) {
        head = tail = nullptr;
    } else if (temp == head) {
        head = head->next;
        if (head) head->prev = nullptr;
    } else if (temp == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Buku berhasil dihapus.\n";
}
int main() {
    int pilihan;
    string judul, penulis;

    do {
        cout << "\n=== Menu Daftar Buku ===\n";
        cout << "1. Tambah Buku di Depan\n";
        cout << "2. Tambah Buku di Belakang\n";
        cout << "3. Hapus Buku berdasarkan Judul\n";
        cout << "4. Tampilkan Daftar Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                tambahDepan(judul, penulis);
                break;
            case 2:
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                tambahBelakang(judul, penulis);
                break;
            case 3:
                cout << "Masukkan Judul Buku yang akan dihapus: ";
                getline(cin, judul);
                hapusBuku(judul);
                break;
            case 4:
                tampilkanBuku();
                break;
            case 5:
                cout << "Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}