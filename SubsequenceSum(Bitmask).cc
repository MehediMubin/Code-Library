#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0)

int main ()
{
    FastIO;

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector <int> v(n);
    for (auto &i : v) cin >> i;

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {  // 1
        int sum = 0, mn = INT_MAX, mx = INT_MIN;  // 2
        for (int i = 0; i < n; i++) {             // 3
            if ((mask >> i) & 1) {                // 4
                sum += v[i];
                mn = min(v[i], mn);
                mx = max(v[i], mx);
            }
        }

        if (sum >= l && sum <= r) {
            if (abs(mn - mx) >= x) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
