#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#include <iostream>
using namespace std;

const int INF = 1 << 30;
typedef pair <int, char> dist_node;
typedef pair <int, int> edge;
unordered_map<char, vector<edge>> graph;
unordered_map<char, int> d;
unordered_map<char, char> p;


void dijkstra(char s){
    for (int i = 33; i <= 126; ++i){
        d[(char)i] = INF;
        p[(char)i] = '\0';
    }

    priority_queue < dist_node, vector <dist_node>, greater<>> q;
    d[s] = 0;
    q.push(dist_node(0, s));

    while (!q.empty()){
        int dist = q.top().first;
        char curr = q.top().second;
        q.pop();
        if (dist > d[curr]) continue;
        for (int i = 0; i < graph[curr].size(); ++i){
            int next = graph[curr][i].first;
            int next_weight = graph[curr][i].second;
            if (d[curr] + next_weight < d[next]){
                d[next] = d[curr] + next_weight;
                p[next] = curr;
                q.push(dist_node(d[next], next));
            }
        }
    }
}



int main() {
    string original, encrypted;
    unordered_map<char, vector<char>> findsum;
    int changes, c, total = 0;
    char a, b;
    cin >> original >> encrypted >> changes;

    for(int i = 0; i<changes; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for(int i = 0; i < original.size(); i++){
        findsum[original[i]].push_back(encrypted[i]);
    }

    for(const auto &key: findsum){
        char curr = key.first;
        dijkstra(curr);
        for(const auto &value: key.second){
            if (curr == value){
                continue;
            }
            else{
                if (d[value] == INF){
                    cout << -1;
                    return 0;
                }
                else{
                    total += d[value];
                }
            }
        }
    }

    cout << total;
    return 0;
}
