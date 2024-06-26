#include<iostream>
using namespace std;
void obst(int p[],int q[]){
    int e[5][5]={0};
    int w[5][5]={0};
    int r[3][3]={0};
    for(int i=1;i<=4;i++){
        for(int j=0;j<4;j++){
            if (i==j+1){
                e[i][j]=q[j];
                w[i][j]=q[j];
            }
        }
    }
    
    for(int l=1;l<=4;l++){
        for(int i=1;i<=4-l+1;i++){
            int j=i+l-1;
            e[i][j]=10000;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int k=i;k<=j;k++){
                int o=e[i][k-1]+e[k+1][j]+w[i][j];
                if(o<e[i][j]){
                    e[i][j]=o;
                    r[i][j]=k;
                }
            }
        }
    }
     for(int i=1;i<=4;i++){
        for(int j=0;j<4;j++){
            cout<<e[i][j]<<"  ";
        }
        cout<<endl;
    }

}
int main(){
    int p[4]={0,1,2,4};
    int q[4]={1,1,1,2};
    obst(p,q);
}