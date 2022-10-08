#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define bs binary_search
typedef vector<vector<int>> vvi;
const ll sized = 30;
const ll N = 26;
const ll inf = 1e9;
const ll MOD = 2111992;
const ll LOG = 20;
int n;
vector<string>a;
vector<int>graph[sized];
bool root[sized];
bool met[sized];
bool check[sized];
void dfs(int S){
    check[S]=true;
    char x=S+96;
    cout<<x<<"";
    for(int i=0;i<graph[S].size();i++){
        dfs(graph[S][i]);
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
    // freopen("main.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    for(int i=0;i<n;i++){
        string tmp=a[i];
        root[tmp[0]-96]=true;
        for(int j=0;j<tmp.size()-1;j++){
            if(graph[tmp[j]-96].empty()==true){
                graph[tmp[j]-96].push_back(tmp[j+1]-96);
                met[tmp[j+1]-96]=true;
                root[tmp[j]-96]=true;
            }
        }
    }
    for(int i=1;i<=26;i++){
        if(root[i]==true && met[i]==false && check[i]==false){
            dfs(i);
        }
    }
    return 0;
}
