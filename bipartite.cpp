#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int N=1e5+9;
vector<int>g[N];
bool vis[N];
int color[N];
bool ok;

void dfs(int u){
    vis[u]=true;

    for(auto x: g[u]){
        if(!vis[x]){
            color[x]=color[u] ^ 1;
            dfs(x);
        }
        else{
            if(color[x]==color[u])ok=false;
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;

    while(m--){

        int u,v;cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    ok=true;

    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
