#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;


string reverseWords(string s) {
  stack<string> text;
  string ans;
  if(s.empty()) return "";
  int i;
  //Check for initial spaces
  if(s[0] == ' '){
      i = 0;
      while(s[i] == ' '){
          i++;
      }
      s = s.substr(i-1);
  }

  string temp;
  i = 0;
  while(i<s.length()){
      if(s[i] != ' '){
          temp = "";
          while(i < s.length() && s[i] != ' '){
              temp += s[i];
              i++;
          }
          text.push(temp);
          s = s.substr(i);
          i = 0;
      }
      i++;
  }

  while(!text.empty()){
      cout << text.top() << " ";
      ans += (text.top() + " ");
      text.pop();
  }

  return ans.substr(0, ans.length()-1);
}

int main(){
	string s  = "the sky is blue";
	reverseWords(s);
}
