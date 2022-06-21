#include <bits/stdc++.h>

#define MAXN 100
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int a[MAXN], ans[MAXN];

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
int main(){ 
    fast_io; 
    int n; 
    cin >> n; 
    if(n > 100)
        return 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        ans[i] = 0;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j)
                continue;
            for(int k = j+1; k<n; k++){
                if(i == k)
                    continue;
                if(gcd(a[j], a[k]) % (2*a[i]) == 0){
                    ans[i]++;
                }
            }
        }

        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}