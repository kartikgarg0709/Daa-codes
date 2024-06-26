#include<iostream>
using namespace std;

void knapsack(int profit[],int weight[],int a,int W){
    
    int we[a+1][W+1]={0};
    for(int i=0;i<=a;i++){
        for(int w=0;w<=W;w++){
            if(weight[i]<=w){
                if(profit[i]+we[i-1][w-weight[i]]>we[i-1][w]){
                        we[i][w]=profit[i]+we[i-1][w-weight[i]];
                }
                else
                we[i][w]=we[i-1][w];
            }
            else
            we[i][w]=we[i-1][w];

        }
    }
cout<<we[a][W];
}
int main(){
    int profit[4]={3,4,5,6};
    int weight[4]={2,3,4,5};
    int w=5;
    knapsack(profit,weight,4,w);
}