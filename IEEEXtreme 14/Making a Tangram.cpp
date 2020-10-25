#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define int ll

int32_t main(){
    FAST
    string s = "";
    for(char i = 'a'; i <= 'z'; i++){
        s += i;
    }
    for(char i = 'A'; i <= 'Z'; i++){
        s += i;
    }
    for(char i = '0'; i <= '9'; i++){
        s += i;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n <= 3){
            cout << "impossible" << endl;
            continue;
        }
        char mat[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = s[n - 1];
            }
        }
        for(int i = 0; i < n; i++){
            mat[i][0] = s[0];
        }
        for(int i = 1; i < n - 1; i++){
            if(i%2){
                int row = i/2;
                int cnt = 0;
                for(int j = 1; j < n; j++){
                    if(mat[row][j] != s[n - 1])row++, j--;
                    mat[row][j] = s[i];
                    cnt++;
                }
                if(cnt != n){
                    mat[row + 1][n - 1] = s[i];
                }
            }
            else{
                int row = n - i/2;
                int cnt = 0;
                for(int j = 1; j < n; j++){
                    if(mat[row][j] != s[n - 1])row--, j--;
                    mat[row][j] = s[i];
                    cnt++;
                }
                if(cnt != n){
                    mat[row - 1][n - 1] = s[i];
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
