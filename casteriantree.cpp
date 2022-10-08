#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e9;
const ll MOD = 123456789;
const ll LOG = 20;
int n;
int bang[sized];
int parent[sized];
int D[sized];
int finddepth(int i){
    if(D[i]!=-2) return D[i];
    D[i]=finddepth(parent[i])+1;
    return D[i];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RMQTREE.inp","r",stdin);
	freopen("RMQTREE.out","w",stdout);
    cin>>n;
    bang[0]=inf;
    for(int i=1;i<=n;i++){
        cin>>bang[i];
    }
    int rightmost=0;// nút
    for(int i=0;i<=n;i++){
        int x=rightmost;
        int y=-1;
        while(true){
            if(bang[x]>=bang[i]) break;
            y=x;
            x=parent[x];
        }   
        parent[i]=x;
        if(y!=-1) parent[y]=i;
        rightmost=i;
    }
    D[0]=-1;
    for(int i=1;i<=n;i++){
        D[i]=-2;
    }
    for(int i=1;i<=n;i++) cout<<finddepth(i)<<" "; 
    return 0;
}