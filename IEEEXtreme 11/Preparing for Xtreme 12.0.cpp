// Link: https://csacademy.com/ieeextreme-practice/task/72a7d67e7e18f4f7d033f7f5a5a09bef/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

const int MB= 21;
const int MN= 101;
map<string, int> mp;
int cnt;

void solve() {
        string str, T;
        vector<pair<int, int>> vs;
        int B= 0;

        while (getline(cin, str)) {

                B++;
                istringstream ss(str);
                int j= 0, nm= 0, mask= 0;

                do {
                        if (!j) {
                                ss >> T;
                                nm= stoi(T);
                        } else {
                                ss >> T;
                                if (mp.count(T)) {
                                        mask|= (1<< mp[T]);
                                } else {
                                        mp[T]= cnt;
                                        mask|= (1<< cnt);
                                        cnt+= 1;
                                }
                        }
                        j++;

                }while (ss);

                vs.push_back({nm, mask});
        }

        vector<int> dp((1<< cnt));

        for (int kk= 0; kk< 1<<(cnt); kk++) dp[kk]= (-1);


        int val= (1<< cnt)- 1;

        function<int(int)> calc= [&](int msk)->int{
                if (msk== val) {
                        return 0;
                }

                int &ret= dp[msk];
                if (ret!= -1)return ret;
                ret= 1e18;

                for (int i= 0; i< B; i++) {
                        ret= min(ret, calc(msk| vs[i].second)+ vs[i].first);
                }

                return ret;
        };

        cout << calc(0)<< "\n";
}

int32_t main(){
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
