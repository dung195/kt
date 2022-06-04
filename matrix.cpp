#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue

const ll MOD=111539786;
typedef vector<vector<ll> > vvi;
// fibonaci by matrix

vvi multi(vvi a,vvi b){
    vvi c;
    c.clear();
    c.resize(a.size());
    for(ll i=0;i<a.size();i++){
        c[i].resize(b[0].size(),0);
    }
    ll t=b[0].size();
    ll m=a.size();
    ll n=a[0].size();
    for(ll i=0;i<m;i++){
        for(ll j=0;j<t;j++){
            for(ll k=0;k<n;k++) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
        }
    }
    return c;
}
vvi lt(vvi a,ll n){
    if(n==1) return a;
    vvi tmp=lt(a,n/2);
    tmp=multi(tmp,tmp);
    if(n%2!=0) tmp=multi(tmp,a);
    return tmp;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main1.inp","r",stdin);
    // freopen("main1.out","w",stdout);
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(n==2){
            cout<<2<<endl;
            continue;
        }
        vvi a;
        a.clear();
        a.resize(2);
        a[0].push_back(0);
        a[0].push_back(1);
        a[1].push_back(1);
        a[1].push_back(1);
        a=lt(a,n-1);
        ll ans=a[1][0]*1+a[1][1]*1;
        cout<<ans%MOD<<endl;
    }
    return 0;
}