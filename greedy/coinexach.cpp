#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void coin(vector<int> &p,int sum){
    sort(p.begin(),p.end());

reverse(p.begin(),p.end());
// for(auto i:p){
//     cout<<i<<"  ";
// }
vector<int> ans;
int k=0;
while(k!=sum){
    for(auto j:p){
        if(sum>j){
        ans.push_back(j);
        k=k+j;
        }
    }
}
for(auto i:ans){
    cout<<i<<"  ";
}
// cout<<k;
}
int main(){
    vector<int> p={25,20,10,5,1};
    int sum=36;
    coin(p,sum);
}