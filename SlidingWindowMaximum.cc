#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)

int main ()
{
    FastIO;

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector <int> v(n);
        for (auto &i : v) cin >> i;

        vector <int> ans;
        deque <int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && v[dq.back()] < v[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) ans.push_back(v[dq.front()]);
        }

        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }

    return 0;
}
