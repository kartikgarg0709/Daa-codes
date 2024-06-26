#include<iostream>
using namespace std;
int x[4]={0};
bool place(int k,int i){
    for (int j=1;j<=k-1;j++){
        if (x[j]==i || abs(x[j]-i)==abs(j-k))
        return false;
        
    }
    return true;
}

void nqueen(int k,int n){
    for (int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if (k==n){
                for(int j=1;j<=n;j++){
                    cout<<x[j]<<"  ";
                }
            }
            else nqueen(k+1,n);
        }
    }
}
int main(){
    nqueen(1,4);
}