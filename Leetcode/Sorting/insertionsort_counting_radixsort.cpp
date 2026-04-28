#include <iostream>
#include <vector>
using namespace std;


int getMax(int arr[], int n){
    int maximum = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>arr[maximum]){
            maximum=i;
        }
    }
    return arr[maximum];
}

void countingsort(int arr[] , int n ,int exp){

    vector<int> output(n);

    int count[10]={0};
    //take the count
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    //prefix sum
    for(int i=1;i<n;i++){
        count[i]+=count[i-1];
    }
    //start from end and place in output in properposition
    for(int i=n-1;i>=0 ;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    
}


void radixsort(int arr[], int n){

    //getMax to set the range of output
    int m = getMax(arr,n);



    //send exp to counting sort
    for(int exp=1; m/exp>0; exp*=10){
        countingsort(arr,n,exp);
    } 
    //so at first it deals with 0th index then 1 and so on...


}

int main(){
    int arr[]= {12, 11, 13, 5, 6};
    int n= sizeof(arr)/sizeof(arr[0]);  
    
    radixsort(arr, n);
 
    cout << "Sorted array: \n";
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}