#include <bits/stdc++.h>
using namespace std;

#define f(a) for(int i = 0; i < a; ++i)
#define pb push_back

struct bignum {
 
public:

    bignum() : num("0") {}

    explicit bignum(string number) {
        reverse(number.begin(), number.end());
        num = number;
    }

    void set_num(string num) {
        reverse(num.begin(), num.end());
        this->num = num;
    }
  
    string to_string() {
        string temp = num;
        reverse(temp.begin(), temp.end());;
        return temp;
    }
    
    // does not work with pointer-type objects of 'bignum'
    friend ostream& operator << (ostream &os, bignum const& num);
  
    bignum operator + (bignum const& other) {
        string result = "";
        string num1 = num, num2 = other.num;
      
        if (num1.size() > num2.size())
            swap(num1, num2);
    
        int carry = 0;
        for (int i = 0; i < num1.size(); ++i) {
            int temp_sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            result.pb(temp_sum % 10 + '0');
            carry = temp_sum / 10;
        }
        
        for (int i = num1.size(); i < num2.size(); ++i) {
            int temp_sum = (num2[i] - '0') + carry;
            result.pb(temp_sum % 10 + '0');
            carry = temp_sum / 10;
        }
        
        if (0 != carry)
            result.pb(carry + '0');
      
        reverse(result.begin(), result.end());
      
        return bignum(result);
    }

private:
    string num;
};

ostream& operator << (ostream &os, bignum const& num) {
    f(num.num.size()) os << num.num[num.num.size() - 1 - i];
    return os;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    const int SIZE = 100;
    bignum nums[SIZE];
    f(SIZE) {
        string temp; cin >> temp;
        nums[i].set_num(temp);
    }

    bignum sum = bignum("0");
    f(SIZE) sum = sum + nums[i];
    
    cout << "sum = " << sum << "\n";

    return 0;
}
