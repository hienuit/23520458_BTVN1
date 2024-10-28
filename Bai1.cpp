#include <iostream>
#include <vector>
using namespace std;

// So sanh hai phan so khi co chung tu
bool isGreater(int num1, int denom1, int num2, int denom2) {
    return (num1 * denom2 > num2 * denom1);
}

bool isSmaller(int num1, int denom1, int num2, int denom2) {
    return (num1 * denom2 < num2 * denom1);
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<pair<int, int>> fractions;
    for (int i = 0; i < n; i++) {
        int numerator, denominator;
        cout << "Nhap tu so cua phan so " << i + 1 << ": ";
        cin >> numerator;

        // Yeu cau nhap lai neu mau bang 0
        do {
            cout << "Nhap mau so cua phan so " << i + 1 << " (khac 0): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (denominator == 0);

        fractions.push_back({ numerator, denominator });
    }

    // Khoi tao phan so nho nhat va phan so lon nhat
    pair<int, int> maxFraction = fractions[0];
    pair<int, int> minFraction = fractions[0];

    for (int i = 1; i < n; i++) {
        if (isGreater(fractions[i].first, fractions[i].second, maxFraction.first, maxFraction.second)) {
            maxFraction = fractions[i];
        }
        if (isSmaller(fractions[i].first, fractions[i].second, minFraction.first, minFraction.second)) {
            minFraction = fractions[i];
        }
    }

    cout << "Phan so nho nhat: " << minFraction.first << "/" << minFraction.second << endl;
    cout << "Phan so lon nhat: " << maxFraction.first << "/" << maxFraction.second << endl;

    return 0;
}
