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

int m[100005][20];

int get(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return max(m[l][k], m[r - (1 << k) + 1][k]);
}

void solve(){
    int n; cin >> n;
    int a[n + 1];
    FOR(i, 1, n){
        cin >> a[i];
        m[i][0] = a[i];
    }
    FOR(j, 1, 19){
        FOR(i, 1, n - (1 << j) + 1){
            m[i][j] = max(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }
    vector<int> l (n + 1, 0), r(n + 1, n + 1);
    stack<int> st;
    FOR(i, 1, n){
        while(sz(st) && a[st.top()] <= a[i]) st.pop();
        if(st.empty()) l[i] = 0;
        else l[i] = st.top();
        st.push(i);
    }
    while(sz(st)) st.pop();
    FOD(i, n, 1){
        while(sz(st) && a[st.top()] <= a[i]) st.pop();
        if(st.empty()) r[i] = n + 1;
        else r[i] = st.top();
        st.push(i);
    }
    int ans = 0;
    FOR(i, 1, n){
        if(l[i] != 0){
            int ro = l[i] - 1, lo = 1, id = 0;
            while(lo <= ro){
                int mid = (lo + ro) / 2;
                if(get(mid, l[i] - 1) >= a[i]){
                    id = mid;
                    lo = mid + 1;
                }
                else ro = mid - 1;
            }
            ans += a[i] * (r[i] - i) * (l[i] - id);
        }
        if(r[i] != n + 1){
            int lo = r[i] + 1, ro = n, id = n + 1;
            while(lo <= ro){
                int mid = (lo + ro) / 2;
                if(get(r[i] + 1, mid) >= a[i]){
                    id = mid;
                    ro = mid - 1;
                }
                else lo = mid + 1;
            }
            ans += a[i] * (i - l[i]) * (id - r[i]);
        }
    }
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}