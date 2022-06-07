#include <iostream>
using namespace std;
long gcd(long x, long  y) {
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
long lcm(long x, long y) {
    return(x * y) / gcd(x, y);
}
long lcm_total(long x){
    long sum = 0;
    for (long i = 1; i <= x; i++) {
        sum += lcm(i, x);
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << lcm_total(x)<<endl;
    }
}

