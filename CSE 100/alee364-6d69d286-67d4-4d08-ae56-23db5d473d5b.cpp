#include <iostream>
using namespace std;
//matrix chain multiplication 
//2 functions

int num = 0;//counting A# 
void print_optimal(int* s, int i, int j, int size){ //shows the order of minimum number of multiplications 
    if(i == j){

        cout << "A" << num++; //A++ increment
        return;
    }
        cout << "(";
        print_optimal(s, i, *((s+i*size)+j), size); 
        print_optimal(s, *((s+i*size)+ j) + 1, j, size);
        cout << ")";
}

void Matrix_chain_Order(int p[], int size){
    int m[size][size];
    int s[size][size];

    for(int i = 1; i < size; i++){//set matrix to (0,0)
        m[i][i] = 0;
    }
    for(int l = 2; l < size; l++){ // l = chain length
        for(int i = 1; i < size - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]); //scalar multiplication
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;//split the arr for minimum cost 
                }
            }
        }
    }
    cout << m[1][size-1] << endl; //sum of matrices
    print_optimal((int*)s, 1, size-1, size); //print EX: A0, A1..(A1A2) .. etc 
    cout << endl;
}

int main(){
    int size;
    cin >> size;
    int a[size+1];

    for(int i = 0; i <= size; i++){
        cin >> a[i];
    }
    
    Matrix_chain_Order(a,size+1); //increased size 
    return 0;
}