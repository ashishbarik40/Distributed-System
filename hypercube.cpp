#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int> &vis,vector<vector<int>> g)
{
    vis[v]=1;
    for(auto &val:g[v])
    {
        if(!vis[val])
        {
            dfs(val,vis,g);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    int m;
    cout<<"Enter Number of Edges: ";
    cin>>m;
    vector<vector<int>> adjacency_list(n);
    vector<vector<int>> adjacency_matrix(n,vector<int>(n,0));
    vector<int> degree(n);
    cout<<"Enter the connections: "<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
    }
    vector<int> vis(n,0);
    dfs(0,vis,adjacency_list);
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cout<<"The given network is not connected"<<endl;
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<"The given network is connected"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        degree[i]=adjacency_list[i].size();
    }
    cout<<"The Adjacency List is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<": ";
        for(auto &val:adjacency_list[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<"The Adjacency Matrix is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adjacency_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The degree of the nodes are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"The node "<<i<<" :"<<degree[i]<<endl;
    }
    return 0;
}
