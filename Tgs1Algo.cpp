#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    string kode;
    float rating;
    float harga;
};

struct Bioskop {
    string nama;
    Film* film;
    int jumlahFilm;
};

string tampilkanFilm(Film* film, int n) {
    string output = "Data Film:\n";
    for (int i = 0; i < n; i++) {
        output += "Kode: " + film[i].kode + ", Judul: " + film[i].judul + ", Rating: " + to_string(film[i].rating) + ", Harga: Rp" + to_string(film[i].harga) + "\n";
    }
    return output;
}

int sequentialSearch(Film* film, int n, string kode) {
    for (int i = 0; i < n; i++) {
        if (film[i].kode == kode)
            return i;
    }
    return -1;
}

int binarySearch(Film* film, int left, int right, string judul) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (film[mid].judul == judul)
            return mid;
        if (film[mid].judul < judul)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

Film* quickSort(Film* film, int left, int right) {
    if (left >= right) return film;
    int i = left, j = right;
    float pivot = film[(left + right) / 2].rating;

    while (i <= j) {
        while (film[i].rating < pivot) i++;
        while (film[j].rating > pivot) j--;
        if (i <= j) {
            swap(film[i], film[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(film, left, j);
    if (i < right) quickSort(film, i, right);
    return film;
}

Film* bubbleSort(Film* film, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (film[j].rating < film[j + 1].rating) {
                swap(film[j], film[j + 1]);
            }
        }
    }
    return film;
}

int main() {
    Bioskop bioskop = {"Grand Indonesia", nullptr, 5};
    Film daftarFilm[5] = {
        {"Badak Siluman", "BS001", 8.500000, 50.000000},
        {"Kodok Zuma", "KZ002", 7.800000, 45.000000},
        {"Hijau Lembayung", "HL003", 9.000000, 55.000000},
        {"Cobra Janda", "CJ004", 8.200000, 48.000000},
        {"Pawang Bekantan", "PB005", 8.800000, 52.000000}
    };
    bioskop.film = daftarFilm;

    cout << "Bioskop: " << bioskop.nama << "\n";
    
    int pilihan;
    do {
        cout << "\n========== Menu ==========\n";
        cout << "1. Tampilkan Data Film\n";
        cout << "2. Cari Film berdasarkan Kode\n";
        cout << "3. Urutkan Rating (Quick Sort)\n";
        cout << "4. Urutkan Rating (Bubble Sort)\n";
        cout << "5. Cari Film berdasarkan Judul (Binary Search)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << tampilkanFilm(bioskop.film, bioskop.jumlahFilm);
                break;
            case 2: {
                string kodeCari;
                cout << "Masukkan kode film: ";
                getline(cin, kodeCari);
                int result = sequentialSearch(bioskop.film, bioskop.jumlahFilm, kodeCari);
                if (result != -1)
                    cout << "Film ditemukan: " << bioskop.film[result].judul << " dengan harga Rp" << bioskop.film[result].harga << "\n";
                else
                    cout << "Film tidak ditemukan.\n";
                break;
            }
            case 3:
                quickSort(bioskop.film, 0, bioskop.jumlahFilm - 1);
                cout << "Setelah Quick Sort Ascending berdasarkan Rating:\n" << tampilkanFilm(bioskop.film, bioskop.jumlahFilm);
                break;
            case 4:
                bubbleSort(bioskop.film, bioskop.jumlahFilm);
                cout << "Setelah Bubble Sort Descending berdasarkan Rating:\n" << tampilkanFilm(bioskop.film, bioskop.jumlahFilm);
                break;
            case 5: {
                string judulCari;
                cout << "Masukkan judul film: ";
                getline(cin, judulCari);
                int result = binarySearch(bioskop.film, 0, bioskop.jumlahFilm - 1, judulCari);
                if (result != -1)
                    cout << "Film ditemukan: " << bioskop.film[result].judul << " dengan harga Rp" << bioskop.film[result].harga << "\n";
                else
                    cout << "Film tidak ditemukan.\n";
                break;
            }
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
