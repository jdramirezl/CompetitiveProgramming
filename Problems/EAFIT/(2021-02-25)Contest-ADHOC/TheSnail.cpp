#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, factor, height, b, c, d; // Height, Climb, Slides, Fatigue
    int day;
    do{
        cin >> a >> b >> c >> d;
        if (a == 0) break;
        height = 0.0;
        factor = (d * b)/100.0; 
        day = 0;
        while(height >= 0){
            day++;
            height += b;
            if (height > a) {break;}
            height -= c;
            b -= factor;
            if (b <= 0) b = 0;
        }
        if (height <= 0) cout << "failure on day " << day << endl; 
        else cout << "success on day " << day << endl; 

    }while(a != 0);
}