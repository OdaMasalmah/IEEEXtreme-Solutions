// Link: https://csacademy.com/ieeextreme-practice/task/f8d68dbb0c844910797ce64354c66143/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
#define mod 1000000007

void solve() {
        int l, w, n, x, y; cin >> l>> w>> n>> x>> y;
        auto XorTo= [](int x) {
                int ans= 0;
                switch(x% 4) {
                        case 0: ans= x; break;
                        case 1: ans= 1; break;
                        case 2: ans= x+ 1; break;
                        case 3: ans= 0; break;
                }
                return ans;
        };

        auto XorRange= [&](int L, int R) {
                return XorTo(R)^ XorTo(L- 1);
        };

        int answer= XorRange(n, l* w+ n- 1);

        int a= (x- n)% l;
        int b= (y- n)% l;
        int df= ((y- n)% l- (x- n)% l);
        if (a> b) {
                df= ((x- n)% l- (y- n)% l);
                x-= df;
                y+= df;
        }

        while (x<= y- df) {
                answer^= XorRange(x, x+ df);
                x+= l;
        }

        cout << answer<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
return 0;
}
