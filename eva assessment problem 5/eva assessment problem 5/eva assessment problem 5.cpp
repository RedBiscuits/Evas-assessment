#include <iostream>
using namespace std;
long long int summingDigit(long long int dividend);

int main()
{
    long long int n, dividend, add, ans;
    int i, test, c;
    cin >> test;
    for (c = 1; c <= test; c++) {
        cin >> n;
        for (i = 1; ; i += 9) {
            dividend = n * i;
            add = summingDigit(dividend);
            if (add == n) {
                ans = dividend;
                break;
            }
        }
        cout << dividend<<endl;
        }
    return 0;
}


long long int summingDigit(long long int dividend)
{
    long long int sum = 0, rem;
    while (dividend != 0) {
        rem = dividend % 10;
        dividend = dividend / 10;
        sum = sum + rem;
    }
    return sum;
}