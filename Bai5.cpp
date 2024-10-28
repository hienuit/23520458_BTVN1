#include <iostream>
#include <vector>
#include <algorithm>

struct Rectangle {
    int x, y, w, h;
};

// So sánh thứ tự từ trái sang phải và từ trên xuống dưới
bool compare(const Rectangle& a, const Rectangle& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int m, n;
    std::cin >> m >> n;

    // Khởi tạo ma trận
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    std::vector<Rectangle> rectangles;

    // Duyệt qua các phần tử của ma trận
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                int width = 0, height = 0;

                // Xác định chiều rộng
                while (j + width < n && matrix[i][j + width] == 1)
                    width++;

                // Xác định chiều cao
                bool valid = true;
                while (i + height < m && valid) {
                    for (int k = 0; k < width; ++k) {
                        if (matrix[i + height][j + k] == 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) height++;
                }

                // Đảm bảo kích thước tối thiểu là 2x2
                if (width >= 2 && height >= 2) {
                    rectangles.push_back({ i, j, width, height });

                    // Đánh dấu các phần tử đã duyệt qua
                    for (int x = i; x < i + height; ++x)
                        for (int y = j; y < j + width; ++y)
                            matrix[x][y] = 0;
                }
            }
        }
    }

    // Sắp xếp các hình chữ nhật
    std::sort(rectangles.begin(), rectangles.end(), compare);

    // Xuất kết quả
    for (const auto& rect : rectangles)
        std::cout << "[" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << "]\n";

    return 0;
}
