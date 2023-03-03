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
const ll LOG = 20;
vector<int>graph[sized];
int par[sized][LOG];
int h[sized];
void dfs(int u){
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        par[v][0]=u;
        h[v]=h[u]+1;
        dfs(v);
    }
}
int getbit(int x,int i){
    return(x>>i)&1;
}
int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    int x=h[u]-h[v];

    for(int i=LOG-1;i>=0;i--){
        if(getbit(x,i)==1) u=par[u][i];
    }
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    dfs(1);
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=2;j++){
    //         cout<<par[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<" ";
    }
    return 0;
}