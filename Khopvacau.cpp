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
int low[sized];
int num[sized];
bool Node[sized];
int cnt=0;
int edge=0;
void dfs(int u,int p){
    int child=0;
    low[u]=num[u]=++cnt;
    for(auto v: graph[u]){
        if(v!=p){
            if(num[v]){
                low[u]=min(low[u],num[v]);
            }
            else{
                dfs(v,u);
                child++;
                low[u]=min(low[u],low[v]);
                if(low[v]==num[v]) edge++;
                if(u==p){
                    if(child>=2){
                        Node[u]=true;
                    }
                }
                else{
                    if(low[v]>=num[u]) Node[u]=true;
                }
            }
        }
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
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!num[i]) dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        cerr<<low[i]<<" ";
    }
    cerr<<endl;
    for(int j=1;j<=n;j++){
        cerr<<num[j]<<" ";
    }
    cerr<<endl;
    // cerr<<child<<endl;
    int dem=0;
    for(int i=1;i<=n;i++){
        if(Node[i]==true) dem++;
    }
    cout<<dem<<" "<<edge<<endl; 
    return 0;
}