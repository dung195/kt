#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll,ll>
#define pll pair<ll,ll>
typedef vector<vector<ll> > vvi;
const ll sized=2207;
const ll inf=1e9+7;
ll mau[sized][sized];
int F[sized][sized];
int find(int n,int m){
    if(F[n][m]!=0) return F[n][m];
    if(n==0 || m==0) return 0;
    if(n==1 && m==1) return mau[n][m];
    else{
        if(n==1 || m==1 )
        F[n][m]=find(n,m-1)+find(n-1,m)+find(n-1,m-1)+mau[n][m]*(abs(n-1)+abs(m-1));
        
        else 
        F[n][m]=find(n,m-1)+find(n-1,m)+find(n-1,m-1)+mau[n][m]*(abs(n-1)+abs(m-1)+1);
        return F[n][m];
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin); 
    // freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            mau[i][j+1]=s[j]-48;
        }
    }
    // find(n,m);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<F[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }    
    cout<<find(n,m)<<endl;
    return 0;
}
