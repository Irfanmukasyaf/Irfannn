#include <iostream>
using namespace std;

// int arr[] = {2,29, 25, 21, 10, 4, 100, 50, 11, 1, 99};
// int N = sizeof(arr) / sizeof(*arr);;

// int main(){
//     // Algoritma
//     for (int i=0; i < N-1; i++) { //Iterasi Ronde
//         for (int j=0; j < N-1-i; j++){
//             if (arr[j] > arr [j+1]){
//                 swap(arr[j], arr [j+1]);
//             }
//         }

//     }
//     for (int i=0; i < N; i++){
//         cout << "Isi Array: " << arr[i] << endl;
//         }
// }



void quick_sort(int array[], int awal, int akhir) {

    int low = awal, high = akhir;

    int pivot = array[(awal + akhir) / 2];

    int temp;


    do {

        while (array[low] < pivot)

            low++;

        while (array[high] > pivot)

            high--;


        if (low <= high) {

            swap(array[low], array[high]);

            low++;

            high--;

        }

    } while (low <= high);


    if (awal < high)

        quick_sort(array, awal, high);

    if (low < akhir)

        quick_sort(array, low, akhir);

}

