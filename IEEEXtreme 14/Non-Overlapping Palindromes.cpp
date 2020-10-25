#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,avx")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

pair<int, int> palstring(const string &s) {
        int n= s.size();
        vector<int> d1(n);// for odd position store (x+ 1)/ 2 for every i
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n); // for even position store (x)/ 2 for every i
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        int mx= 1, fr= 0;
        for (int i= 0; i< n; i++) {
                if (d1[i]* 2- 1> mx) {
                        mx= d1[i]* 2- 1;
                        fr= i- d1[i]+ 1;
                }
        }

        for (int i= 0; i< n; i++) {
                if (d2[i]* 2> mx) {
                        mx= d2[i]* 2;
                        fr= i- d2[i];
                }
        }
        return {fr, mx};
}

void solve() {
        int t; cin >> t;
        while ( t-- ) {
                string str; cin >> str;
                bool all= 1;
                int n= (int)str.size();
                for (int i= 1; i< n; i++) if(str[i]!= str[i- 1]) all= 0;
                if (all) {
                        cout << n<< "\n";
                        continue;
                }
                int ans= 0;
                pair<int, int> p= palstring(str);
                if (n== p.second) {
                        cout << n-1<< "\n";
                        continue;
                }
                {
                        if (p.second> 0) {
                                pair<int, int> c1= palstring(str.substr(0, p.first));
                                ans= max(ans, c1.second);
                        }
                        if (p.second+ p.first< str.size()) {
                                pair<int, int> c1= palstring(str.substr((p.second+ p.first), str.size()-(p.second+ p.first)));
                                ans= max(ans, c1.second);
                        }
                        cout << ans+ p.second<< "\n";
                }

        }
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
