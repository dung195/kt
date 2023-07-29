#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 3;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 1e9+7;
const ll LOG = 20;
// https://nguyenhue2023.contest.codeforces.com/group/dFLpA3Lnt1/contest/464142/problem/A
struct matrix{
    int n,m;
    int mal[sized][sized];
    void init(){
        memset(mal,0,sizeof(mal));
    }
    void initdv(){
        init();
        for(int i=0;i<sized;i++) mal[i][i]=1;
    }
    matrix operator *(matrix B){
        matrix C;
        C.n=n;
        C.m=B.m;
        C.init();
        for(int i=0;i<C.n;i++){
            for(int j=0;j<C.m;j++){
                for(int k=0;k<m;k++){
                    C.mal[i][j]=(C.mal[i][j]+mal[i][k]*B.mal[k][j])%MOD;
                }
            }
        }
        return C;
    }
    matrix POW(int x){
        matrix C;
        C.n=n;
        C.m=m;
        C.initdv();
        for(int i=1;i<sized;i++){
            C.mal[i][i]=1;
        }
        if(x==0) return C;
        matrix B=POW(x/2);
        C=B*B;
        if(x%2==1) C=C*(*this);
        return C;
    }
};
void solve(){
    int n;
    cin>>n;
    if(n==0){
        cout<<1<<endl;
    }
    if(n==1){
        cout<<1<<endl;
    }
    matrix A;
    A.n=2;
    A.m=1;
    A.init();
    A.mal[0][0]=1;
    A.mal[1][0]=1;
    matrix C;
    C.n=2;
    C.m=2;
    C.init();
    C.mal[0][0]=1;
    C.mal[0][1]=2;
    C.mal[1][0]=1;
    // matrix X=C.POW(7);
    // for(int i=0;i<X.n;i++){
    //     for(int j=0;j<X.m;j++){
    //         cerr<<X.mal[i][j]<<" ";
    //     }
    //     cerr<<endl;
    // }
    // cerr<<endl;
    // matrix G=C*A;
    // for(int i=0;i<G.n;i++){
    //     for(int j=0;j<G.m;j++){
    //         cout<<G.mal[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    matrix G= (C.POW(n-1))*A;
    cout<<G.mal[0][0]<<endl;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}