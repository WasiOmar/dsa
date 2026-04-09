#include <iostream>
#include<vector>
using namespace std;

#define B 256
#define M 101

void rabinKarp(const string text, const string pattern){
    int s_p=pattern.length();
    int s_t=text.length();
    int h=1;//this will eventually be B^(s_p)
    //initial compute
    int s,p;
    
    for(int i=0;i<s_p;i++){
        h=B*h%M;
        s=B*(s+text[i])%M;
        p=B*(p+pattern[i])%M;
    }
    for(int i=0;i<s_t-s_p;i++){
        if(s==p){
            int j=0;
            for(int ll=0;j<s_p;j++){
                if(pattern[j]!=text[j+i]){
                    break;
                }
            }
            if (j==s_p){
                cout<<i<<endl;
            }
        }
        //recompute s
        s=((s-text[i]*h)%M+(text[i+s_p]*B%M))%M;
        if(s<0) s=s+M;
    }
}

int main(){
    rabinKarp("ABCCDDAEFG","CDD");
}