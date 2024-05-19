#include<bits/stdc++.h>
using namespace std;
int main()
{
    int edge,node,start;
    cout<< "Enter the number of node: ";
    cin>>node;
    cout<< "Enter the number of edge: ";
    cin>>edge;

    bool visit[node+1];
    vector<int> adj[node+1];

    cout<< "Enter the edges: "<< endl;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<"Enter the starting node: ";
    cin>>start;

    for(int i=0;i<=node;i++) visit[i]= false;

    queue<int>q;
    q.push(start);

    visit[start]=true;

    cout<< "BFS result: \n";
    while(!q.empty())
    {
        int fr= q.front();
        q.pop();

        cout<<fr<<endl;

        for(int i=0;i<adj[fr].size();i++)
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                q.push(adj[fr][i]);
            }
        }
    }

    return 0;
}
