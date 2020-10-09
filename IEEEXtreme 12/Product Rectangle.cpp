// Link: https://csacademy.com/ieeextreme-practice/task/product-rectangle/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

int best(vector<int> v){
    int cur= 0, bb= -1e18;

    for (int i= 0; i< v.size(); i++) {
        cur= 0;
        for (int j= i; j< v.size(); j++) {
                cur+= v[j];
                bb= max(bb, cur);
        }
    }

    return bb;
}

int wbest(vector<int> v){
    int cur= 0, bb= 1e18;

    for (int i= 0; i< v.size(); i++) {
        cur= 0;
        for (int j= i; j< v.size(); j++) {
                cur+= v[j];
                bb= min(bb, cur);
        }
    }

    return bb;
}

void solve() {
    int n, m; cin >> n>> m;
    vector<int> v(n);
    vector<int> vm(m);

    for (auto& X: v) cin >> X;
    for (auto& X: vm) cin >> X;

    int best1= best(v);
    int best2= best(vm);

    int best3= wbest(v);
    int best4= wbest(vm);

    cout << max({best1* best4, best2* best3, best1* best2, best3* best4})<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
