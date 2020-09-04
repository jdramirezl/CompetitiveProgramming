#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define ll long long
#define ld long double
#define ms(ar, val) memset(ar, val, sizeof ar)

using namespace std;

int anagram(string a, string b){
  unordered_map<char, int> mapa; //O(1) O(1) -> O(n) O(n)
  unordered_map<char, int> mapb;
  
  for(int i = 0; i<a.size(); ++i){
    mapa[a.at(i)]++;
  }
  
  for(int i = 0; i<b.size(); ++i){
    mapb[b.at(i)]++;
  }
  
  //B to A
  int count = 0;
  for(auto const& kv: mapb){
    if(mapa.count(kv.first) > 0){
      int dif = abs(kv.second-mapa[kv.first]); 
      count += dif;
      mapa[kv.first] = 0;
      mapb[kv.first] = 0;
    }
    else{
      count += kv.second;
    }
  }
  
  //A to B
  for(auto const& kv: mapa){
    if(mapb.count(kv.first) == 0){
      count += kv.second;
    }
  }
  
  return count;
  
}

int main()
{
    cout.precision(20);
    string a;
    string b;
    cin >> a >> b;

    int ans = anagram(a,b);

    cout << ans;
}