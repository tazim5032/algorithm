#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

int main()
{
    ll n,m,i,j,k,x,y,z,t;

    cin>>t;

    while(t--)
    {
          int a, b, r, x = 0;
                cin >> a >> b >> r;
                if (a < b) swap(a, b);
                bool f = false;
                for (int i = 62; i >= 0; --i) {
                        bool ab = a >> i & 1, bb = b >> i & 1;
                        if (ab && !bb) {
                                if (f && (x | (1LL << i)) <= r) x |= 1LL << i;
                                else f = true;
                        }
                }
                a ^= x;
                b ^= x;
                cout << abs(a - b) << '\n';
    }

}
