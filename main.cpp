#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll,ll>
#define pll pair<ll,ll>
typedef vector<vector<ll> > vvi;
const int sized=1e5+7;
const ll inf=1e9+7;
int num[sized];
int T[sized];
int sign[sized];
int len[sized];
pq<int,vector<int>,less<int>>q;
int convert(string s){
    int ans=0;
    for(int i=s.size()-1;i>=0;i--){
        ans+=(s[i]-48)*pow(10,s.size()-1-i);
    }
    return ans;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin); 
    // freopen("main.out","w",stdout);
    string s;
    cin>>s;
    sign[1]=1;
    int cnt=1;
    int pos=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==43 || s[i]==45){
            num[++cnt]=convert(s.substr(pos,i-pos));
            len[cnt]=i-pos;
            pos=i;
            if(s[i]==43) sign[cnt]=1;
            if(s[i]==45) sign[cnt]=-1;
        }
    }
    T[1]=num[1];
    for(int i=2;i<=s.size();i++){
        T[i]=T[i-1]*sign[i]*num[i];
    }
    //đã xong mảng :))
    
    //số
    for(int i=1;i<=cnt-1;i++){
        for(int j=1;j<=to_string(num[i]).size();j++){
            int moi=(num[i]/pow(10,j))*pow(10,j-1);
            int v=T[i-1]+sign[i]*moi+T[s.size()]-T[i];
            q.push(v);
        }
    }

    //dấu
    for(int i=1;i<=cnt-1;i++){
        int moi=num[i]*pow(10,i+1)+num[i+1];
        int v=T[i-1]+sign[i]*moi+T[s.size()]-T[i+1];
        q.push(v);
    }
    cout<<q.top()<<endl;
    return 0;
}
