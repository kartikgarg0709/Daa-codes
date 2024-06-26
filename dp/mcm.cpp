#include<iostream>
using namespace std;
void printparen(int s[][6],int i,int j){
    if (i==j)
    cout<<"A"<<i;
    else{
        cout<<"(";
        printparen(s,i,s[i][j]);
        printparen(s,s[i][j]+1,j);
        cout<<")";

    }
}

void mcm(int p[],int i){
        const int n=6;
    int m[n][n]={0};
    int s[n][n]={0};
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=1000;
            for(int k=i;k<=j-1;k++){
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (q<m[i][j])
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<n;j++){
    //         if(i==j)
    //         s[i][j]=i;
    //         cout<<s[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    printparen(s,1,n-1);

}
int main(){
    int p[6]={4,10,3,12,20,7};
    mcm(p,6);
}