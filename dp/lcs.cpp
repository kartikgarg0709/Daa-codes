#include<iostream>
using namespace std;
void lcs(string a,string b){
    const int n=a.length();
    const int m=b.length();
    // cout<<m<<endl;
    int c[n+1][m+1]={0};
    char b[n+1][m+1];
    for(int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
           c[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i-1]==b[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
            }
            else{
                c[i][j]=c[i][j-1];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<c[n][m];
}
int main(){
    string a="abcbdab";
    string b="bdcaba";
    lcs(a,b);

}