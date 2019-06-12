#include <bits/stdc++.h>
using namespace std;

#define f(a) for (int i = 0; i < a; ++i)
#define f2(a, b) for (int i = a; i < b; ++i)

typedef unsigned long long ll;

const int SIZE = 20, GROUP_SIZE = 4;
int arr[SIZE][SIZE];
ll result;

inline void solution() {
    
    // horizontal
    f(SIZE - GROUP_SIZE + 1) {
        ll temp_result = 1;
        for (int j = i; j < i + GROUP_SIZE; ++j)
            temp_result *= arr[i][j];
        result = max(result, temp_result);
    }

    // vertical
    f(SIZE - GROUP_SIZE + 1) {
        ll temp_result = 1;
        for (int j = i; j < i + GROUP_SIZE; ++j)
            temp_result *= arr[j][i];
        result = max(result, temp_result);
    }

    // down-right diagonal
    f(SIZE - GROUP_SIZE + 1) {
        for (int j = 0; j < SIZE - GROUP_SIZE + 1; ++j) {
            ll temp_result = 1;
            for (int k = 0; k < GROUP_SIZE; ++k)
                temp_result *= arr[i+k][j+k];
            result = max(result, temp_result);
        }
    }

    // down-left diagonal
    f(SIZE - GROUP_SIZE + 1) {
        for (int j = GROUP_SIZE - 1; j < SIZE; ++j) {
            ll temp_result = 1;
            for (int k = 0; k < GROUP_SIZE; ++k)
                temp_result *= arr[i+k][j-k];
            result = max(result, temp_result);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    f(SIZE) for (int j = 0; j < SIZE; ++j)
        cin >> arr[i][j];
    
    solution();

    cout << result << "\n";

    return 0;
}
