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
const ll inf = 1e9;
const ll MOD = 123456789;
const ll LOG = 20;
int bang[sized];
int st[sized*4];
int la[sized];
void buildtree(int l,int r,int id){
    if(l==r){
        st[id]=bang[l];
        return;
    }
    int mid=(l+r)/2;
    buildtree(l,mid,id*2);
    buildtree(mid+1,r,id*2+1);
    st[id]=max(st[id*2],st[id*2+1]);
}
void lazy(int id){
    st[id]+=la[id];
    la[id*2]+=la[id];
    la[id*2+1]+=la[id];
    la[id]=0;
}
void update(int l,int r,int u,int v,int id,int val){
    lazy(id);
    if(u>r || v<l) return;
    if(l>=u && v>=r){
        la[id]+=val;
        lazy(id);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,u,v,id*2,val);
    update(mid+1,r,u,v,id*2+1,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
int maximum(int l,int r,int u,int v,int id){
    lazy(id);
    if(u>r || v<l) return -inf;
    if(l>=u && v>=r){
        return st[id];
    }
    int mid=(l+r)>>1;
    return max(maximum(l,mid,u,v,id*2),maximum(mid+1,r,u,v,id*2+1));
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bang[i];
    int q;
    cin>>q;
    buildtree(1,n,1);
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r,val;
            cin>>l>>r>>val;
            update(1,n,l,r,1,val);
        }
        if(type==2){
            int l,r;
            cin>>l>>r;
            cout<<maximum(1,n,l,r,1)<<endl;
        }
    }
    return 0;
}
