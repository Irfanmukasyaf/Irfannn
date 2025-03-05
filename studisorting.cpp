#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menampilkan daftar nama
void display(string names[], int n) {
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }
    cout << endl;
}

// Bubble Sort untuk pengurutan ascending
void bubbleSort(string names[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

// Quick Sort untuk pengurutan descending
int partition(string names[], int low, int high) {
    string pivot = names[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (names[j] > pivot) { // Untuk descending
            i++;
            swap(names[i], names[j]);
        }
    }
    swap(names[i + 1], names[high]);
    return i + 1;
}

void quickSort(string names[], int low, int high) {
    if (low < high) {
        int pi = partition(names, low, high);
        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // Menghindari masalah dengan getline setelah cin
    
    string names[n];
    cout << "Masukkan nama mahasiswa: " << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, names[i]);
    }
    
    // Copy daftar nama untuk pengurutan dengan metode berbeda
    string namesBubble[n], namesQuick[n];
    for (int i = 0; i < n; i++) {
        namesBubble[i] = names[i];
        namesQuick[i] = names[i];
    }
    
    // Pengurutan ascending dengan Bubble Sort
    bubbleSort(namesBubble, n);
    cout << "\nNama mahasiswa setelah diurutkan secara ascending (Bubble Sort):" << endl;
    display(namesBubble, n);
    
    // Pengurutan descending dengan Quick Sort
    quickSort(namesQuick, 0, n - 1);
    cout << "Nama mahasiswa setelah diurutkan secara descending (Quick Sort):" << endl;
    display(namesQuick, n);
    
    return 0;
}
