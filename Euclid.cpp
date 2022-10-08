#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bs binary_search
const ll sized = 1e5;
const ll N = 1e7+1;
const int inf = 1e9;
const ll MOD = 2111992;
const ll LOG = 20;
int x,y,d;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void extendedeuclid(int a,int b){
    if(b==0){
        d=a;
        x=1;
        y=0;
    }
    else{
        extendedeuclid(b,a%b);
        int tmp=x;
        x=y;
        y=tmp-(a/b)*y;
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);

    return 0;
}
