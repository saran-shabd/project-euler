#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi get_factors(int num) {
    vi result;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (0 == num%i) {
            while (0 == num%i) {
                num /= i;
                result.push_back(i);
            }
        }
    }
    if (0 != num) result.push_back(num);
    return result;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int result = 1;

    for (int i = 2; i <= 20; ++i) {
        if (0 != result % i) {
            vi factors = get_factors(i);
            for (int factor : factors) {
                result *= factor;
                if (0 == result % i) break;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
