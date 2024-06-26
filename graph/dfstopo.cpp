#include <iostream>
#include <vector>

using namespace std;

 int WHITE = 0;
 int GRAY = 1;
 int BLACK = 2;

// vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
vector<int> adj[6] = {{3}, {0}, {1}, {2}, {2, 3}, {}};
int color[6];


void dfs(int u){
    color[u]=GRAY;
    for(auto v:adj[u]){
        if(color[v]==WHITE)
        dfs(v);
        else if(color[v]==GRAY){
            cout<<"cycle is presnt";
        return;
        }
    }
    color[u]=BLACK;
}
int main(){
    for(int i=0;i<6;i++){
        color[i]=WHITE;
    }
    dfs(0);
    cout<<"cycle is not presnt";
}