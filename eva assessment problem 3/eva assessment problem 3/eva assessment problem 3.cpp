#include <iostream>
using namespace std;

int main() {

    string s, p;
    cin >> s >> p;

    int s1 = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '*') {

            if (i == p.size() - 1) {
                cout << "True";
                return 0;
            }
            else {

                if (p[i + 1] == '*' || p[i + 1] == '?') {
                    continue;
                }

                while (p[i + 1] != s[s1]) {
                    s1++;
                }
                i++;
                s1++;

            }

        }
        else if (p[i] == '?' || p[i] == s[s1]) {
            s1++;
        }
        else {
            cout << "False";
            return 0;
        }
    }



    if (s1 >= s.size()) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}
