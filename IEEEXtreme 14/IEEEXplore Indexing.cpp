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
    string str;
    getline(cin, str);
    stringstream ss(str);
    set<string> stop;
    while(getline(ss, str, ';')) {
        stop.insert(str);
    }
    getline(cin, str);
    stringstream sss(str);
    set<string> indx;
    while(getline(sss, str, ';')) {
        indx.insert(str);
    }
    
    bool title = false, body = false, abstract = false;

    map<string, int> sw;
    int L = 0;

    while(cin>>str){
        start:
        if(str.empty())
            continue;
        if(str[0] == '<'){
            if(str[1] != '/'){
                string tag;
                lp(i, str.size()){
                    if(str[i] == '>'){
                        tag = str.substr(1, i-1);
                        str = str.substr(i+1);
                        break;
                    }
                }
                if(tag == "title")
                    title = true;
                if(tag == "body")
                    body = true;
                if(tag == "abstract")
                    abstract = true;
            }
            else{
                string tag;
                lp(i, str.size()){
                    if(str[i] == '>'){
                        tag = str.substr(2, i-2);
                        str = str.substr(i+1);
                        break;
                    }
                }
                if(tag == "title")
                    title = false;
                if(tag == "body")
                    body = false;
                if(tag == "abstract")
                    abstract = false;
            }
            goto start;
        }

        string remain = "123?_what!!!!omg";
        lp(i, str.size()){
            if(str[i] == '<'){
                remain = str.substr(i);
                str = str.substr(0,i);
                break;
            }
        }

        string s = "";
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '?' || str[i] == '!' || str[i] == ',' || str[i] == '.')
                continue;
            if(isalpha(str[i]))
                str[i] = tolower(str[i]);
            if(isalpha(str[i]) || str[i] == '\'')
                s += str[i];
        }

        str = s;

        stringstream ss(str);

        while(ss>>str){
            if(title || body || abstract){
                if(stop.count(str) == 0){
                    if(str.size() >= 4){
                        L++;
                    }
                }   
                if(indx.count(str)){
                    if(title){
                        sw[str] += 5;
                    }
                    if(abstract){
                        sw[str] += 3;
                    }
                    if(body){
                        sw[str] += 1;
                    }
                }
            }
        }

        if(remain != "123?_what!!!!omg"){
            str = remain;
            goto start;
        }

    }

    vector<pair<string, int>> ans(sw.begin(), sw.end());
    sort(ans.begin(), ans.end(), [](auto a, auto b){
        if(a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });
    
    int len = min(3ll, int(ans.size()));
    
    lp(i, len){
        cout<<fixed<<showpoint<<setprecision(16)<<ans[i].first<<": "<<ans[i].second*100.0/L<<endl;
    }

    if(ans.size() >= 4){
        lp3(i, 3, ans.size()){
            if(ans[i].second != ans[2].second)
                break;
            cout<<fixed<<showpoint<<setprecision(16)<<ans[i].first<<": "<<ans[i].second*100.0/L<<endl;
        }
    }

}

int32_t main() {  fastIO
    
    solve();
    
    return 0;
}
