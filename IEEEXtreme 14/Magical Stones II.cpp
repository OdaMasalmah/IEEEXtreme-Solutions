#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,avx")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (ll)(v).size()
#define mod 1000000007

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve() {
        int n; cin >> n;

        vector<int> v[2];
        for (int i= 0; i< n; i++) {
                int X; cin >> X;
                v[0].push_back(X);
        }

        for (int i= 0; i< n; i++) {
                int X; cin >> X;
                v[1].push_back(X);
        }

        auto change= [&](vector<int> &ar, int kind) {
                for (int jj= 0; jj< n; jj++) {
                        ar[jj]= v[kind][ar[jj]- 1];
                }
        };

        for (int i= 0; i<= 11; i++) {
                vector<int> ar;

                for (int ii= 1; ii<= n; ii++) ar.push_back(ii);
                vector<bool> vb;
                for (int j= 0; j<= 3041; j++) {
                        vb.push_back(rand(0, 123)% 2);
                        change(ar, vb.back());
                        set<int> st;
                        for (int jj= 0; jj< n; jj++) st.insert(ar[jj]);
                        if (st.size()== 1) {
                                for (int kk= 0; kk< vb.size(); kk++) {
                                        if (vb[kk]) cout << "B";
                                        else cout << "W";
                                }
                                cout << "\n";
                                return;
                        }
                }

        }
        cout << "impossible\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
return 0;
}
