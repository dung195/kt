#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
typedef vector<vector<ll> > vvi;
const ll sized=2000+7;
const ll inf=1e9+7;
const ll MOD=inf;
vector<pii>code;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin); 
    // freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x; 
        code.push_back({x,0});
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x; 
        code.push_back({x,1});
    }
    sort(code.begin(),code.end());
    int ans=0;
    int now=code[0].second;
    for(int i=1;i<code.size();i++){
        if(code[i].second+now==1)
        { 
            ans++;
            now=-1;
        }
        else now=code[i].second;
    }
    cout<<ans<<endl;
    return 0;
}
