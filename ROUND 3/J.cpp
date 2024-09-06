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
#define matrix vector<vector<int>>
#define int long long

using namespace std;

int A, B, M;

matrix init(){
    return vector<vector<int>>(2, vector<int>(2, 0));
}

matrix mul(const matrix &a, const matrix &b){
    matrix c = init();
    FOR(i, 0, 1){
        FOR(j, 0, 1){
            FOR(k, 0, 1){
                c[i][j] += (a[i][k] % M) * (b[k][j] % M) % M;
                c[i][j] %= M;
            }
        }
    }
    return c;
}

matrix Pow(matrix a, int b){
    if(b == 0){
        matrix I = init();
        I[0][0] = I[1][1] = 1;
        return I;
    }
    matrix x = Pow(a, b / 2);
    if(b % 2 == 0) return mul(x, x);
    else return mul(a, mul(x, x));
}

void solve(){
    cin >> A >> B >> M;
    int x = __gcd(A, B);
    matrix F = init();
    F[0][0] = 1;
    matrix T = init();
    T[0][0] = T[0][1] = T[1][0] = 1;
    cout << mul(Pow(T, x - 1), F)[0][0] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int TC = 1;
    cin >> TC;
    while(TC--) solve();
    return 0;
}