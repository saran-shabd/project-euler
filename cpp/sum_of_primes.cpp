#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int SIZE = 2000000;
    vector<bool> primes(SIZE, true);

    for (int i = 2; i < i*i; ++i)
        if (primes[i])
            for (int j = i*i; j < SIZE; j += i)
                primes[j] = false;

    ll sum = 0;
    for (int i = 2; i < SIZE; ++i)
        if (primes[i]) sum += i;
    
    cout << sum << "\n";

    return 0;
}
