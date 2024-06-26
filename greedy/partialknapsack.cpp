#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> arr1,pair<int,int> arr2){
    return arr1.first>arr2.first;
}

void knapsack(vector<pair<int,int>> &arr,int w){
    int profit=0;
    int weight=0;
    sort(arr.begin(),arr.end(),comp);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i].first<<endl;
    // }
    for(int i=0;i<arr.size();i++){
        if (weight<w){
            int a=min(arr[i].second,w-weight);
            profit=profit+(arr[i].first*a)/arr[i].second;
            weight=weight+a;
        }
    }
cout<<profit;
}
int main(){
    vector<pair<int,int>> arr;
    arr={{100,20},{60,10},{120,30}};
    int w=50;
    knapsack(arr,w);

}