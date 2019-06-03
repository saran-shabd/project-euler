#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int sums = 0, squares = 0;
    for (int i = 1; i <= 100; ++i)
        sums += pow(i, 2);
    for (int i = 1; i <= 100; ++i)
        squares += i;
    squares = pow(squares, 2);

    cout << abs(sums - squares) << "\n";

    return 0;
}
