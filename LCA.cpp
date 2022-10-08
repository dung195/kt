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
int m,n,q;
vector<int>graph[sized];
int h[sized];
int p[sized][LOG];
void dfs(int S){
    for(int i=0;i<graph[S].size();i++){
        p[graph[S][i]][0]=S;
        h[graph[S][i]]=h[S]+1;
        dfs(graph[S][i]);
    }
}
int getbit(int x,int i){                                
    return (x>>i)&1;
}
int lca(int a,int b){
    if(h[a]<h[b]) swap(a,b);
    int x=h[a]-h[b];
    for(int i=LOG-1;i>=0;i--){
        if(getbit(x,i)==1) a=p[a][i];
    }
    if(a==b) return a;
    for(int i=LOG-1;i>=0;i--){
        if(p[a][i]!=p[b][i]){
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);              
    }
    dfs(1);
    for(int i=1;i<LOG;i++){
        for(int u=1;u<=n;u++){
            p[u][i]=p[p[u][i-1]][i-1]; // cha thứ 2**i của x =cha thứ 2**(i-1) của cha thứ 2**(i-1) của x
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}