#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
#define pb emplace_back
#define all(v) (v).begin(),(v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAX = 500;

int main ()
{
    FastIO;

    string a, b;
    while (cin >> a) {
        cin >> b;

        reverse(all(a));
        reverse(all(b));
        vector <int> v(MAX, 0);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                v[i + j] += (a[i] - '0') * (b[j] - '0');
            }
        }

        for (int i = 0; i + 1 < v.size(); i++) {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }

        int i = v.size() - 1;
        while (i > 0 && v[i] == 0) i--;
        for (; i >= 0; i--) cout << v[i];
        cout << nl;
    }

    return 0;
}
