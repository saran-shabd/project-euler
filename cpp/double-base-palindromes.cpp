#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

inline string get_binary(int num) {

	string temp = "";
	for (int i = 31; i >= 0; --i) {
		int k = num >> i;
		temp.push_back((k & 1) ? '1' : '0');
	}

	int index = -1, i = 0;
	while (temp[i++] == '0') ++index;
	if (-1 != index)
		temp = temp.substr(index + 1, temp.size() - index + 1);

	return temp;
}

inline bool check_str_palindrome(string str) {
	string temp = str;
	reverse(temp.begin(), temp.end());
	return temp == str;
}

inline bool check_int_palindrome(int num) {
	int digit_count = floor(log10(num)) + 1;
	int digits[digit_count];
	int i = digit_count - 1;
	while (num > 0) {
		digits[i--] = num % 10;
		num /= 10;
	}

	int middle = digit_count / 2;
	for (int i = 0; i < middle; ++i)
		if (digits[i] != digits[digit_count - i - 1]) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll sum = 0;

	for (int i = 1; i < 1000000; ++i) {
		string binary = get_binary(i);
		if (check_int_palindrome(i) && check_str_palindrome(binary))
			sum += i;
	}

	cout << sum << "\n";

	return 0;
}
