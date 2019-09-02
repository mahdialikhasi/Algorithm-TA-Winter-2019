// Bahar Boroomand

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<bool> visitedAll;
void DFS(int s,int V,vector<vector<int > > &graph){
    visitedAll[s] = true;
    vector<int>::iterator i;
    for (i = graph[s].begin(); i != graph[s].end(); ++i)
        if (!visitedAll[*i])
            DFS(*i,V,graph);
}
void topologicalSortUtil(int s, bool visited[], stack<int> &Stack,int V,vector<vector<int> > &graph){
    visited[s] = true;
    vector<int>::iterator i;
    for (i = graph[s].begin(); i != graph[s].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack,V,graph);
    Stack.push(s);
}

int topologicalSort(int V,vector<vector<int > > &graph){
    stack<int> Stack;
    int cnt = 0;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        visitedAll.push_back(false);
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack,V,graph);

        while(!Stack.empty()){
            DFS(Stack.top(),V,graph);
            Stack.pop();
            cnt++;
            bool finish=true;
            while(visitedAll[Stack.top()]==true ) {
                Stack.pop();
                if(Stack.empty())
                    break;
            }


        }
        return cnt;

}

int main() {
    int t;
    cin>>t;
    vector<int> vi;
    vector<vector<int> > graph(t,vi);
    if(t==1){
        int n;
        cin>>n;
        cout<<"1";
        return 0;
    }

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int sec;
            cin>>sec;
            graph[i].push_back(sec-1);

        }
    }
	cout << topologicalSort(t,graph);
    return 0;
}