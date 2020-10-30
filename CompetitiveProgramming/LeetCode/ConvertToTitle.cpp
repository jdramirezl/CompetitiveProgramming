#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;

string convertToTitle(int n) {
	  string result;
	  while (n) {
	      result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;
	  }
	  reverse(result.begin(), result.end());
	  return result;
}
