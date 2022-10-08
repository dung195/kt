#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bs binary_search
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
int abs_1(int x){
    int y=x>>31;
    return (x+y)^y;
}
int maxi(int x,int y){
    int m=(x-y)>>31;
    return x&m| x&~m;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    cout<<max(3,5)<<endl;
    cout<<abs(99)<<endl;
    return 0;
}