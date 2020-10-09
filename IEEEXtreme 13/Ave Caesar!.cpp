// Link: https://csacademy.com/ieeextreme-practice/task/ave-caesar/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()

void solve() {
        string str; cin >> str;

        vector<string> an;
        string s= "";
        s+= str[0];

        for (int i= 1; i< str.size(); i++) {
                if (str[i- 1]> str[i]) {
                        an.push_back(s);
                        s= "";
                        s+= str[i];
                } else s+= str[i];
        }

        if (s.size()) an.push_back(s);
        
        sort(all(an));
        string ne= "";
        for (int i= 0; i< an.size(); i++) ne+= an[i];
        if (ne== str) cout << "1";
        else cout << "0";
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
