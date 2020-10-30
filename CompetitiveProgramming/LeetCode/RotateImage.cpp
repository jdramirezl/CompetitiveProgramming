#include <iostream>
#include <bits/stdc++.h>
#define D(x) cout << #x << " = " << x << endl;

using namespace std;


//Better: transpose and reverse
class Solution {
public:
    void print(const vector<vector<int>>& xd){
        for(auto &a : xd){
            for(auto &b: a){
                cout << setw(4) << b << " ";
            }
            cout << endl;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int limit = matrix.size(), ini = 0, layers, t1 = matrix[0][0], t2 = matrix[limit-1][limit-1], a, b, minus = limit-2; //MINUS SIZE-1  LIMIT SIZE
        int rounds = limit - 1, end=0, var = 0, aa = rounds, bb = var;


        cout << "first" << endl;
        print(matrix);

        if(limit%2==0) layers = limit/2;
        else layers = (limit-1)/2;

        for(int i = 0; i<layers; ++i){
            end += (rounds-var);
            rounds--;
            var++;
        }

        D(end)
        D(layers)

        for(int i = 0; i<end; ++i){
            cout << (i+1) << endl;
            D(ini)
            D(limit)
            //Tops
            for(int j = ini; j<limit-1; ++j){
                //Top
                a = matrix[ini][j+1];
                matrix[ini][j+1] = t1;
                t1 = a;
                //Bot
                b = matrix[(limit-1)][(limit-2)-j+ini];
                matrix[(limit-1)][(limit-2)-j+ini] = t2;
                t2 = b;
            }

            for(int j = ini; j<limit-1; ++j){
                //Top
                a = matrix[j+1][(limit-1)];
                matrix[j+1][(limit-1)] = t1;
                t1 = a;
                //Bot
                b = matrix[(limit-2)-j+ini][ini];
                matrix[(limit-2)-j+ini][ini] = t2;
                t2 = b;
            }

            D(minus)
            D(aa)
            D(bb)
            if(i == minus){
                ini++;
                limit--;
                aa--;
                bb++;
                D((aa-bb))
                minus += ((aa-bb));
            }


            t1 = matrix[ini][ini];
            t2 = matrix[limit-1][limit-1];

            print(matrix);

        }

        cout << "second" << endl;
        print(matrix);
    }
};

int main(){
    vector<vector<int>> mat = {
            {1,2,3},{4,5,6},{7,8,9}
    };

    Solution a;
    a.rotate(mat);
}
