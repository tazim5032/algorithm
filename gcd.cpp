#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int gcd(int a, int b){
    if(a==0)return b;
    if(b==0)return a;
    if(a<b)swap(a,b);
    return gcd(a%b,b);
}
int main(){

    int a,b;cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
