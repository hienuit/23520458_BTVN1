#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ham so sanh khi hai phan so co chung mau, so sanh tu
bool compareFractions(pair<int, int> f1, pair<int, int> f2) {
    return (f1.first * f2.second < f2.first * f1.second);
}

int main() {
    int n, k;
    cout << "Nhap so luong phan so n: ";
    cin >> n;
    cout << "Nhap gia tri k: ";
    cin >> k;

    vector<pair<int, int>> fractions;
    for (int i = 0; i < n; i++) {
        int numerator, denominator;
        cout << "Nhap tu so cua phan so " << i + 1 << ": ";
        cin >> numerator;

        // Nhap lai phan so neu mau bang 0
        do {
            cout << "Nhap mau so cua phan so " << i + 1 << " (khac 0): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Mau so phai khac 0. Vui long nhap lai.\n";
            }
        } while (denominator == 0);

        fractions.push_back({ numerator, denominator });
    }

    // Sap xep mang theo gia tri tang dan
    sort(fractions.begin(), fractions.end(), compareFractions);

    // Kiem tra xem co ton tai phan so lon thu k hay be thu k khong
    if (k <= n) {
        cout << "Phan so be thu " << k << ": "
            << fractions[k - 1].first << "/" << fractions[k - 1].second << endl;
        cout << "Phan so lon thu " << k << ": "
            << fractions[n - k].first << "/" << fractions[n - k].second << endl;
    }

    return 0;
}
