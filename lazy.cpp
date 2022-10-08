#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bs binary_search
#define int ll
const ll sized = 1e6;
const ll N = 1e7;
const int inf = 1e9;
const ll MOD = 123456789;
const ll LOG = 20;
// lazy
int n,q;
int bang[sized];
int st[sized*4];
int la[sized];
void Buildtree(int l,int r,int id){
    if(l==r){
        st[id]=bang[l];
        return ;
    }
    int mid=(l+r)/2;
    Buildtree(l,mid,id*2);
    Buildtree(mid+1,r,id*2+1);
    st[id]=max(st[id*2],st[id*2+1]);
}
void lazy(int id){
    st[id]+=la[id];
    la[id*2]+=la[id];
    la[id*2+1]+=la[id];
    la[id]=0;
}
void update(int id,int l,int r,int u,int v,int val){
    lazy(id);
    if(r<u || v<l) return;
    if(u<=l && v>=r){
        la[id]+=val;
        lazy(id);
        return; 
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
int maxi(int l,int r,int u,int v,int id){
    lazy(id);
    if(r<u || v<l) return -inf;
    if(u<=l && v>=r) return st[id];

    int mid=(l+r)/2;
    return max(maxi(l,mid,u,v,id*2),maxi(mid+1,r,u,v,id*2+1));
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);  
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bang[i];
    Buildtree(1,n,1);
    cin>>q;
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int x,y,val;
            cin>>x>>y>>val;
            update(1,1,n,x,y,val);
        }
        if(type==2){
            int l,r;
            cin>>l>>r;
            cout<<maxi(1,n,l,r,1)<<endl;
        }
    }
    return 0;
}
