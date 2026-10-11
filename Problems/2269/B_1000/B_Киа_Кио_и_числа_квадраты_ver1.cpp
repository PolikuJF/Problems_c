#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

std::pair<int, int> count_operations(int num) {
    int steps = 0;

    while (num != 1 && num != 4) {
        int sum = 0;
        int t = num;
        while (t > 0) {
            int d = t % 10;
            sum += d * d;
            t /= 10;
        }
        num = sum;
        ++steps;
    }

    return {num, steps};
}

int main() {
    int a;
    std::cin >> a;

    for (int i = 0; i < a; ++i) {
        int b;
        std::cin >> b;

        std::vector<std::pair<int,int>> data(b);

        for (int j = 0; j < b; ++j) {
            int x;
            std::cin >> x;
            data[j] = count_operations(x);
        }

        std::sort(data.begin(), data.end());

        long long total = 0;

        int j = 0;
        while (j < b) {
            int k = j;
            int state = data[j].first;

            if (state == 1) {
                while (k < b && data[k].first == 1) ++k;
                long long group_size = k - j;
                total += group_size * (group_size - 1) / 2;
            } else {
                while (k < b && data[k].first == 4) ++k;

                std::vector<int> norm;
                for (int t = j; t < k; ++t) {
                    int s = data[t].second;
                    while (s >= 8) s -= 8;
                    norm.push_back(s);
                }

                std::sort(norm.begin(), norm.end());

                int m = 0;
                while (m < (int)norm.size()) {
                    int p = m;
                    while (p < (int)norm.size() && norm[p] == norm[m]) ++p;
                    long long group_size = p - m;
                    total += group_size * (group_size - 1) / 2;
                    m = p;
                }
            }

            j = k;
        }

        std::cout << total << '\n';
    }
    return 0;
}