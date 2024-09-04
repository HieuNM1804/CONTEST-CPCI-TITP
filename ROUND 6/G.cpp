#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long
#define double long double

using namespace std;

bool are_close(double x, double y, double tol = 1e-9) {
    return abs(x - y) < tol;
}

void solve(){
    int n; cin >> n;
    double a, b, c; 
    set<double> ans;
    vector<tuple<double, double, double>> v;
    FOR(i, 1, n){
        cin >> a >> b >> c;
        v.pb({a, b, c});
    }

    FOR(i, 1, n){
        auto [a, b, c] = v[i - 1];
        if(a == 0){
            if(b == 0 && c == 0){
                cout << -1 << endl; 
                return;
            }
            else if(b == 0 && c) continue; 
            else{
                double x = (double)-c / b;
                if(ans.find(x) == ans.end()){
                    ans.insert(x);
                }
            }
        }
        else{
            double delta = b * b - 4 * a * c;
            if(delta >= 0){
                double x1 = (-b + sqrt(delta)) / (2 * a);
                double x2 = (-b - sqrt(delta)) / (2 * a);

                for (auto& root : {x1, x2}) {
                    bool found = false;
                    for (auto& r : ans) {
                        if (are_close(root, r)) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        ans.insert(root);
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
