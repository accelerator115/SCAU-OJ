#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
	int ddl, val;
};

bool cmp(const Job &a, const Job &b) {
	return a.val > b.val;
}

int main() {
	int n;
	cin >> n;
	vector<Job> jobs(n);
	int max = 0;
	for (int i = 0; i < n; ++i) {
		cin >> jobs[i].ddl;
		if (jobs[i].ddl > max)
			max = jobs[i].ddl;
	}
	for (int i = 0; i < n; ++i) {
		cin >> jobs[i].val;
	}
	sort(jobs.begin(), jobs.end(), cmp);

	vector<bool> used(max + 1, false);
	int total = 0;
	for (const auto &job : jobs) {
		if (!used[job.ddl]) {
			used[job.ddl] = true;
			total += job.val;
		}
	}
	cout << total << endl;
	return 0;
}
