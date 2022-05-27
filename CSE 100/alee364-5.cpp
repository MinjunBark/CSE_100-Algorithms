#include <iostream>

using namespace std;
// Quicksort 
// Ex: input:6
// 5,3,2,,1,6,4
// output:
// 1;2;3;4;5;6;
void swap(int *a, int *b){ //swap two elements 
    int c = *a;
    *a = *b;
    *b = c;
}
//x splits p and r into two halves. p < x && r > x 
int Partition(int arr[], int p, int r){ // p = low / r = high / x =pivot 
    int x = arr[r]; //x = pivot 
    int i = p - 1; // i = index of smaller element

    for(int j = p; j <= r - 1; j++){  //for every element smaller than x(pivot) j increments. 
        if(arr[j] <= x){   // if element is greater than x(pivot) i increments
            i++;               //Note* if and element is greater than pivot take no action as j increments
            swap(arr[i],arr[j]); //therefore swap i -> j to place elements in correct position
        }
    }
    swap(arr[i+1],arr[r]); //once passed through all elements in array swap x(pivot) to the correct position
    return i+1;
}

void QuickSort(int arr[], int p, int r){
    if(p < r){
        int q = Partition(arr,p,r); // q = partion index 
        QuickSort(arr,p,q-1); //sorting left side 
        QuickSort(arr,q+1,r); //sorting right side 
    }
}

void printA(int arr[], int size){//print function
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
}

int main (){
    int user_input;
    cin >> user_input;
    int arr[user_input];
    for(int i = 0; i < user_input; i++){
        cin >> arr[i];
    }

    QuickSort(arr, 0, user_input -1);
    printA(arr,user_input);

    return 0;
}