#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void interval(vector<pair<int,int>> &a){
    
    int endtime=a[0].second;
    cout<<a[0].first<<"  "<<a[0].second<<endl;
    a.erase(a.begin());
    int k=0;
    while(a.size()!=0){
        for(int i=0;i<a.size();i++){
            if(a[i].first>=endtime){
                endtime=a[i].second;
                cout<<a[i].first<<"  "<<a[i].second<<"..";
                a.erase(a.begin()+i);
                // cout<<a.size();
            }
        }
        // cout<<a.size();
        cout<<endl;
        k++;
        endtime=0;
    }
    cout<<"value is "<<k<<endl;
}

int main(){
    vector<pair<int,int>> a;
    a={{1,3},{2,4},{2,7},{3,5},{3,7},{4,6},{5,6},{5,8},{6,10},{7,9},{8,10}};
    
    interval(a);
    // a.pop_back();
    
    


}