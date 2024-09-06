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

const int N = 1e5 + 100;
int st[N * 4], a[N];

void update(int id, int l, int r, int pos, int val){
	if(l > pos || r < pos) return;
	if(l == r && r == pos){
		st[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
	if(r < u || l > v) return 0;
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return get(id * 2, l, mid, u, v)
		+ get(id * 2 + 1, mid + 1, r, u, v);
}

void solve(){
    int n, k; cin >> n >> k;
    int a[n + 1], b[n + 1];
    FOR(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    FOR(i, 1, n) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    int nt = 0, r = 1, ans = 0;
    FOR(i, 1, n){
        if(r == i){
        	update(1, 1, n, a[i], 1);
        	r++;
		}
        while(r <= n && nt < k){
            nt += get(1, 1, n, a[r] + 1, N);
            update(1, 1, n, a[r], 1);
            r++;
        }
        if(nt >= k) ans += (n - r + 2);
        nt -= get(1, 1, n, 1, a[i] - 1);
        update(1, 1, n, a[i], -1);
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}