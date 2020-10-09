// Link: https://csacademy.com/ieeextreme-practice/task/bear-sums/
#include <bits/stdc++.h>
using namespace std;
#define lp(i, x, n) for (int i = x; i < (int)n; i++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define ll long long
#define N 100011

int main() {
        int t; cin >> t;
        while (t--) {
                int s, n, res = 0;
                cin >> s>> n;
                map<int, int> mp;
                bool b = 1;
                lp (i, 0, n) {
                        int a;
                        cin >> a;
                        if (mp.count(a) && b) {
                                res = a;
                                b = 0;
                        } else mp[s - a] = 1;
                }
                if (b) {
                        cout << "!OK\n";
                } else
                        cout << min(res, s - res)<< " "<< max(res, s - res)<< endl;
        }
        return 0;
}
