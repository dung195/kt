#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bs binary_search
const ll sized = 1e7;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 2111992;
const ll LOG = 20;
int n,m,s;
int cuom[sized];
vector<pll>bt_1;
vector<pll>bt_2;
int cnt=0;
int mang1[sized];
int mang2[sized];
void Backtrack1(int k){
    if(k>n/2) {
        ll cnt=0;
        ll tong=0;
        for(int i=1;i<=n/2;i++){
            if(mang1[i]==1) {
                cnt++;
                tong+=cuom[i];
            }
        }
        bt_1.push_back({cnt,tong});
        return;
    }
    for(int i=0;i<=1;i++){
            mang1[k]=i;
            Backtrack1(k+1);
    }
}
void Backtrack2(int k){
    if(k>n) {
        ll cnt=0;
        ll tong=0;
        for(int i=n/2+1;i<=n;i++){
            if(mang2[i]==1) {
                cnt++;
                tong+=cuom[i];
            }
        }
        bt_2.push_back({cnt,tong});
        return;
    }
    for(int i=0;i<=1;i++){
            mang2[k]=i;
            Backtrack2(k+1);
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    cin>>n>>m>>s;
    int cnt=0;
    for(int i=1;i<=n;i++) cin>>cuom[i];
    Backtrack1(1);
    Backtrack2(n/2+1);
    sort(bt_2.begin(),bt_2.end());
    for(int i=0;i<bt_1.size();i++){
        pll tmp=bt_1[i];
        ll a=0;
        int pos=lower_bound(bt_2.begin(),bt_2.end(),make_pair(m-tmp.first,a))-bt_2.begin();
        int pos2=upper_bound(bt_2.begin(),bt_2.end(),make_pair(m-tmp.first,inf))-bt_2.begin()+1;
        if(bt_2[pos].first+tmp.first==m){
            for(int i=pos;i<pos2;i++){
                int choose=bt_2[i].first;
                int tong=bt_2[i].second;
                if(tong+tmp.second==s) cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
