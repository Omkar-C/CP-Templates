#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const int INF = 1e16;

class dijkstra{
    private:
        vector<long long> distance;
        vector<vector<pair<int,int>>> graph;
        vector<long long> parent;
        int n;
    public:
        dijkstra(vector<vector<pair<int,int>>> &adjList) {
            graph = adjList;
            n = graph.size();
            distance.assign(n, INF);
            parent.assign(n, -1);
        }

        void dijkstraAlgo(int source) {
            distance[source] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            pq.push({0, source});

            while(!pq.empty()) {
                int vertex = pq.top().second;
                long long dist = pq.top().first;
                pq.pop();

                if(dist != distance[vertex]) continue;

                for(auto edge: graph[vertex]) {
                    int to = edge.first;
                    int len = edge.second;

                    if(distance[vertex] + len < distance[to]) {
                        distance[to] = distance[vertex] + len;
                        parent[to] = vertex;
                        pq.push({distance[to], to});
                    }
                }
            }
        }

        vector<long long>& distances() {
            return distance;
        }

        vector<long long>& parents() {
            return parent;
        }
};
