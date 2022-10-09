#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD=2e9+11;
ll nhan(ll a,ll b,ll mod){
    if(b==0) return 0;
    ll t=nhan(a,b/2,mod);
    t=(t+t)%mod;
    if(b%2!=0) t=(t+a)%mod;

    return t;
}
ll power(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll t=power(a,b/2,mod);
    t=(t*t)%mod;
    if(b%2!=0){
        t=(t*b)%mod;
    }
    return t;
}
main(){
    ll a,b; 
    cin>>a>>b; 
    cout<<nhan(a,b,MOD)<<endl;
    cout<<power(a,b,MOD)<<endl;
}