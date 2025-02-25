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
int bang[sized];
int st[sized*4];
//https://oj.vnoi.info/problem/segtree_itez1
void buildtree(int l,int r,int id){
    if(l==r){
        st[id]=bang[l];
        return;
    }
    int mid=(l+r)>>1;
    buildtree(l,mid,id*2);
    buildtree(mid+1,r,id*2+1);
    st[id]=max(st[id*2],st[id*2+1]);
}
void update(int l,int r,int u,int v,int val,int id){
    if(l>v || r<u) return;
    if(l==u && r==v){
        st[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,u,v,val,id*2);
    update(mid+1,r,u,v,val,id*2+1);
    st[id]=max(st[id*2],st[id*2+1]);
}
int find_max(int l,int r,int u,int v,int id){
    if(v<l || r<u) return -inf;
    if(l>=u && r<=v){
        return st[id];
    }
    int mid=(l+r)>>1;
    return max(find_max(l,mid,u,v,id*2),find_max(mid+1,r,u,v,id*2+1));
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bang[i];
    }
    buildtree(1,n,1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int u,v;
            cin>>u>>v;
            update(1,n,u,u,v,1);
        }
        if(type==2){
            int u,v;
            cin>>u>>v;
            cout<<find_max(1,n,u,v,1)<<endl;
        }
    }
    return 0;
}
