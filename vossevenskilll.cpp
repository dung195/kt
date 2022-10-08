#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll,ll>
#define pll pair<ll,ll>
typedef vector<vector<ll> > vvi;
const ll sized=1000000;
const ll inf=1e9+7;
ll F[sized];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin); 
    // freopen("main.out","w",stdout);
    string s;
    cin>>s;
    int cur=0,n=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 55){
            F[++cur]++;
            n=max(n,cur);
        }
        else cur=0;
    }
    for(int i=n-1;i>0;i--){
        F[i]+=F[i+1];
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<F[i]<<endl;
    }
    return 0;
}
