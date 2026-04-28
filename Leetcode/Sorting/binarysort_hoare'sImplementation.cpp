#include <iostream>
#include<vector>
using namespace std;


vector<int> segOddEven(vector<int> vec){
    int low=0, high=vec.size()-1;

    while(low<high){
        while(vec[low]%2==0 && low<high) low++;
        while(vec[high]%2==1 && low<high) high--;

        if(low<high){
            swap(vec[low], vec[high]);
            low++;
            high--;
        }
    }
    return vec;
}


//segregate odd and even    even first
int main(){
    vector<int> vec= {2,5,4,3,1,8,6};

    vec=segOddEven(vec);


    for(int x: vec){
        cout<<x<<" ";
    }
}