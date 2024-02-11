#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

const int N=1e5+9;
vector<int>g[N];
int dis[N],parent[N];
bool vis[N];

int main()
{
    int n,m;cin>>n>>m;

    while(m--){

        int u,v;cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int>q;

    q.push(1);
    vis[1]=true;
    dis[1]=0;

    while(!q.empty()){

        int u=q.front();

        q.pop();

        for(auto x : g[u]){

            if(!vis[x]){

                q.push(x);
                parent[x]=u;
                dis[x]=dis[u]+1;
                vis[x]=true;
            }
        }
    }

    for(int i=1;i<=n;i++)cout<<dis[i]<< " ";
    cout<<endl;

    // to find parent of n'th node
    int x=n;

    while(x!=1){

        cout<<x<<" ";
        x=parent[x];
    }

    cout<<1<<" ";

    cout<<endl;
}

