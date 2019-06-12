#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    const int MAX_N = 1e6;
    bool primes[MAX_N+1];
    memset(primes, true, sizeof(primes));

    for (int i = 2; i*i <= MAX_N; ++i) {
        if (primes[i]) {
            for (int p = i*i; p <= MAX_N; p += i) {
                primes[p] = false;
            }
        }
    }

    int count = 0, result = 0;
    for (int i = 2; i <= MAX_N; ++i) {
        if (primes[i]) {
            ++count;
            result = i;
            if (10001 == count) break;
        }
    }

    cout << result << "\n";

    return 0;
}
