// Link: https://csacademy.com/ieeextreme-practice/task/ranged-alfa-pool/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

const int inf= 1e9;
const int N= 1e6+ 1;
int pref[N];
int dp[N][22][2];

void add(int &a, int b) {
        if (a>= mod) a-= mod;
        if (b>= mod) b-= mod;
        if (b< 0) b+= mod;
        if (a< 0) a+= mod;
        a+= b;
        if (a>= mod) a-= mod;
        if (a< 0) a+= mod;
}

int calc(int idx, int wh, bool wn) {
        if (idx== 0) return 1;

        int &ret= dp[idx][wh][wn];
        if (ret!= -1) return ret;
        ret= 0;

        if ((1<< wh)<= idx) {
                add(ret, calc(idx- (1<< wh), wh+ 1, 1));
        }
        if (wn== 1){
               add(ret, calc(idx, 0, 0));
        }
        return ret;
}

void solve() {
        memset(dp, -1, sizeof dp);

        pref[0]= 1;
        for (int i= 1; i< N; i++) {
                add(pref[i], pref[i- 1]);
                add(pref[i], calc(i, 0, 1));
        }

        int T; cin >> T;
        while (T--) {
                int a, b; cin >> a>> b;
                int x= pref[b];
                int y= a== 0? 0: pref[a- 1];
                add(x, -y);
                cout << x<< "\n";
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
