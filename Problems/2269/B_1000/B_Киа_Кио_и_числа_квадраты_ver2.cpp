#include <iostream>
#include <unordered_map>

std::pair<int, int> count_operations(int num) {
    int steps = 0;
    while (num != 1 && num != 4) {
        int sum = 0;
        while (num > 0) {
            int d = num % 10;
            sum += d * d;
            num /= 10;
        }
        num = sum;
        ++steps;
    }
    return {num, steps};
}

int main() {
    int a;
    std::cin >> a;

    while (a--) {
        int b;
        std::cin >> b;

        std::unordered_map<int, long long> freq;

        for (int j = 0; j < b; ++j) {
            int x;
            std::cin >> x;
            auto [state, steps] = count_operations(x);
            int key = (state == 1) ? -1 : (steps % 8);
            ++freq[key];
        }

        long long total = 0;
        for (auto& [key, cnt] : freq) {
            total += cnt * (cnt - 1) / 2;
        }

        std::cout << total << '\n';
    }
    return 0;
}