#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 16;
int a[sized];
int st[LOG][sized];
int n;
void preprocess(){
    for(int i=1;i<=n;i++) st[0][i]=a[i];
    for(int j=1;j<=LOG;j++){
        for(int i=1; i + (1 << j) - 1 <= n;i++){
            st[j][i]=min(st[j-1][i],st[j-1][i+ 1<<(j-1)]);
        }
    }
}
int queryMin(int l,int r){
    int k=__lg(r-l+1);
    return min(st[k][l],st[k][r-(1<<k)+1]);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int q;
    cin>>n>>q;
    preprocess();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<queryMin(l,r-1)<<endl;
    }
    return 0;
}