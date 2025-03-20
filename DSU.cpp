#include<bits/stdc++.h>
//https://oj.vnoi.info/problem/dsu_a
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
int par[sized];
// DSU
//  lấy gốc cao nhất của u
int getroot(int u){
    if(par[u]<0) return u;
    return par[u]=getroot(par[u]);
}
void connect(int u,int v){
    u=getroot(u);
    v=getroot(v);
    if(u==v) return;
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];   // khi khi nối thì số lượng con của u khi này= số lượng con của u trước khi nối + số lượng con của v
    par[v]=u; // set cha v =u
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    // mảng par[i] lưu cha của node thứ i, tại node cao nhất thì sẽ là par[i]= -(số lượng con)
    for(int i=0;i<sized;i++) par[i]=-1; 
    // khai báo par[i]= - (số lượng con) , vì chưa có cạnh nào được nối với nhau, nên chính nó là con của nó và nó là cha cao nhất của cụm , nên par[i]=-1
    for(int i=0;i<m;i++){
        string type;
        cin>>type;
        int u,v;
        cin>>u>>v;
        if(type=="union"){
            connect(u,v);
        }
        else{
            u=getroot(u);
            v=getroot(v);
            if(u==v){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}