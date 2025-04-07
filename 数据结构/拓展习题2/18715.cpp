#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> push_seq(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> push_seq[i];
    }

    stack<int> s;
    vector<int> output;
    int push_idx = 0;

    while (output.size() < n)
    {
        if (push_idx < n)
        {
            s.push(push_seq[push_idx++]);
        }

        bool popped = true;
        while (!s.empty() && popped)
        {
            popped = false;
            int top = s.top();
            bool can_pop = true;

            for (int i = push_idx; i < n; ++i)
            {
                if (push_seq[i] > top)
                {
                    can_pop = false;
                    break;
                }
            }

            if (can_pop)
            {
                output.push_back(top);
                s.pop();
                popped = true;
            }
        }
        if (push_idx >= n && !s.empty())
        {
            while (!s.empty())
            {
                output.push_back(s.top());
                s.pop();
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}