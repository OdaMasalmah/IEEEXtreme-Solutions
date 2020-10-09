// Link: https://csacademy.com/ieeextreme-practice/task/alfa-pool/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long 
#define mod 1000000007

const int inf= 1e9;
const int N= 1e5+ 12;

int dp[N][22][2];

void solve() {
        int n; cin >> n;
        function<int(int, int, bool)> calc= [&](int idx, int wh, bool wn)->int {
                if (idx== 0) return 1;

                int &ret= dp[idx][wh][wn];
                if (ret!= -1) return ret;
                ret= 0;

                if ((1<< wh)<= idx) {
                        ret= (ret+ calc(idx- (1<< wh), wh+ 1, 1))% mod;
                }
                if (wn== 1){
                        ret= (ret+ calc(idx, 0, 0))% mod;
                }
                return ret;
        };

        cout << (calc(n, 0, 1)% mod)<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        memset(dp, -1, sizeof dp);
        cin >> T;
        while ( T-- ) solve();
return 0;
}
