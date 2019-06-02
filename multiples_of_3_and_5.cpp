#include <bits/stdc++.h>
using namespace std;

#define f(a) for(int i = 0; i < a; ++i)

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int sum = 0;
    f(1000) if (0 == i%3 || 0 == i%5) sum += i;
    cout << sum << "\n";

    return 0;
}
