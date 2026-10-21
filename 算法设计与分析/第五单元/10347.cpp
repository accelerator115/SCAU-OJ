#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Job {
    int start;
    int end;
    ll val;
};

bool cmpJob(const Job &a, const Job &b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n), t(n), w(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) cin >> w[i];

    vector<Job> jobs;
    jobs.reserve(n);
    for (int i = 0; i < n; ++i) {
        Job job;
        job.start = s[i];
        job.end = s[i] + t[i] - 1;
        job.val = 1LL * t[i] * w[i];
        jobs.push_back(job);
    }

    sort(jobs.begin(), jobs.end(), cmpJob);

    vector<int> p(n, -1);
    for (int j = 0; j < n; ++j) {
        for (int i = j - 1; i >= 0; --i) {
            if (jobs[i].end < jobs[j].start) { p[j] = i; break; }
        }
    }

    vector<ll> dp(n + 1, 0);
    for (int k = 1; k <= n; ++k) {
        ll notake = dp[k - 1];
        ll take = jobs[k - 1].val + (p[k - 1] == -1 ? 0 : dp[p[k - 1] + 1]);
        dp[k] = max(notake, take);
    }

    cout << dp[n] << '\n';
    return 0;
}
