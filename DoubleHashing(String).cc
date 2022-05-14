#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5 + 9;
const int p1 = 29, p2 = 31, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int pw1[N], pw2[N];
void precal () {
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = (1LL * pw1[i - 1] * p1) % mod1;
        pw2[i] = (1LL * pw2[i - 1] * p2) % mod2;
    }
}

pair <int, int> getHash (string str) {
    int hash1 = 0, hash2 = 0;
    for (int i = 0; i < str.size(); i++) {
        hash1 += (1LL * pw1[i] * (str[i] - 'a' + 1)) % mod1;
        hash1 %= mod1;

        hash2 += (1LL * pw2[i] * (str[i] - 'a' + 1)) % mod2;
        hash2 %= mod2;
    }

    return {hash1, hash2};
}

int32_t main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    precal();
    string a, b;
    cin >> a >> b;

    cout << (getHash(a) == getHash(b)) << endl;         

    return 0;
}
