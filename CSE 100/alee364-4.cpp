#include <iostream>
using namespace std;
// HeapSort 
// EX: input :6
// 5,3,2,1,6,4

// output: 1;2;3;4;5;6;

// runtime O(nlogn)
//parent node / left node/ right node
void Heapify(int arr[], int size, int i){
    int parent = i; // initialze parent node to i 
    int left = 2 * i + 1; // left node 2i+1  
    int right = 2 * i + 2; // right node 2i + 2

    if(left < size && arr[parent] < arr[left]){ //if left_node is larger than root 
        parent = left;
    }
    if(right < size && arr[parent] < arr[right]){ //if right_node is larger than largest root
        parent = right;
    }
    if(parent != i){ //if parent_node isnt largest root, exchange 
        swap(arr[i],arr[parent]);
        Heapify(arr,size,parent);
    }
}

void HeapSort(int arr[],int size){
    int i;
    for(i = size/2 -1; i >= 0; i--){ //building heap
        Heapify(arr,size,i);
    }
    for(i = size -1; i > 0; i--){ // extracts each element 1 at a time
        swap(arr[0],arr[i]); //swap current node to end node
        Heapify(arr,i,0); //calling heapify(reduced)
    }
}

void print(int arr[], int size){ //print function 
    for (int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
}

int main (){
    int user_input;
    cin >> user_input;
    int arr[user_input];
    
    for(int i =0; i < user_input; i++){ //user_input 
        cin >> arr[i];
    }

    HeapSort(arr,user_input);
    print(arr,user_input);

    return 0;
}