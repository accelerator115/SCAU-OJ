#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 21;
vector<int> adj[MAXN];
int inDegree[MAXN];
int n, m;

void topologicalSort()
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.top();
        q.pop();
        cout << curr << " ";
        for (int next : adj[curr])
        {
            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }

    topologicalSort();
    return 0;
}
