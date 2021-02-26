#include <bits/stdc++.h>
using namespace std;

void divisors(int n, unordered_set<int> &divis){
    for (int i=1; i*i<=n; i++) { 
        if (n%i == 0) { 
            if (n/i == i){ 
                divis.insert(i); 
            }
            else {
                divis.insert(i); 
                divis.insert(n/i); 
            }
        } 
    } 
}

int main(){
    int n, smallest = INT_MAX, temp;
    cin >> n;
    vector<int> nums (n, 0);
    unordered_set<int> divis;

    for(int i=0; i<n; ++i){
        cin >> temp;
        smallest = min(smallest, temp);
        nums[i] = temp;
    } 

    divisors(smallest, divis);

    for(int i=0; i<n; ++i){
        if(nums[i] != smallest){
            for(const auto &div: divis){
                if(nums[i]%div != 0) divis.erase(div);
            }
        }
    }

    cout << divis.size();
}