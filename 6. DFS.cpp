#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];

void dfs(int src)
{
    cout << src << endl;
    vis[src] = true;
    for (int child : v[src])
    {
        if (vis[child] == false)
            dfs(child);
    }
}
int main()
{
    int n, e,s;
    cout<<"Enter number of node: ";
    cin >> n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges: \n";
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<"Enter the starting node: ";
    cin>>s;
    memset(vis, false, sizeof(vis));
    dfs(s);
    return 0;
}
