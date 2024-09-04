#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define sz(x) (int)(x).size()
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

int h[200005], dp[200005];
deque<int> q;

int cost(int j, int i, int c) {
    return dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
}

bool can_erase(int i, int j, int k) {
    return (h[i] - h[j]) * (h[i] * h[i] + dp[i] - h[k] * h[k] - dp[k])
        <= (h[i] - h[k]) * (h[i] * h[i] + dp[i] - h[j] * h[j] - dp[j]);
}

void solve() {
    memset(dp, 0x3f, sizeof dp);
    int n, c; 
    cin >> n >> c;
    FOR(i, 1, n) cin >> h[i];
    dp[1] = 0;
    q.push_back(1);
    FOR(i, 2, n) {
        while (sz(q) >= 2 && cost(q[0], i, c) >= cost(q[1], i, c)) 
            q.pop_front();
        dp[i] = cost(q[0], i, c);
        while (sz(q) >= 2 && can_erase(q[sz(q) - 2], q.back(), i)) 
            q.pop_back();
        q.push_back(i);
    }
    cout << dp[n] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
