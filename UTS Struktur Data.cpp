#include <iostream>
#include <string>
using namespace std;

struct NilaiMhs {
    int nilaiAbsen;
    int nilaiTugas;
    int nilaiUTS;
    int nilaiUAS;
    char nilaiHuruf;
};

struct Mahasiswa {
    char nama[50];
    string NPM;
    char kelas;
    NilaiMhs nilai;

    Mahasiswa *next, *prev;
};

Mahasiswa *head = NULL, *tail = NULL, *baru, *bantu, *sementara;

void inputDataMahasiswa() {
    system("cls");
    baru = new Mahasiswa();
    baru->next = NULL;
    baru->prev = NULL;
    
    cout << "Pakai underscore jika lebih dari 1 kata." << endl;
    cout << "Nama mahasiswa : "; cin >> baru->nama;
    cout << "NPM mahasiswa : "; cin >> baru->NPM;
    cout << "Kelas mahasiswa : "; cin >> baru->kelas; baru->kelas = toupper(baru->kelas);
    cout << "Nilai absen mahasiswa: "; cin >> baru->nilai.nilaiAbsen;
    cout << "Nilai tugas mahasiswa : "; cin >> baru->nilai.nilaiTugas;
    cout << "Nilai UTS mahasiswa : "; cin >> baru->nilai.nilaiUTS;
    cout << "Nilai UAS mahasiswa : "; cin >> baru->nilai.nilaiUAS;

    int nilaiAbsen = baru->nilai.nilaiAbsen;
    int nilaiTugas = baru->nilai.nilaiTugas;
    int nilaiUTS = baru->nilai.nilaiUTS;
    int nilaiUAS = baru->nilai.nilaiUAS;

    float nilaiAkhir = (nilaiAbsen * 10/100) + (nilaiTugas * 20/100) + (nilaiUTS * 30/100) + (nilaiUAS * 40/100);

    if(nilaiAkhir > 80) {
        baru->nilai.nilaiHuruf = 'A';
    } else if(nilaiAkhir > 70) {
        baru->nilai.nilaiHuruf = 'B';
    } else if(nilaiAkhir > 60) {
        baru->nilai.nilaiHuruf = 'C';
    } else {
        baru->nilai.nilaiHuruf = 'D';
    };

    if(head == NULL) {
        head = tail = baru;
    } else {
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
        // baru->next = head;
        // head->prev = baru;
        // head = baru;
    };
    cout << "Data berhasil ditambahkan!" << endl;
    system("pause");
};

void hapusDataMahasiswa() {
    system("cls");
    if(head == NULL) {
        cout << "Data mahasiswa masih kosong!" << endl;
        system("pause");
        return;
    };
    string NPM;
    cout << "Masukkan npm mahasiswa : "; cin >> NPM;

    if(head->NPM == NPM) {
        bantu = head;
        head = head->next;
        delete bantu;
        cout << "Data berhasil dihapus!" << endl;
        system("pause");
        return;
    }

    bantu = head;
    sementara = head->next;
    while(sementara->NPM != NPM) {
        bantu = sementara;
        sementara = sementara->next;
        if(sementara == NULL) {
            cout << "NPM tidak ditemukan!" << endl;
            system("pause");
            return;
        }
    };

    bantu->next = sementara->next;
    delete sementara;
    cout << "Data berhasil dihapus!" << endl;
    system("pause");
};

void tampilkanDataKelasMahasiswa() {
    system("cls");
    char kelas;
    bantu = head;

    if(bantu == NULL) {
        cout << "Data Mahasiswa Masih Kosong!" << endl;
        system("pause");
        return;
    }

    cout << "Masukkan kelas mahasiswa yang ingin ditampilkan : "; cin >> kelas;
    system("cls");
    cout << "\n\tData Mahasiswa" << endl;
    cout << "==============================" << endl;
    while(bantu != NULL) {
        if(bantu->kelas == toupper(kelas)) {
            cout << "Nama mahasiswa \t\t: " << bantu->nama << endl;
            cout << "NPM mahasiswa \t\t: " << bantu->NPM << endl;
            cout << "Kelas mahasiswa \t\t: " << bantu->kelas << endl;
            cout << "Nilai akhir mahasiswa \t: " << bantu->nilai.nilaiHuruf << endl << endl;
        };
        bantu = bantu->next;
    };
    system("pause");
};

void tampilkanDataMahasiswa() {
    system("cls");
    
    bantu = head;
    if(bantu == NULL) {
        cout << "Data Mahasiswa Masih Kosong!" << endl;
        system("pause");
        return;
    };
    
    cout << "\n\tData Mahasiswa" << endl;
    cout << "==============================" << endl;
    while(bantu != NULL) {
        cout << "Nama mahasiswa \t\t: " << bantu->nama << endl;
        cout << "NPM mahasiswa \t\t: " << bantu->NPM << endl;
        cout << "Kelas mahasiswa\t\t: " << bantu->kelas << endl;
        cout << "Nilai Akhir mahasiswa \t: " << bantu->nilai.nilaiHuruf << endl << endl;
        bantu = bantu->next;
    };
    system("pause");
};

int main() {
    int pilihan;

    do{
        system("cls");
        cout << "=========================================================" << endl;
        cout << "|\t\tProgram Pendataan Mahasiswa\t\t|" << endl;
        cout << "=========================================================" << endl;
        cout << "|1.| Input data mahasiswa \t\t\t\t|" << endl;
        cout << "|2.| Tampilkan semua data mahasiswa \t\t\t|" << endl;
        cout << "|3.| Tampilkan data mahasiswa berdasarkan kelas \t|" << endl;
        cout << "|4.| Hapus data mahasiswa \t\t\t\t|" << endl;
        cout << "|0.| Keluar \t\t\t\t\t\t|" << endl;
        cout << "=========================================================" << endl;
        cout << "Pilihan : ";cin >> pilihan;

        switch (pilihan) {
        case 1:
            inputDataMahasiswa();
            break;
        case 2:
            tampilkanDataMahasiswa();
            break;
        case 3: 
            tampilkanDataKelasMahasiswa();
            break;
        case 4: 
            hapusDataMahasiswa();
            break;
        case 0:
            delete head;
            break;
        default:
            cout << "Silahkan pilih opsi yang sesuai!" << endl;
            system("pause");
            break;
        }

    } while(pilihan != 0);

    cout << "Program Selesai." << endl;
    return 0;
};
