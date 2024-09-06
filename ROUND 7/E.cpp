#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int, int>>
#define ii pair<ll, ll>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k; cin >> k;
    int a[k];
    F(i, 0, k) cin >> a[i];
    vector<vector<int>> v(k);
    unordered_map<int, int> m;
    int b[k];
    F(i, 0, k){
        set<int> tmp;
        F(j, 0, a[i]){
            int x; cin >> x;
            v[i].pb(x);
            tmp.insert(x);
        }
        for(int x : tmp) m[x]++;
    }   
    int res = 1e9;
    for(auto x : m){
        if(x.se == k){
            res = min(res, x.fi);
        }
    }
    if(res == 1e9){
        cout << "NO\n";
    }
    else cout << res << endl;
}