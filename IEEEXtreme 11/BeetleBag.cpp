// Link: https://csacademy.com/ieeextreme-practice/task/ed8629419f140a5a2c923b049aba1224/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

int dp[201][555];

void solve() {
        int c, n; cin >> c>> n;
        vector<pair<int, int>> v;

        for (int i= 0; i< n; i++) {
                int x, y; cin >> x>> y;
                v.push_back({x, y});
        }

        memset(dp, -1, sizeof dp);

        function<int(int, int)> calc= [&](int idx, int cost)->int{
                if (idx>= n) {
                        return 0;
                }

                int &ret= dp[idx][cost];
                if (ret!= -1) return ret;
                ret= 0;

                if (cost+ v[idx].first<= c)
                        ret= max(ret, calc(idx+ 1, cost+ v[idx].first)+ v[idx].second);
                ret= max(ret, calc(idx+ 1, cost));
                return ret;
        };

        cout << calc(0, 0)<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
