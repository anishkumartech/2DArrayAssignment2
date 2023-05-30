#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(std::vector<int>& changed) {
    std::vector<int> original;
    std::unordered_map<int, int> freqMap;

    // Build frequency map
    for (int num : changed) {
        freqMap[num]++;
    }

    for (int num : changed) {
        if (freqMap[num] == 0) {
            continue; // Skip if the element is already used
        }

        int half = num / 2;
        if (num % 2 == 0 && freqMap[half] > 0) {
            original.push_back(half);
            freqMap[half]--;
        } else {
            return {}; // Empty array if changed is not a doubled array
        }
    }

    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};
    std::vector<int> original = findOriginalArray(changed);

    // Printing the original array
    std::cout << "[";
    for (int i = 0; i < original.size(); i++) {
        std::cout << original[i];
        if (i < original.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
