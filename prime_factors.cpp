#include <iostream>
#include<vector>
using namespace std;

const int N=1e6+9;
int smallest_prime_factor[N];

int main(){

    for(int i=2;i<N;i++)smallest_prime_factor[i]=i;

    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i)smallest_prime_factor[j]=min(smallest_prime_factor[j],i);
    }

    int q;cin>>q;

    while(q--){

        int n;cin>>n;

        vector<int>ans;

        while(n>1){

            ans.push_back(smallest_prime_factor[n]);
            n/=smallest_prime_factor[n];
        }

        for(auto x: ans)cout<<x<<" ";
        cout<<endl;
    }
}
