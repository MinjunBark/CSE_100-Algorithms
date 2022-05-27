#include <iostream> 
using namespace std;

void Merge(int arr[], int left, int mid, int right){
    //creating subarray 
    //splitting array into 2 
    int n1 = mid - left + 1;
    int n2=  right - mid;
    //creating temp array
    int tempArr1[n1]; // left array
    int tempArr2[n2]; // right array
    //indexs for subarrays
    int i, j, k;
    //copying the splitting array into the temp subarrays
    for(i = 0; i < n1; i++){
        tempArr1[i] = arr[left + i];
    }
    for( j = 0; j < n2; j++){
        tempArr2[j] = arr[mid + 1 + j];
    }
    i = 0; // index of left subarray
    j = 0; // index of right subarray
    k = left; // index of merged array
    //
    while (i < n1 && j < n2){ //merging temparrays back to array
        if (tempArr1[i] <= tempArr2[j]){
            arr[k] = tempArr1[i];
            i++;
        }
        else{
            arr[k] = tempArr2[j];
            j++;
        }
        k++;
    }
    //merging the temparray back to array
    while(i < n1){ //copying remaining elements of left
        arr[k] = tempArr1[i];
        i++;
        k++;    
    }
    while (j < n2){//copying right
        arr[k] = tempArr2[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int left, int right){
    if(left < right ){
        int mid = left + (right-left) / 2;
    
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1, right);
        Merge(arr,left,mid,right);
    }
}

void printArray(int arr[], int size){ //printing array
    for(int i = 0; i < size; i ++){
        cout << arr[i] << ";";
    }
}



int main () {
    int user_input;
    cin >> user_input;
    int arr[user_input];
    for(int i = 0; i < user_input; i++) {
            cin >> arr[i];
    }
    // cout <<"Before" << endl;
    // printArray(arr,user_input);
    mergeSort(arr, 0, user_input - 1);
    // cout << "After" << endl;
    printArray(arr, user_input);

    return 0;
}