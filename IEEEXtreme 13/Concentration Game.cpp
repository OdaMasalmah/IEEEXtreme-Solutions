// Link: https://csacademy.com/ieeextreme-practice/task/concentration-game/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        vector<int> v(n* 2+ 1);

        for (int i= 1; i<= 2* n; i+= 2) {
                cout << (i)<< " "<< (i+ 1)<< endl;
                string str; cin >> str;
                if (str[0]== 'M') {
                        v[i]= v[i+ 1]= -1;
                } else {
                        int x1, x2;
                        x1= stoi(str);
                        cin >> x2;
                        v[i]= x1;
                        v[i+ 1]= x2;
                }
        }
        for (int i= 1; i<= 2* n; i++) {
                if (v[i]== -1) continue;
                else {
                        for (int j= i+ 1; j<= 2* n; j++) {
                                if (v[i]== v[j]) {
                                        cout << i<< " "<< j<< endl;
                                        v[i]= v[j]= -1;
                                        string str; cin>> str;
                                        break;
                                }

                        }
                }
        }
        cout << "-1"<< endl;
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
