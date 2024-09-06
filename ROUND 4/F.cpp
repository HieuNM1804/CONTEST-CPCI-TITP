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
//#define int long long

using namespace std;

int32_t main(){
    int x, y, z; cin >> x >> y >> x;
    scanf("\n");
    map<string, int> m1, m2, m3;
    string s1, s2, s3; 
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    vector<string> v, total;
    stringstream ss1(s1), ss2(s2), ss3(s3);
    string w;
    while(ss1 >> w){
        v.pb(w);
        total.pb(w);
    }
    for(int i = 0; i < sz(v); i += 2) m1[v[i]] += stoll(v[i+1]);
    v.clear();
    while(ss2 >> w){
        v.pb(w);
        total.pb(w);
    }
    for(int i = 0; i < sz(v); i += 2) m2[v[i]] += stoll(v[i+1]);
    v.clear();
    while(ss3 >> w){
        v.pb(w);
        total.pb(w);
    }
    for(int i = 0; i < sz(v); i += 2) m3[v[i]] += stoll(v[i+1]);
    map<string, int> ok;
    for(auto it : m1){
        if(it.se >= 20 && m2[it.fi] >= 20 && m3[it.fi] >= 20)
            ok[it.fi] = 1;
    }
    vector<string> ans;
    for(int i = 0; i < sz(total); i += 2){
        if(ok[total[i]]){
            ans.pb(total[i]);
            ok[total[i]] = 0;
        }
    }
    cout << sz(ans) << ' ';
    for(auto it : ans) cout << it << ' ';
}