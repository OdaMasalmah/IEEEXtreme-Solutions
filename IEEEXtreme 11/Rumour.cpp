// Link: https://csacademy.com/ieeextreme-practice/task/9ca8fafd184f553a903734761546a224/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int a, b; cin >> a>> b;
        int cnt= 0;

        while (a!= b) {
                if (a> b) swap(a, b);
                b/= 2;
                cnt+= 1;
        }

        cout << cnt<< "\n";
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
