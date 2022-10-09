#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int, int>
#define pll pair<ll, ll>
typedef vector<vector<ll>> vvi;
const ll sized=3000005;
const ll inf=1e9+7;
const ll MOD=inf;
int n;
int getbit(int x,int i){
    return (x<<i)&1;
}
int batbit(int x,int i){
    return x|(1<<i);
}
int offbit(int x,int i){
    return x&(~1<<i);
}
//tt=sigma(2**pos1)
//F[i,tt]
int F[sized][31];
int 
bool check1(int i,int t){

}
bool check(int tt,int t){
    for(int i=0;i<=3;i++){
        if(getbit(t,i)==getbit(t,i+1)) return getbit(tt,i)==getbit(tt,i+1);
    }
    return false;
}
int find(int i,int tt){
    if(i>n) return 1;
    if(F[i][tt]==-1) return F[i][tt];
    for(int t=0;t<32;t++){
        if(i==1 || check(t,tt))  F[i][tt]+=find(i+1,t);
    }
    return F[i][tt];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
    // freopen("main.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){

    }
}   