#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int num; // Tu so
    int den; // Mau so

    // Ham nhan hai phan so
    Fraction operator*(const Fraction& other) const {
        return { num * other.num, den * other.den };
    }

    // Ham so sanh hai phan so
    bool operator==(const Fraction& other) const {
        return num * other.den == den * other.num;
    }
};

// Ham so sanh phan so de sap xep (gia tri thuc)
bool compareFraction(const Fraction& f1, const Fraction& f2) {
    return f1.num * f2.den < f2.num * f1.den;
}

// Ham tim tap hop con voi tich bang phan so dich
void findSubsetWithTargetProduct(const vector<Fraction>& fractions, Fraction target) {
    int n = fractions.size();
    vector<Fraction> bestSubset;
    bool found = false;

    // Duyet qua tat ca cac tap hop con
    for (int mask = 1; mask < (1 << n); ++mask) {
        Fraction product = { 1, 1 };
        vector<Fraction> subset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                product = product * fractions[i];
                subset.push_back(fractions[i]);
            }
        }

        // Kiem tra neu tich cua tap hop con bang phan so dich
        if (product == target) {
            if (!found || subset.size() < bestSubset.size()) {
                bestSubset = subset;
                found = true;
            }
        }
    }

    if (found) {
        // Sap xep tap hop con theo thu tu tang dan
        sort(bestSubset.begin(), bestSubset.end(), compareFraction);

        // Xuat tap hop con
        for (const auto& frac : bestSubset) {
            cout << frac.num << "/" << frac.den << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<Fraction> fractions(n);
    cout << "Nhap tung phan so a/b:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> fractions[i].num >> fractions[i].den;
    }

    Fraction target;
    cout << "Nhap phan so dich a_k / b_k: ";
    cin >> target.num >> target.den;

    findSubsetWithTargetProduct(fractions, target);

    return 0;
}
