#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> answers(n);

    for (int i = 0; i < n; ++i) {
        long long a, b;
        std::cin >> a >> b;

        long long k = a - b + 1;
        answers[i] =  (1LL << k) + 2* (b - 1);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << answers[i] << '\n';
    }

    return 0;
}