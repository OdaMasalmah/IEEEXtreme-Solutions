// Link: https://csacademy.com/ieeextreme-practice/task/telescope-scheduling/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()

const int M= 10001;
const int N= 1011;
int dp[M][N];

void solve() {
        int n; cin >> n;
        vector<pair<int, pair<int, int>>> v(n);
        for (int i= 0; i< n; i++) {
                int l, r, x; cin >> l>> r>> x;
                v[i]= {l, {r, x}};
        }

        sort(all(v));

        memset(dp, -1, sizeof dp);

        function<int(int, int)> calc= [&](int idx, int last)->int{
                if (idx>= n) {
                        return 0;
                }

                int &ret= dp[idx][last];
                if (ret!= -1)return ret;
                ret= 0;

                ret= max(ret, calc(idx+ 1, last));
                if (last!= N) {
                        if (v[idx].first> last)
                                ret= max(ret, calc(idx+ 1, v[idx].second.first)+ v[idx].second.second);
                } else if (last== N)
                        ret= max(ret, calc(idx+ 1, v[idx].second.first)+ v[idx].second.second);

                return ret;
        };

        cout << calc(0, N);
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
