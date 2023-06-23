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
int cnt=0;
stack<int>st;
int ans=0;
void Tarjan(int u){
    low[u]=num[u]=++cnt;
    st.push(u);
    for(auto v: graph[u]){
        if(num[v]){
            low[u]=min(low[u],num[v]);
        }
        else{
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if(num[u]==low[u]){
        ans++;
        int tmp;
        do
        {
            tmp=st.top();
            st.pop();
            num[tmp]=low[tmp]=inf;
        } while (tmp!=u);
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
        // graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!num[i]){
            Tarjan(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}