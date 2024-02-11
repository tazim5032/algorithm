#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int N=1e5+9;
vector<int>g[N];
int color[N];
bool ok;

void dfs(int u){
    color[u]=1;

    for(auto x: g[u]){
        if(!color[x]){
            dfs(x);
        }
        else if(color[x]==1){
            ok=true;
        }
    }

    //color[u]=2;
}
int main()
{
    int n,m;cin>>n>>m;

    while(m--){

        int u,v;cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    ok=false;

    for(int i=1;i<=n;i++){
        if(!color[i])dfs(i);
    }

    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

