#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int curr = 1, next = 2, sum = 0;
    while (curr < 4000000) {
        if (0 == curr%2) sum += curr;
        int temp = next;
        next += curr;
        curr = temp;
    }

    cout << sum << "\n";

    return 0;
}
