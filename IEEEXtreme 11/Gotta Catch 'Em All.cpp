// Link: https://csacademy.com/ieeextreme-practice/task/e610aba28810ebcf2d3998692269b5a0/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

const int N= 202;
int dp[N][N];

void solve() {
        int n, m; cin >> n>> m;
        vector<vector<int>> v(n);
        for (int i= 0; i< n; i++) {
                for (int j= 0; j< m; j++) {
                        int x; cin >> x;
                        v[i].push_back(x);
                }
        }

        auto can= [&](int md) {
                for (int i= 0; i<= n; i++) for (int j= 0; j<= m; j++) dp[i][j]= -1e10;
                dp[0][1]= dp[1][0]= md;
                for (int i= 1; i<= n; i++) {
                        for (int j= 1; j<= m; j++) {
                                dp[i][j]= max({dp[i- 1][j], dp[i][j- 1]})+ v[i- 1][j- 1];
                                if (dp[i][j]<= 0) dp[i][j]= -1e10;
                        }
                }

                return dp[n][m]>= 1;
        };

        int lo= -1e5, hi= 1e5;
        while (hi- lo> 1) {
                int md= (lo+ hi)/ 2;
                if (can(md)) hi= md;
                else lo= md;
        }

        cout << hi<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
