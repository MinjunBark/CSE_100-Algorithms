#include <iostream>
using namespace std;
//insertion sort 

void insertion_sort(int arr[], int n){ // insertion sort code
    int key;
    int j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void PrintSort(int arr[], int n){
      for(int k = 0; k < n; k++)
            cout << arr[k] << ";";
            cout << "\n";
}

int main (){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){ //input arr
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        insertion_sort(arr,i+1);
        PrintSort(arr,i+1);
    }
    // insertion_sort(arr,n);
    // PrintSort(arr,n);
    return 0;
}