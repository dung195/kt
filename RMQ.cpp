#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pq priority_queue
#define bs binary_search
// #define int ll
const ll sized = 500005;
const ll N = sized;
// const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
//https://judge.yosupo.jp/problem/staticrmq
int a[sized];
int st[LOG + 1][sized];
int n;
int q;
int lg2[N];
void BuildLog2Array()
{
    lg2[1] = 0;
    for (int i = 2; i < N; ++i)
        lg2[i] = lg2[i / 2] + 1;
}
void preprocess()
{
    for (int i = 1; i <= n; i++)
        st[0][i] = a[i];
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
}
int queryMin(int l, int r)
{
    int k = lg2[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
    // freopen("main.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    preprocess();
    BuildLog2Array();
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << queryMin(l + 1, r) << endl;
    }
    return 0;
}