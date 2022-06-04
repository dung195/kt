#include<bits/stdc++.h>
using namespace std;
#define sized 100
bool check[sized];
void SNT(){
    for(int i=2;i<sized;i++){
        check[i]=true;
    }
    for(int i=2;i*i<sized;i++){
        if(check[i]==true){
            for(int j=i*i;j<sized;j+=i){
                check[j]=false;
            }
        }
    }
    for(int i=2;i<sized;i++){
        if(check[i]==true) cout<<i<<" ";
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SNT();
    return 0;
}