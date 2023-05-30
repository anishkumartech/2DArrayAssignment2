#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;

    for (int num : nums) {
        int index = std::abs(num) - 1;
        if (nums[index] < 0) {
            result.push_back(index + 1);
        } else {
            nums[index] *= -1;
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> duplicates = findDuplicates(nums);

    // Printing the duplicates
    std::cout << "[";
    for (int i = 0; i < duplicates.size(); i++) {
        std::cout << duplicates[i];
        if (i < duplicates.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}

