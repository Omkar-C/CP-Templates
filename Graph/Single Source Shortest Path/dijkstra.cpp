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

class Dijkstra{
    private:
        vector<ll> distance;
        vector<vector<pair<ll,ll>>> graph;
        vector<long long> parent;
        int n;
        int sourceVertex;
        ll INF = 1e16;

        void init(vector<vector<pair<ll,ll>>> &adjList) {
            graph = adjList;
            n = graph.size();
            distance.assign(n, INF);
            parent.assign(n, -1);
        }

    public:
        Dijkstra(vector<vector<pair<ll,ll>>> &adjList) {
            init(adjList);
        }

        Dijkstra(vector<vector<pair<ll,ll>>> &adjList, ll inf) {
            INF = inf;
            init(adjList);
        }

        void dijkstraAlgo(int source) {
            sourceVertex = source;
            distance[source] = 0ll;
            priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
            pq.push({0ll, source});

            while(!pq.empty()) {
                auto [currDist, vertex] = pq.top();
                pq.pop();

                if(currDist > distance[vertex]) continue;

                for(auto edge: graph[vertex]) {
                    ll to = edge.first;
                    ll len = edge.second;

                    if(distance[vertex] + len < distance[to]) {
                        distance[to] = distance[vertex] + len;
                        parent[to] = vertex;
                        pq.push({distance[to], to});
                    }
                }
            }
        }

        bool hasPath(int v) {
            return getDistanceToV(v) != INF;
        }

        vector<ll> distances() {
            return distance;
        }

        vector<ll> parents() {
            return parent;
        }

        ll getDistanceToV(int x) {
            return distance[x];
        }

        vector<long long> generatePathToV(int v) {
            vector<long long> path;
            if(getDistanceToV(v) == INF) {
                return path;
            }

            while(v != sourceVertex) {
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(sourceVertex);
            reverse(all(path));
            return path;
        }
};