#include <iostream>
#include <vector>

std::vector<std::vector<int>> convertTo2DArray(std::vector<int>& original, int m, int n) {
    int totalElements = m * n;
    if (original.size() != totalElements) {
        return {};  // Return empty 2D array if it is impossible
    }

    std::vector<std::vector<int>> result(m, std::vector<int>(n));
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[index++];
        }
    }

    return result;
}

int main() {
    std::vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;

    std::vector<std::vector<int>> result = convertTo2DArray(original, m, n);

    // Printing the result
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
