#include <iostream>
#include <vector>
using namespace std;
int n = 5;
vector <int> x;
vector<vector<int>> graph;


void printArr(vector<int> x)
{
    for (int i=0; i < x.size(); i++)
        cout << x[i] << " ";

    cout << endl;
}
void nextVertex(int k)
{
    do{
        x[k] = (x[k]+1) % (n+1);
        if (x[k] == 0)
            return;
            
        if (graph[x[k-1]][x[k]] != 0)
        {
            int i=1;
            for (i=1; i<=k; i++)
                if (x[i] == x[k])
                    break;
            
            if (i == k)
                if (k < n || (k==n && graph[x[n]][x[1]] != 0))
                    return ;
        }
    } while (true);
}

void hamiltonian(int k)
{
    do{
        nextVertex(k);
        if (x[k] == 0)
            return;
        if (k == n)
            printArr(x);
        else
            hamiltonian(k+1);
    }while(true);
}
int main() {
    // tc - n^n
    x.push_back(0);
    x.push_back(1);
    for (int i=2; i<n+1; i++)
        x.push_back(0);

    // graph = {{}, {0, 0,1,1,0,1}, {0, 1,0,1,1,1}, {0, 1,1,0,1,0}, {0, 0,1,1,0,1}, {0, 1,1,0,1,0}};
    graph = {{},{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}};
    hamiltonian(2);

    return 0;
}