#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define pll pair<ll, ll>
typedef vector<vector<ll>> vvi;
const ll sized=3e5+11;
const ll inf=1e18;
const ll MOD=inf;
// dp[i][j]: giá trị lớn nhất khi lấy i món hàng đầu tiên và giới hạn cho phép 
//của balo là j
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-wi]+ai]
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-ai]+ai]
//ds dp[n][w]
ll val[sized];
ll capacity[sized];
ll n,w;
ll F[105][100005];
ll find(ll i,ll j){
    if(F[i][j]!=0) return F[i][j] ;
    if(j<0) return 0;
    if(j==0) return 0;
    if(i==0) return 0;
    else{
        if(j<capacity[i]) {
            F[i][j]=find(i-1,j);
            return F[i][j];
        }
        else F[i][j]=max(find(i-1,j-1),find(i-1,j-capacity[i])+val[i]);
        return F[i][j];
    }
}
main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin); 
    // freopen("main.out","w",stdout);
    cin>>n>>w;
    for(ll i=1;i<=n;i++){
        cin>>capacity[i]>>val[i];
    }
    cout<<find(n,w)<<endl;
    return 0;
}
