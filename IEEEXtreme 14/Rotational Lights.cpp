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

vector<int> getFactors(int n){
    vector<int> res;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            res.push_back(n/i);
        }
    }
    return res;
}

void solve(){
    
    int n, t;
    cin>>n>>t;

    vector<int> v(n);
    lp(i, n) cin>>v[i];

    set<int> st(v.rbegin(), v.rend());


    vector<int> factors = getFactors(n);

    sort(factors.rbegin(), factors.rend());

    int mx = 1;
    for(int i: factors){
        if(t % i == 0){
            bool sem = true;
            for(int x: st){
                if(st.count((x+t/i)%t) == 0){
                    sem = false;
                    break;
                }
            }
            if(sem){
                cout<<t/i-1<<endl;
                return;
            }
        }
    }
        
    cout<<t-1<<endl;

}

int32_t main() {  fastIO
    
    solve();
    
    return 0;
}
