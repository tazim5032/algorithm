#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int N=1e5+9;
vector<int>g[N];
bool vis[N];

void dfs(int u){
    vis[u]=true;
    for(int it : g[u]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;

    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans=0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }

    cout<<ans<<endl;
}
