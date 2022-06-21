#include <bits/stdc++.h>

#define MAXN 100
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

pair<int, pair<string, int>> a[MAXN];

bool compare(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b){
    return a.second.first > b.second.first;
}

int main(){
    fast_io;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i].second.first;
        a[i].first = i;
    }
    
    sort(a, a+n, compare);
    a[0].second.second = a[0].second.first.size() + 1;
    for(int i = 1; i<n; i++){
        if(a[i].second.first[0] == a[i-1].second.first[0]){
            if(a[i].second.first.size() + 1 == a[i-1].second.first.size()
            || a[i].second.first.size() == a[i-1].second.first.size()){
                a[i].second.second = a[i-1].second.second;
            }
            else{
                a[i].second.second = a[i].second.first.size() + 1;
            }
        }else{
            a[i].second.second = a[i].second.first.size() + 1;
        }
        //cout << a[i].second.first << ' ' << a[i].second.second - a[i].second.first.size() - 1 << endl;

    }

    sort(a, a+n);

    // print a
    for(int i = 0; i<n; i++){
        // cout << a[i].second.first << ' ' << a[i].second.second - a[i].second.first.size() << endl;
        cout << a[i].second.second - a[i].second.first.size() << ' ';
    }
    cout << endl;

    return 0;
}