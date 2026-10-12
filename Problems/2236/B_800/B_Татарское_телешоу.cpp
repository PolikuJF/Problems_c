#include <iostream>
#include <string>
using namespace std;

int input() {
    int t;
    std::cin >> t;
    return t;
}
void print(string s) {
    std::cout << s << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = input();
    while(t--) {
        int a, b;
        std::cin >> a >> b;
        string s;
        std::cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size() - b; i++) {
            if (s[i] != '0') {
                s[i] = '0';
                if (s[i + b] != '0' ) {
                    s[i + b] = '0';
                } else {
                    s[i + b] = '1';
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                sum++;
                break;
            }
        }
        if (sum != 0) {
            print("NO");
        } else {
            print("YES");
        }
    }    
    return 0;
}