#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll


#define lp3(i,s,n) for(int i = s;i < int(n); ++i)
#define lp(i, n) lp3(i,0,n)
#define pb push_back
#define debug(x) cout<<"[" << #x << " is: " << x << "] "<<endl;

#define file freopen("input.in","r",stdin);
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0);

int max(int a, int b){
    return a > b ? a : b;
}

map<string, int> dp;

int calc(int c, int h, int o){
    if(c+h+o == 0)
        return 0;

    string key = to_string(c)+"-"+to_string(h)+"-"+to_string(o);
    if(dp.count(key))
        return dp[key];

    int ch1, ch2, ch3;
    ch1 = ch2 = ch3 = 1e10;
    if(c+o){
        int cc = max(1 - c, 0);
        int oo = max(2 - o, 0);
        ch1 = cc + oo + calc(max(c-1, 0), h, max(o-2, 0));
    }

    if(h+o){
        int hh = max(2 - h, 0);
        int oo = max(1 - o, 0);
        ch2 = hh + oo + calc(c, max(h-2, 0), max(o-1, 0));
    }

    if(c+o+h){
        int cc = max(6 - c, 0);
        int hh = max(12 - h, 0);
        int oo = max(6 - o, 0);
        ch3 = cc + oo + hh + calc(max(c-6, 0), max(h-12, 0), max(o-6, 0));
    }

    return dp[key] = min(min(ch1, c+h+o), min(ch2, ch3));
}

void solve(){
    int c, h, o;
    cin>>c>>h>>o;

    cout<<calc(c, h, o)<<endl;
}

int32_t main() {  fastIO
    
    int t; cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
