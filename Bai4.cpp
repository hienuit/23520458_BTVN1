#include <iostream>
#include <vector>

using namespace std;

// Ham ap dung Arnold's Cat Map
vector<vector<int>> arnoldsCatMap(const vector<vector<int>>& matrix, int m) {
    vector<vector<int>> transformed(m, vector<int>(m));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = (2 * i + j) % m;
            int y = (i + j) % m;
            transformed[x][y] = matrix[i][j];
        }
    }

    return transformed;
}

// Ham kiem tra xem hai ma tran co bang nhau khong
bool areMatricesEqual(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat1[i][j] != mat2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Ham tinh chu ky cua phep bien doi Arnold's Cat Map
int calculateCycle(const vector<vector<int>>& matrix, int m) {
    vector<vector<int>> transformed = matrix;
    int cycle = 0;

    do {
        transformed = arnoldsCatMap(transformed, m);
        cycle++;
    } while (!areMatricesEqual(matrix, transformed));

    return cycle;
}

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int cycle = calculateCycle(matrix, m);
    cout <<  cycle << endl;

    return 0;
}
