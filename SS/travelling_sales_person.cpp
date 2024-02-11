#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;

int n,m,a[20][20];
bool vis[20];
int ans;
void dfs(int source, int cityCnt, int cost){

    if(cityCnt==n-1){
        ans=min(ans,cost+a[source][0]);
        return;
    }

    vis[source]=true;

    for(int i=0;i<n;i++){

        if(!vis[i])dfs(i, cityCnt+1, cost+a[source][i]);
    }

    vis[source]=false;
}

int main(){

    int t;cin>>t;

    while(t--){

        cin>>n;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cin>>a[i][j];
            }

             vis[i]=false;
        }

        ans=1e9;

        dfs(0, 0, 0);

        cout<<ans<<endl;
    }
}
