#include <bits/stdc++.h>

using namespace std;

struct Building{
    int stock, type, index;

    Building(){
        stock = 0;
        type = 0;
        index = -1;
    }

    Building(int s, int t, int i){
        stock = s;
        type = t;
        index = i;
    }

    bool operator>(const Building& b) const{
        return stock > b.stock;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int typeA, typeB, typeC;
    cin >> typeA >> typeB >> typeC;
    int n = typeA + typeB + typeC;
    vector<Building> buildings(3*n);
    vector<bool> selected(n, false);

    int temp = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> temp;
            buildings[i*3 + j] = Building(temp, j, i);
        }
    }
    sort(buildings.begin(), buildings.end(), greater<Building>());

    int total = 0, i = 0;

    while(i<3*n){
        if(typeA + typeB + typeC == 0)
            break;
        if(selected[buildings[i].index]){
            i++;
            continue;
        }

        switch(buildings[i].type){
            case 0:
                if(typeA > 0){
                    typeA--;
                    total += buildings[i].stock;
                    selected[buildings[i].index] = true;
                }
                break;
            case 1:
                if(typeB > 0){
                    typeB--;
                    total += buildings[i].stock;
                    selected[buildings[i].index] = true;
                }
                break;
            case 2:
                if(typeC > 0){
                    typeC--;
                    total += buildings[i].stock;
                    selected[buildings[i].index] = true;
                }
                break;
        }
        i++;
    }

    cout << total << endl;
    return 0;
}