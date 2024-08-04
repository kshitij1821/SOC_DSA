#include <iostream>

using namespace std;

bool checkNumber(long long num) {
    while (num >= 10) {
        int lastDigit = num % 10;
        if (lastDigit == 9) {
            return false;
        }
        num = (num / 10) - 1;
    }
    return num == 0;
}

int main() {
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; ++t) {
        long long number;
        cin >> number;

        if (checkNumber(number)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
