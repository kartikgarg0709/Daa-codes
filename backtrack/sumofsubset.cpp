#include<iostream>
using namespace std;
int w[5]={0,3,5,6,7};
int m=15;
int x[5]={0,0,0,0,0};
void sumofsubset(int s,int k,int r){
    x[k]=1;
    if(s+w[k]==m){
        for(int i=0;i<=4;i++){
            cout<<x[i]<<"  ";
        }
    }
    else if(s+w[k]+w[k+1]<=m){
        sumofsubset(s+w[k],k+1,r-w[k]);
    }
    else if(s+w[k+1]<=m & s+r-w[k]>=m){
        x[k]=0;
        sumofsubset(s,k+1,r-w[k]);
    }
}
int main(){
    sumofsubset(0,1,21);
    return 0;
}