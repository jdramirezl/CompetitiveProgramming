#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, temp;
    while(true){
        cin >> n >> b;
        if (n==0 && b == 0) break;
        unordered_set<int> nums;
        vector<int> vec;
        for(int i=0; i<b; ++i){
            cin >> temp;
            nums.insert(temp);
            vec.push_back(temp);
        }
        
        bool found;
        for(int i=1; i<=n; ++i){
            found = false;
            for(int j = 0; j < vec.size(); ++j){
                if(nums.count(vec[j] + i) > 0){
                    found = true;
                    break;
                }
            }

            if(!found){
                cout << "N" << endl;
                break;
            }
        }

        if(found) cout << "Y" << endl;
    }
}