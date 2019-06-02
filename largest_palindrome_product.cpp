#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f(a) for(ll i = 0; i < a; ++i)
#define pb push_back

bool check_palindrome(ll num) {
    vector<ll> digits;
    while (num > 0) {
       digits.push_back(num%10);
       num /= 10; 
    }
    f(digits.size()/2 + 1)
        if (digits[i] != digits[digits.size() - i - 1])
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    ll result = -1;
    for (ll i = 999; i >= 1; --i) {
        for (ll j = i; j >= 1; --j) {
            ll temp = i*j;
            if (check_palindrome(temp) && temp > result) {
                result = i*j;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
