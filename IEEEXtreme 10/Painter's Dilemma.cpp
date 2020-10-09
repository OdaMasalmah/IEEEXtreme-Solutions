//Link: https://csacademy.com/ieeextreme-practice/task/painters-dilemma/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()

const int N= 501;
int dp[N][25][25];

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for(auto& i: v) cin >> i;

        memset(dp, -1, sizeof dp);
        function<int(int, int, int)> calc=[&](int idx, int f, int s)->int{
                if (idx>= n) return 0;

                int &ret= dp[idx][f][s];
                if (ret!= -1) return ret;
                ret= 1e10;

                if (f== v[idx]) {
                        ret= min(ret, calc(idx+ 1, f, s));
                        ret= min(ret, calc(idx+ 1, f, v[idx])+ 1);
                } else if(v[idx]== s) {
                        ret= min(ret, calc(idx+ 1, f, s));
                        ret= min(ret, calc(idx+ 1, v[idx], s)+ 1);
                } else {
                        ret= min(ret, calc(idx+ 1, v[idx], s)+ 1);
                        ret= min(ret, calc(idx+ 1, f, v[idx])+ 1);
                }
                return ret;
        };
        cout << calc(0, 22, 22)<< "\n";
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
