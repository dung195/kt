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
vector<int>revgraph[sized];
stack<int>st;
int dd[sized];
int vis1[sized];
int vis2[sized];
map<int,bool>a;
void dfs1(int S){
    vis1[S]=1;
    for(auto x: graph[S]){
        if(!vis1[x]){
            dfs1(x);
        }
    }
    st.push(S);
}
void dfs2(int S,int rep){
    if(vis2[S]==true) return;
    vis2[S]=true;
    dd[S]=rep;
    for(auto v:revgraph[S]){
            dfs2(v,rep);
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
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }   
    for(int i=1;i<=n;i++){
        if(vis1[i]==false) dfs1(i);
    }
    while(st.size()>0){
        int u=st.top();
        st.pop();
        dfs2(u,u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[dd[i]]!=true){
            a[dd[i]]=true;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}