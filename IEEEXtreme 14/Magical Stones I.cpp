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


void solve(){
    int n; cin>>n;
    vector<int> v(n);
    lp(i, n){ cin>>v[i]; --v[i]; }

    set<int> all;
    lp(i, n) all.insert(i);

    map<int, int> ans;
    set<set<int>> seen;
    seen.insert(all);
    for(int i = 1; ; i++){
        set<int> next;
        for(int x: all){
            next.insert(v[x]);
        }
        if(next.size() < all.size()){
            ans[next.size()] = i;
        }

        if(seen.count(next) || next.empty()){
            break;
        }
        seen.insert(next);
        all = next;
    }

    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        if(ans.count(x))
            cout<<ans[x]<<endl;
        else
            cout<<-1<<endl;
    }
    
}

int32_t main() {  fastIO
    
    solve();
    
    return 0;
}
