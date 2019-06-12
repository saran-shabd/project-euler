#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    ll n = 600851475143, g = 1;

    for (ll i = 2; i <= sqrt(n); ++i) {
        if (0 == n%i) g = i;
        while (0 == n%i) n /= i;
    }

    if (n > 2) g = n;

    cout << g << "\n";

    return 0;
}
