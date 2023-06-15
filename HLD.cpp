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
vector<pii>graph[sized];
int chainHead[sized];
int chainInd[sized];
int nChild[sized];
int nChain=0;
int nBase=0;
int posInBase[sized];
void hld(int u){
    if(chainHead[nChain]==0) chainHead[nChain]=u;
    chainInd[u]=nChain;
    posInBase[u]=++nBase;
    int mxvtx=-1;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i].first;
        if(mxvtx==-1 || nChild[v]>nChild[mxvtx]){
            mxvtx=v;
        }
    }
    if(mxvtx>-1){
        hld(mxvtx);
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
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        nChild[u]++;
    }
    return 0;
}