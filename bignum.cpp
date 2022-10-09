#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
typedef vector<ll> bignum;
bignum A,B;
bignum makearray(string s){
    bignum C; 
    C.clear();
    for(int i = s.size()-1; i >=0; i--)
        C.push_back(s[i] - 48);
    return C;
}
string tostring(bignum a){
    string ans="";
    for(int i = a.size()-1; i >=0; i--)
        ans += char(a[i]+48);
    return ans;
}
bignum add(bignum a,bignum b){
    bignum c;
    c.resize(max(a.size(),b.size()));
    a.resize(c.size());
    b.resize(c.size());
    ll mem=0;
    for(int i=0;i<c.size();i++){
        ll sum=mem+a[i]+b[i];
        c[i]=sum%10;
        mem=sum/10;
    }
    if(mem>0) c.push_back(mem);
    return c; 
}
bignum subtract(bignum a,bignum b){
    bignum c;
    c.resize(max(a.size(),b.size()));
    a.resize(c.size());
    b.resize(c.size());
    ll mem=0;
    for(int i=0;i<c.size();i++){
        ll sub=a[i]-b[i]-mem;
        if(sub<0){
            mem=1;
            sub+=10;
        }
        else sub=0;
        c[i]=sub;
    }
    while(c.size()-1>1 && c[c.size()-1]==0)c.pop_back();
    return c; 
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    A=makearray(a);
    B=makearray(b);
    bignum C=subtract(A,B);
    cout<<tostring(C)<<endl;
}