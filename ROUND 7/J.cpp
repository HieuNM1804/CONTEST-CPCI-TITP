#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ii pair<int,int>
const int N = 1e5 + 5, inf = 1e18;

int n, m, k, nchain;
int a[N], b[N], up[N][18], chainHead[N], chainIn[N], sz[N], h[N], t[4 * N], lazy[4 * N], num[N], l[N], r[N];
vector<int> ke[N];

void down(int k, int l, int r) {
    if (lazy[k] != 0) {
        int mid = (l + r) >> 1;
        t[k << 1] += lazy[k];
        t[k << 1 | 1] += lazy[k];
        lazy[k << 1] += lazy[k];
        lazy[k << 1 | 1] += lazy[k];
        lazy[k] = 0;
    }
}

void setup(int k, int l, int r) {
    if (l == r) {
        t[k] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    setup(k << 1, l, mid);
    setup(k << 1 | 1, mid + 1, r);
    t[k] = max(t[k << 1], t[k << 1 | 1]);
}

void update(int k, int l, int r, int u, int v, int val) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
        t[k] += val;
        lazy[k] += val;
        return;
    }
    down(k, l, r);
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, u, v, val);
    update(k << 1 | 1, mid + 1, r, u, v, val);
    t[k] = max(t[k << 1], t[k << 1 | 1]);
}

int get(int k, int l, int r, int u, int v) {
    if (r < u || l > v) return -inf;
    if (l >= u && r <= v) return t[k];
    down(k, l, r);
    int mid = (l + r) >> 1;
    return max(get(k << 1, l, mid, u, v), get(k << 1 | 1, mid + 1, r, u, v));
}

void dfs(int u) {
    sz[u] = 1;
    for (auto v : ke[u]) if (v != up[u][0]) {
        h[v] = h[u] + 1;
        up[v][0] = u;
        for (int i = 1; i <= 17; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
        dfs(v);
        sz[u] += sz[v];
    }
}

int LCA(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int i = 0; i <= 17; ++i)
            if (k & (1 << i)) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; --i)
        if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
    return up[u][0];
}

void HLD(int u) {
    if (chainHead[nchain] == 0) chainHead[nchain] = u;
    chainIn[u] = nchain;
    num[u] = ++m;
    int best = -1;
    for (auto v : ke[u]) if (v != up[u][0]) {
        if (best == -1 || sz[best] < sz[v]) best = v;
    }
    if (best > 0) HLD(best);
    for (auto v : ke[u]) if (up[u][0] != v) {
        if (v != best) {
            ++nchain;
            HLD(v);
        }
    }
    l[u] = r[u] = num[u];
    for (auto v : ke[u]) if (up[u][0] != v) {
        r[u] = max(r[u], r[v]);
    }
}

void upQuery(int u, int v) {
    while (1) {
        if (chainIn[u] == chainIn[v]) {
            update(1, 1, n, num[v], num[u], k);
            break;
        }
        update(1, 1, n, num[chainHead[chainIn[u]]], num[u], k);
        u = up[chainHead[chainIn[u]]][0];
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    m = 0; dfs(1);
    m = 0; HLD(1);
    for (int i = 1; i <= n; ++i) b[num[i]] = a[i];
    setup(1, 1, n);
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, y;
            cin >> x >> y >> k;
            int lca = LCA(x, y);
            upQuery(x, lca); upQuery(y, lca);
            update(1, 1, n, num[lca], num[lca], -k);
        }
        else {
            int x;
            cin >> x;
            int m1 = get(1, 1, n, l[x], r[x]);
            int m2 = -inf, m3 = -inf;
            if (l[x] > 1) m2 = get(1, 1, n, 1, l[x] - 1);
            if (r[x] < n) m3 = get(1, 1, n, r[x] + 1, n);
            int mB = max(m2, m3);
            if (m1 == mB) cout << '=' << endl;
            else if (m1 > mB) cout << '>' << endl;
            else cout << '<' << endl;
        }
    }
}
