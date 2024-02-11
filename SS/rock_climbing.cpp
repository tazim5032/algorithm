#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;

int a[55][55],n,m;
bool ok,vis[55][55];

void dfs(int i, int j, int k){

    if(i<0 || i>=n || j<0 || j>=m)return;
    if(vis[i][j])return;

    vis[i][j]=true;

    if(a[i][j]==3){
        ok=true;
        return;
    }

    if(j+1<m && a[i][j+1]!=0 && vis[i][j+1]==false)dfs(i,j+1,k);
    if(j-1>=0 && a[i][j-1]!=0 && vis[i][j-1]==false)dfs(i,j-1,k);

    for(int h=1;h<=k;h++){

        if(i+h<n && a[i+h][j]!=0 && vis[i+h][j]==false)
            dfs(i+h,j,k);
        if(i-h>=0 && a[i-h][j]!=0 && vis[i-h][j]==false)
            dfs(i-h,j,k);
    }
}
int main(){

    int t;cin>>t;

    while(t--){

        cin>>n>>m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        for(int k=0;k<=n;k++){

            ok=false;

            memset(vis, false, sizeof(vis));

            dfs(n-1,0,k);

            if(ok){

                cout<<k<<endl;
                break;
            }
        }
    }

    return 0;
}
