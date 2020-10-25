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
    int w, h, r, c;
    cin>>w>>h>>r>>c;
    int cnt = ((w+r-1)/r) * ((h+c-1)/c);
    int total = 0;
    int arr[r][c];
    for(int j = 0; j < r; j++){
        for(int z = 0; z < c; z++){
            cin >> arr[j][z];
            total += cnt*arr[j][z];
        }
    }
    if(w%r != 0){
        vector<int> vec;
        for(int j = 0; j < w - w%r; j++){
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < c; i++){
                sum1 += arr[j][i];
                sum2 += arr[r - j - 1][i];
            }
            vec.pb(sum1);
            vec.pb(sum2);
        }
        sort(vec.rbegin(), vec.rend());
        for(int a = 0; a < w - w%r; a++){
            total -= vec[a];
        }
    }
    if(h%c != 0){
        vector<int> vec;
        for(int j = 0; j < h - h%c; j++){
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < r; i++){
                sum1 += arr[i][j];
                sum2 += arr[i][c - j - 1];
            }
            vec.pb(sum1);
            vec.pb(sum2);
        }

        sort(vec.rbegin(), vec.rend());
        for(int a = 0; a < h - h%c; a++){
            total -= vec[a];
        }
    }
    cout << total << endl;
}

int32_t main() {  fastIO

    solve();

    return 0;
}
