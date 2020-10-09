//https://csacademy.com/ieeextreme-practice/task/lexical-addition/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (v).size()
#define int long long
#define mod 1000000007

int n, a, b;
vector<int> vv;

void bal(int i, int j) {
        if (i >= j) return;
        if (vv[i] == a) { bal(i + 1, j); return; }
        if (vv[j] == b) { bal(i, j - 1); return; }
        int wh = vv[i] - a;
        int rm = b - vv[j];
        if (wh >= rm) {
                vv[j] = b;
                wh -= rm;
                vv[i] -= rm;
                bal(i, j - 1);
        } else {
                vv[j] += wh;
                vv[i] = a;
                bal(i + 1, j);
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        cin >> n>> a>> b;
        if (n < a) {
                cout << "NO";
                return 0;
        }
        for (int i = 1; i <= 111111; i++) {
                int ans = n / i;
                if (ans >= a && ans <= b) {
                        if (i * b < n) continue;
                        cout << "YES\n";
                        int md = n % i;
                        int sm = 0;
                        for (int j = 0; j < i; j++) {
                                vv.push_back(ans);
                                sm += ans;
                        }
                        int re = n - sm;
                        lp(i, vv.size()) {
                                if (vv[i] + re > b) {
                                        re -= b - vv[i];
                                        vv[i] = b;
                                } else {
                                        vv[i] += re;
                                        re = 0;
                                }
                        }
                        sort(all(vv));
                        //lp(i, vv.size()) cout << vv[i]<< " ";
                        //cout << endl;
                        bal(0, vv.size() - 1);
                        lp(i, vv.size()) cout << vv[i]<< " ";
                        return 0;
                }
        }
        cout << "NO";
return 0;
}
