#include <iostream>
using namespace std;

int index1 = 0; //to print the second line 
int index2 = 0;
const int index3 = -1;
//using bottom cutrod psuedo
int cutRod(int price[], int size){ // price = p // size = n
    int r[size + 1]; // r = new temp array
    r[0] = 0;

    for (int i = 1; i <= size; i++){
        int maxi = INT_MIN; //maxi = q 
        for(int j = 0; j < i; j++){
            if(maxi < max(maxi, price[j] + r[i-j-1])){
                index1 = j;
                index2 = i-j-1;
            }
            maxi = max(maxi, price[j] + r[i-j-1]);
            r[i] = maxi;
        }
    }
    return r[size];
}

int main (){
    int lengthRod;
    int key;
    cin >> lengthRod;
    int arr[lengthRod];

    for(int i = 0; i < lengthRod; i++){
        cin >> arr[i];
    }  
    cout << cutRod(arr,lengthRod) << endl; //calling max output

    //used for 2nd line of output
    if(index2 != 0){
        cout << index1 + 1 << " " << index2 << " " << index3 << endl;  
    }
    else{
        cout << index1 + 1 << " " << index3 << endl;
    }
    return 0;
}