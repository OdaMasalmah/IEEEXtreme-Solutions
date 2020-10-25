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

int n;
vector<pair<int, int>> v;
set<int> all;

const int mod = 1e9 + 7;

int fastPower(int x, int y){
    if(y == 0)
        return 1;
    int z = fastPower(x, y/2);
    if(y%2)
        return ((z*z)%mod)*x;
    return (z*z)%mod;
}

bool valid(int x, int y, int k){
    queue<int> q;
    q.push(x);
    set<int> remain = all;
    remain.erase(x);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == y)
            return true;
        set<int> copy = remain;
        for(int z: copy){
            if(abs(v[x].first - v[z].first) + abs(v[x].second - v[z].second) <= k+1){
                q.push(z);
                remain.erase(z);
            }
        }
    }
    return false;
}

void solve(){
    int q, sq, mk;
    cin>>n>>q>>sq>>mk;

    v = vector<pair<int, int>> (n);
    lp(i, n) cin>>v[i].first>>v[i].second;

    int as, bs, cs, at, bt, ct, ak, bk, ck;
    cin>>as>>bs>>cs>>at>>bt>>ct>>ak>>bk>>ck;

    vector<vector<int>> query(q, vector<int>(3));
    lp(i, sq){
        cin>>query[i][0]>>query[i][1]>>query[i][2];
    }
    lp3(i, sq, q){
        query[i][0] = (as * query[i-1][0] + bs * query[i-2][0] + cs) % n +1;
        query[i][1] = (at * query[i-1][1] + bt * query[i-2][1] + ct) % n +1;
        query[i][2] = (ak * query[i-1][2] + bk * query[i-2][2] + ck) % mk;
    }
    
    lp(i, n)
        all.insert(i);
    valid(query[3][0]-1, query[3][1]-1, query[3][2]);

    int ans = 0;
    lp(i, q){
        if(valid(query[i][0]-1, query[i][1]-1, query[i][2]))
            ans = (ans + fastPower(2, i+1)) % mod;
    }
    
    cout<<ans<<endl;   
}

int32_t main() {  fastIO
    
    solve();
    
    return 0;
}
