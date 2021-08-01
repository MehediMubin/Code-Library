#include<bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
#define pb emplace_back
#define all(v) (v).begin(),(v).end()
#define Fread freopen("in.txt","r", stdin)
#define Fwrite freopen("out.txt", "w", stdout)
#define what_is(x) cerr << #x << " is " << x << endl;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector <ll> Add (vector <ll> &v, vector <ll> &v1) {
    reverse(all(v));
    reverse(all(v1));

    ll len = min(v.size(), v1.size());
    ll carry = 0;
    vector <ll> ans;
    for (int i = 0; i < len; i++) {
        ll val = v[i] + v1[i] + carry;
        carry = val / 10;
        ans.pb(val % 10);
    }

    if (v.size() > len) {
        for (int i = len; i < v.size(); i++) {
            ll val = v[i] + carry;
            carry = val / 10;
            ans.pb(val % 10);
        }
    }

    if (v1.size() > len) {
        for (int i = len; i < v1.size(); i++) {
            ll val = v1[i] + carry;
            carry = val / 10;
            ans.pb(val % 10);
        }
    }

    while (carry) {
        ans.pb(carry % 10);
        carry /= 10;
    }

    reverse(all(ans));
    return ans;
}

int main ()
{
    FastIO;
    //Fread;
    //Fwrite;

    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        vector <ll> v, v1;
        for (int i = 0; i < a.size(); i++) v.pb(a[i] - '0');
        for (int i = 0; i < b.size(); i++) v1.pb(b[i] - '0');

        vector <ll> ans = Add(v, v1);
        for (auto i : ans) cout << i;
        cout << nl;
    }

    return 0;
}
