// Link: https://csacademy.com/ieeextreme-practice/task/lemons/
#include <bits/stdc++.h>
using namespace std;
#define lp(i, x, n) for (int i = x; i < (int)n; i++)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define ll long long
#define N 100011

int n, m, s;

ll solve(int nm) {
        if (nm == 2) {
                return m + s;
        }
        if (nm == 3) {
                return (m + s) << 1;
        }
        ll res = (nm >> 1) * m + s;
        res += solve(nm - (nm >> 1));
        return res;
}

int main() {
        cin >> n>> m>> s;
        if (n == 2) {
                cout << "0";
        }else cout << solve(n);
        return 0;
}
