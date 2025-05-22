#include <iostream>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        graph[a].push_back({b, x});
        graph[b].push_back({a, x});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const pair<int, int>& edge : graph[u])
        {
            int v = edge.first;
            int cost = edge.second;
            if (dist[v] > dist[u] + cost)
            {
            dist[v] = dist[u] + cost;
            pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[n] << endl;
    }

    return 0;
}