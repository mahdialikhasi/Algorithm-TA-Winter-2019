// Bahar Boroomand

#include <bits/stdc++.h>
using namespace std;
bool bicolorable(vector<vector<bool> > graph,int V, int src){
    int color[V];
    for (int i = 0; i < V; ++i)
        color[i] = -1;
    color[src] = 1;
    queue <int> myQ;
    myQ.push(src);
    while (!myQ.empty()){
        int top = myQ.front();
        myQ.pop();
        for (int v = 0; v < V; ++v){
            if (graph[top][v] && color[v] == -1){
                color[v] = 1 - color[top];
                myQ.push(v);
            }else if (graph[top][v] && color[v] == color[top])
                return false;
        }
    }
    return true;
}


int main()
{
    int V , E;
    cin >> V;
    while(V != 0) {
        cin >> E;
        vector<bool> vi(V,0);
        vector<vector<bool> > graph(V, vi);

        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b]=1;
            graph[b][a]=1;

        }


        bicolorable(graph, V, 0) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n" ;
        cin >> V;
    }
    return 0;
}