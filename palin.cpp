#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
#define int ll
const ll sized = 1e3;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
int F[sized][sized];
int dp[sized];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    string s;
    cin>>s;
    s=" "+s;
    for(int i=s.size();i>=1;i--){
        for(int j=i;j<=s.size();j++){
            if(i==j) F[i][j]=1;
            else{
                if(i==j-1) F[i][j]=s[i]==s[j];
                else{
                    if(s[i]==s[j]) F[i][j]=F[i+1][j-1];
                }
            }
        }
    }
    dp[1]=1;
    for(int i=2;i<=s.size()-1;i++){
        dp[i]=inf;
        for(int j=1;j<=i;j++){
            if(F[j][i]==1) dp[i]=min(dp[i],dp[j-1]+1);
        }
    }
    cout<<dp[s.size()-1]<<endl;
    return 0;
}