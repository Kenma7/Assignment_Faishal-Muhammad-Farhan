#include <iostream>
#include <cstring>
using namespace std;

const int MAX_MAHASISWA = 26;

struct Nilai {
    int absen;
    int tugas;
    int uts;
    int uas;
};

struct Mahasiswa {
    char nama[50];
    long long npm;
    Nilai nilai;
    float nilaiAkhir;
    char indexNilai;
};

void hitungNilai(Mahasiswa &mhs) {
    mhs.nilaiAkhir = 0.1 * mhs.nilai.absen + 0.2 * mhs.nilai.tugas + 0.3 * mhs.nilai.uts + 0.4 * mhs.nilai.uas;
    if (mhs.nilaiAkhir > 80)
        mhs.indexNilai = 'A';
    else if (mhs.nilaiAkhir > 70)
        mhs.indexNilai = 'B';
    else if (mhs.nilaiAkhir > 60)
        mhs.indexNilai = 'C';
    else
        mhs.indexNilai = 'D';
}

int main() {
    Mahasiswa arrMahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;

    char menu;
    do {
        cout << "Menu: \n";
        cout << "C. Input data mahasiswa \n";
        cout << "R. Menampilkan data mahasiswa \n";
        cout << "U. Edit data mahasiswa \n";
        cout << "D. Hapus data mahasiswa \n";
        cout << "X. Keluar \n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 'C': {
                system("cls");

                if (jumlahMahasiswa < MAX_MAHASISWA) {
                    Mahasiswa mhs;
                    cout << "-- Masukkan biodata Mahasiswa -- \n\n";
                    cout << "Masukan Nama: ";
                    cin.ignore();
                    cin.getline(mhs.nama, sizeof(mhs.nama));
                    cout << "Masukan NPM: ";
                    cin >> mhs.npm;
                    cout << "Masukan Absen: ";
                    cin >> mhs.nilai.absen;
                    cout << "Masukan nilai Tugas: ";
                    cin >> mhs.nilai.tugas;
                    cout << "Masukan nilai UTS: ";
                    cin >> mhs.nilai.uts;
                    cout << "Masukan nilai UAS: ";
                    cin >> mhs.nilai.uas;

                    hitungNilai(mhs);

                    arrMahasiswa[jumlahMahasiswa++] = mhs;

                    system("cls");

                    cout << "Data mahasiswa berhasil ditambahkan! \n\n";
                } else {
                    cout << "Kapasitas mahasiswa penuh! \n\n";
                }
                break;
            }
            case 'R': {
                 system("cls");

                  cout << "Data Mahasiswa: \n";
                  cout << "---------------------------------------------- \n";
                  cout << "No\tNama\tNPM\tNilai Akhir\tIndex Nilai \n";
                  cout << "---------------------------------------------- \n";
                     for (int i = 0; i < jumlahMahasiswa; ++i) {
    cout << i + 1 << "\t" << arrMahasiswa[i].nama << "\t" << arrMahasiswa[i].npm << "\t" << arrMahasiswa[i].nilaiAkhir << "\t\t" << arrMahasiswa[i].indexNilai <<endl;
                     }
                  cout << "---------------------------------------------- \n";
                     break;
                    }
            case 'U': {
                system("cls");

                long long npm;
                cout << "Masukkan NPM mahasiswa yang ingin diubah: ";
                cin >> npm;
                bool found = false;
                for (int i = 0; i < jumlahMahasiswa; ++i) {
                    if (arrMahasiswa[i].npm == npm) {
                        cout << "Masukan Nama: ";
                        cin.ignore();
                        cin.getline(arrMahasiswa[i].nama, sizeof(arrMahasiswa[i].nama));
                        cout << "Masukan NPM: ";
                        cin >> arrMahasiswa[i].npm;
                        cout << "Masukan Absen: ";
                        cin >> arrMahasiswa[i].nilai.absen;
                        cout << "Masukan nilai Tugas: ";
                        cin >> arrMahasiswa[i].nilai.tugas;
                        cout << "Masukan nilai UTS: ";
                        cin >> arrMahasiswa[i].nilai.uts;
                        cout << "Masukian nilai UAS: ";
                        cin >> arrMahasiswa[i].nilai.uas;

                        hitungNilai(arrMahasiswa[i]);

                        system("cls");

                        cout << "Data mahasiswa berhasil diubah! \n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Data mahasiswa dengan NPM tersebut tidak ditemukan! \n";
                }
                break;
            }
            case 'D': {
                system("cls");
                long long npm;
                cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                cin >> npm;
                bool found = false;
                for (int i = 0; i < jumlahMahasiswa; ++i) {
                    if (arrMahasiswa[i].npm == npm) {
                        for (int j = i; j < jumlahMahasiswa - 1; ++j) {
                            arrMahasiswa[j] = arrMahasiswa[j + 1];
                        }
                        jumlahMahasiswa--;
                        system("cls");
                        cout << "Data mahasiswa berhasil dihapus! \n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Data mahasiswa dengan NPM tersebut tidak ditemukan! \n";
                }
                break;
            }
            case 'X': {
                cout << "====================================================================\n";
                cout << "Program ini dibuat oleh : Faishal Muhammad Farhan (2310631170135) \n";
                cout << "====================================================================\n";
                break;
            }
            default: {
                cout << "Menu tidak valid! \n";
                break;
            }
        }
    } while (menu != 'X');

    return 0;
}