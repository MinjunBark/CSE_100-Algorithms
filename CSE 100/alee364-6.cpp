#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> v[], int size, int r){ 
    vector<int> B[size];
   // B = new vector<int>[size];
    int i,j;
    int k = 10;
    int C[k];

    for(i = 0; i < k; i++){ // initialzing count[10] = 0 setting the elements to all start off as 0 
        C[i]= 0;
    }

    for(j = 0; j < size; j++){ // inspects each input elements (tallying)
        vector<int> x = v[j]; // increment c[j]++ 
        int c= x[r];
        C[c] = C[c] + 1;
    }
    
    for(i = 1; i < k; i++){ //add the previous element to the current element 
        C[i] = C[i] + C[i-1];
    }

    for(j = size - 1; j >= 0; j--){ //putting each element in vector B and sorting into final position
        B[C[v[j][r]]-1] = v[j];
        C[v[j][r]] = C[v[j][r]] - 1;
    }
    for(i = 0; i < size; i ++){
        v[i] = B[i];
    }
}

void RadixSort(vector<int> v[], int size){
    for(int r = 9; r >= 0; r--){
        CountingSort(v,size,r);
    }
}

void PrintArr(vector<int> v[], int size){
    for(int i = 0; i < size; i++ ){
        for(int j = 0; j < 10; j++){
            cout << v[i][j] << ";" ;
        }
          cout << endl;
    }
}

int main () {
    int size; 
    cin >> size;
    int i,j;
    vector<int> v[size+1];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
        int size2;
        cin >> size2;
        v[i].push_back(size2);
        }
    }
    RadixSort(v,size);
    PrintArr(v,size);

    return 0 ;
}