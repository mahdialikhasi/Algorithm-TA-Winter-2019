// Bahar Boroomand

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt;
vector<int> add;
void DFS(int v, bool visited[],vector<vector<int> > &graph,vector<int> &res)
{


    visited[v] = true;
    res.push_back(v);
    cnt++;

    vector<int>::iterator i;
    for (i = graph[v].begin(); i != graph[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited,graph,res);
}
vector<vector<int> > getTranspose(int V,vector<vector<int> > &graph)
{
    vector<int> vi;
    vector<vector<int > > revGraph(V,vi);
    for (int v = 0; v < V; v++)
    {

        vector<int>::iterator i;
        for(i = graph[v].begin(); i != graph[v].end(); ++i)
        {
            revGraph[*i].push_back(v);
        }
    }
    return revGraph;
}
void TotalDfs(int v, bool visited[], stack<int> &Stack,vector<vector<int> > &graph)
{

    visited[v] = true;


    vector<int>::iterator i;
    for(i = graph[v].begin(); i != graph[v].end(); ++i)
        if(!visited[*i])
            TotalDfs(*i, visited, Stack,graph);


    Stack.push(v);
}




int stronglyConnectedComponents(int V,vector<vector<int> > &graph)
{
    int maxNum=0;
    stack<int> Stack;

    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            TotalDfs(i, visited, Stack,graph);
        vector<vector<int> > revGraph=getTranspose(V,graph);
    for(int i = 0; i < V; i++)
        visited[i] = false;
    vector<vector<int> > final;

    while (Stack.empty() == false)
    {

        int v = Stack.top();
        Stack.pop();


        if (visited[v] == false)
        {
            cnt=0;
            vector<int> res;
            DFS(v, visited,revGraph,res);
            final.push_back(res);



        }
    }
    vector<int> fin(V,0);
    for(int i=final.size()-1;i>=0;i--){
        if(final[i].size()>1){
            for(int j=0;j<final[i].size();j++){
                fin[final[i][j]]=final[i].size();
            }
        }
        else{
            fin[final[i][0]]=fin[graph[final[i][0]][0]]+1;
        }
    }
    int max=0;
    int vertex;
    for(int i=0;i<V;i++){
        if(max<fin[i]){
            max=fin[i];
            vertex=i;

        }
    }

    return vertex;
}


int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        int V;
        cin >> V;
        vector<int> vi;
        vector<vector<int> > graph(V, vi);

        for (int i = 0; i < V; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b-1);

        }



        cout << "Case "<<t+1<<": " << stronglyConnectedComponents(V,graph)+1<<"\n";
    }
}
