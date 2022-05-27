#include <iostream>
#include <queue>
#include <string>
using namespace std;

class minHeap{
    public:
        char data;
        unsigned freq; //cannot be negative
        minHeap *left;
        minHeap *right;
        
    minHeap(char data, unsigned freq){
        left = NULL;
        right = NULL;
        this -> data = data;
        this -> freq = freq;
    }
};

class compare{
    public:
        bool operator()(minHeap *left, minHeap *right){
            return (left-> freq > right->freq);
        }
};

void printHuffman(minHeap* root, string bits, char ans){
    if(!root){
        return;
    }
    if(root->data != '$'){
        if(ans == root->data){ // this allows every print to start from A,B,C ... etc
            cout << root->data << ":" << bits << endl;  // bits = codewords 
        }
    }
    printHuffman(root->left,bits + "0", ans); //left = 0 ex:000 , 00, 100....
    printHuffman(root->right, bits + "1", ans); // right = 1 
}

void HuffmanCode(char data[], int freq[], int size){
    priority_queue<minHeap*,vector<minHeap*>,compare> priorityQ;
    minHeap *left;
    minHeap *right;
    minHeap *top;

    for(int i = 0; i < size; i++){
        priorityQ.push(new minHeap(data[i], freq[i]));
    }
    while(priorityQ.size() != 1){ //extract lowest frequencies of both nodes 
        left = priorityQ.top();
        priorityQ.pop();
        right = priorityQ.top();
        priorityQ.pop();

        top = new minHeap('$', left->freq + right->freq); //adding the lowest frequencies
        top->left = left;
        top->right = right;

        priorityQ.push(top);
    }
    for(int i = 0; i < 6; i++){  //print A: B: C: ....
        printHuffman(priorityQ.top(),"",data[i]);
    }
}

int main(){
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[6];
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        cin >> freq[i];
    }
    HuffmanCode(arr,freq,size);
    return 0;
}