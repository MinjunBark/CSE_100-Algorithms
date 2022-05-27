#include <iostream> 
using namespace std;

// MaxSub array via divide and conquer 
// example:
//     input : 6
//         {-3,11,-2,-3,10,-5}
//     output : 16

int MaxSubArray(int arr[], int size){
    int maxi = arr[0]; // creating indices at arr[0]
    int sum = arr[0]; 

    for(int i = 1; i < size; i++){ //starting from index 1 
        sum = max(arr[i], sum + arr[i]); //add starting from greatest positive number in array and add till it reaches to greatest positive number
        maxi = max(maxi, sum); //return maximum integer in array from sum 
    }
    return maxi;

}

int main (){
    //user_input
    int user_input;
    cin >> user_input;
    int arr[user_input];

    for(int i = 0; i < user_input; i++){
        cin >> arr[i];
    }
    //creating print function
    int print_max = MaxSubArray(arr,user_input); 
    cout << print_max;
    

    return 0;
}