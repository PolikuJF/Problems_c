https://codeforces.com/problemset/problem/2225/C

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void input(T *arr, int len) {
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
}

template<typename T>
void print(T *arr, int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i];
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        vector<char> arr(a), brr(a);
        input(arr.data(), a);
        input(brr.data(), a);
        int count = 0;
        for (int i = 0; i < a; ++i) {
            if (i == (a - 1)) {
                if (arr[i] != brr[i]) {
                    count++;
                }
                continue;
            }
            if (arr[i] == brr[i]) {
                continue;
            }
            if (arr[i] == arr[i + 1]) {
                if (brr[i] == brr[i + 1]) {
                    i++;
                    continue;
                } else {
                    i++;
                    count++;
                    continue;
                }
            }
            if (brr[i] == brr[i + 1]) {
                if (arr[i] == arr[i + 1]) {
                    i++;
                    continue;
                } else {
                    i++;
                    count++;
                    continue;
                }
            }
            count++;
        }
        std::cout << count << '\n';
    }
    return 0;
}

https://codeforces.com/problemset/problem/2276/C
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> P(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            P[i] = P[i-1] + x;
        }
        vector<int> cnt(k, 0);

        long long ans = 0;
        int left = 0;

        for (int j = 1; j <= n; j++) {
            while (left <= j - k - 1) {
                cnt[P[left] % k]++;
                left++;
            }
            ans += cnt[P[j] % k];
        }

        cout << ans << "\n";
    }
    return 0;
}


https://codeforces.com/problemset/problem/2241/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<long long> arr(n);
        std::vector<long long> brr(n);
        bool flag = true;
        long long count = 0;
        long long index = 0;
        for (int i = 0; i< n; i++) {
            std::cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> brr[i];
        }
        for (int i = 0; i< n; i++) {
            if (arr[i] < brr[i] ) {
                count+= brr[i] - arr[i];
            } else {
                count -= arr[i] - brr[i];
                if (count < 0) {
                    flag = false;
                }
            }
        }
        if (flag) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
    return 0;
}

https://codeforces.com/problemset/problem/2258/B1

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> count(2 * m + 2, 0);

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            count[x]++;
        }

        std::vector<int> count2(m + 3, 0);
        for (int i = m; i >= 1; --i) {
            count2[i] = count2[i + 1] + count[i];
        }

        int max_ans = 0;

        for (int i = 1; i <= m; ++i) {
            int current_ans = count2[i] + count[2 * i];
            if (current_ans > max_ans) {
                max_ans = current_ans;
            }
        }

        std::cout << max_ans << "\n";
    }

    return 0;
}


https://codeforces.com/problemset/problem/2259/C

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int x;
        std::cin >> x;
        int count = 0;
        std::vector<int> arr(x);
        int minn = -1;
        int maxx = -1;
        for (int i = 0; i < x; ++i) {
            int a;
            std::cin >> a;
            if (count == 0) {
                if (a == 1 or a == -1) {
                    a = 1;
                    count++;
                    minn = i;
                }
            }
            arr[i] = a;
        }

        if (minn != -1) {
            for (int i = x -1; i > minn; --i) {
                if (arr[i] == 1 or arr[i] == -1) {
                    maxx = i;
                    arr[i] = 1;
                    break;
                }
            }
        }
        if (maxx != minn) {
            for (int i = minn; i < maxx; i++) {
                if (arr[i] == -1) {
                    arr[i] = 0;
                }
            }
        }
        for (int i = 0; i < x; ++i) {
           std::cout << arr[i] << " "; 
        }
        std::cout << "\n";
    }

    return 0;
}


https://codeforces.com/problemset/problem/2260/B

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        long long x, y, k;
        std::cin >> x >> y >> k;
        long long count = 0;
        while (x *2 <= y and k > 0) {
            count += y % x;
            y++;
            x++;
            k--;
        }
        count +=(y-x)*(k);
        std::cout << count << "\n";
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

long long sum_mod(long long d, long long L, long long R) {
    if (L > R) return 0;
    long long total = 0;
    long long q = d / L;
    while (L <= R) {
        long long last_a = d / q;
        long long cur_R = min(R, last_a);
        long long count = cur_R - L + 1;
        
        long long sum_a = (L + cur_R) * count / 2;
        total += count * d - q * sum_a;
        
        L = cur_R + 1;
        if (L > R) break;
        q = d / L;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        
        long long d = y - x;
        long long end_a = x + k - 1;
        
        if (d == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        if (x > d) {
            cout << d * k << "\n";
            continue;
        }
        
        long long part1_end = min(end_a, d);
        long long ans = sum_mod(d, x, part1_end);
        
        if (end_a > d) {
            ans += d * (end_a - d);
        }
        
        cout << ans << "\n";
    }
    return 0;
}


https://codeforces.com/problemset/problem/2261/A

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int count1 = 0;
        int left = -1, right = -1;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1++;
                if (left == -1) left = i;
                right = i;
            }
        }
        
        if (count1 == 1) {
            cout << 0 << "\n";
        } else if (count1 == 2) {
            cout << 1 << "\n";
        } else {
            cout << right - left << "\n";
        }
    }
    
    return 0;
}


https://codeforces.com/problemset/problem/2261/B


#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int mx = -1, mn = 1000000001;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > mx) { 
                mx = x;
            }
            if (x < mn) {
                mn = x;
            }
        }
        
        int diff = mx ^ mn;
        int mask = 1;
        
        while (mask <= diff) {
            mask <<= 1;
        }
        
        cout << (mx | (mask - 1)) << "\n";
    }
    
    return 0;
}


https://codeforces.com/problemset/problem/2261/C


#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int odd_count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != 0) {
                odd_count++;
            }
        }
        
        int even_count = n - odd_count;
        
        if ((even_count == 1 && odd_count == 1) || (even_count == 0 && odd_count == 3)) {
            cout << "Larpity\n";
        } else {
            cout << "Moggity\n";
        }
    }
    
    return 0;
}



https://codeforces.com/problemset/problem/2261/D1


#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
        }
        
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        
        int k = (n + 1) / 2;
        cout << k << "\n";
        
        for (int i = 1; i <= k; i++) {
            cout << i << " " << i + k - 1 << "\n";
        }
    }
    
    return 0;
}


https://codeforces.com/problemset/problem/2268/A


#include <iostream>
#include <vector>
using namespace std;


int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long n;
        long long k;
        long long count = 0;
        cin >> n >> k;
        std::vector<int> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        while(k <= n){
            if (arr[k - 1] > arr[n-k]) {
                count += arr[k - 1];
                arr[k - 1] = 0;
            } else {
                count += arr[n-k];
                arr[n - k] = 0;
            }
            k++;
        }
        std::cout << count << '\n';
    }
    
    return 0;
}


https://codeforces.com/problemset/problem/2275/A


#include <iostream>

int main() {
    long long a;
    std::cin >> a;

    while (a--) {
        long long b, c, d;
        std::cin >> b >> c >> d;
        std::cout << b << " " << c - d << '\n';
    }
    return 0;
}


https://codeforces.com/problemset/problem/2275/B


#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main() {
    long long a;
    std::cin >> a;

    while (a--) {
        long long b;
        std::cin >> b;
        std::string s;
        std::cin >> s;
        
        std::vector<int> arr(b, 0);
        std::stack<long long> st;
        
        for (long long i = 0; i < b; i++) {
            if (s[i] == '1') {
                st.push(i);
            } else if (s[i] == '2') {
                if (!st.empty()) {
                    long long j = st.top();
                    st.pop();
                    arr[j] = 1;
                } else {
                    arr[i] = 1;
                }
            } else if (s[i] == '3') {
                arr[i] = 1;
            }
        }
        long long zeroCount = 0;
        for (long long i = 0; i < b; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            }
        }
        
        std::cout << zeroCount << '\n';     
        
        bool first = true;
        for (long long i = 0; i < b; i++) {
            if (arr[i] == 0) {
                if (!first) {
                    std::cout << ' ';
                }
                std::cout << i + 1;
                first = false;
            }
        }
        std::cout << '\n';
    }
    return 0;
}


https://codeforces.com/problemset/problem/2275/C


#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a;
    std::cin >> a;

    while (a--) {
        long long b;
        std::cin >> b;

        std::vector<long long> arr(b);
        for (long long i = 0; i < b; i++) {
            std::cin >> arr[i];
        }

        long long m = b - 4;
        if (m <= 0) {
            std::cout << 0 << '\n';
            continue;
        }

        std::vector<long long> sums(m);
        std::unordered_map<long long, long long> count;

        for (long long i = 0; i < m; i++) {
            sums[i] = arr[i] + arr[i + 2] - arr[i + 4];
            count[sums[i]]++;
        }

        long long total = 0;

        for (long long i = 0; i < m; i++) {
            long long c = count[sums[i]];

            c -= 1;

            if (i + 2 < m && sums[i + 2] == sums[i]) c -= 1;
            if (i + 4 < m && sums[i + 4] == sums[i]) c -= 1;

            total += c;

            count[sums[i]]--;
        }

        std::cout << total << '\n';
    }
    return 0;
}


https://codeforces.com/problemset/problem/2275/D


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;

        std::vector<long long> a(n), b(n), c(n);
        long long minimum_sum = LLONG_MAX;

        for (long long i = 0; i < n; i++) {
            std::cin >> a[i] >> b[i] >> c[i];
            minimum_sum = std::min(minimum_sum, a[i] + b[i] + c[i]);
        }

        const long long INF = LLONG_MAX / 4;

        long long low = minimum_sum;
        long long high = minimum_sum + k + 1;
        while (low + 1 < high) {
            long long middle = low + (high - low) / 2;
            long long total_cost = 0;
            bool ok = true;

            for (long long i = 0; i < n; i++) {
                long long sum_abc = a[i] + b[i] + c[i];
                long long cost;

                if (sum_abc >= middle) {
                    cost = 0;
                } else if (a[i] == b[i] && b[i] == c[i]) {
                    cost = INF;
                } else if (a[i] > b[i] || a[i] > c[i] || b[i] > c[i]) {
                    cost = middle - sum_abc;
                } else {
                    long long preparation = std::min(b[i] - a[i] + 1, c[i] - b[i] + 1);
                    cost = (middle - sum_abc) + 2 * preparation;
                }

                if (cost >= INF) {
                    ok = false;
                    break;
                }
                total_cost += cost;
                if (total_cost > k) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                low = middle;
            } else {
                high = middle;
            }
        }

        std::cout << low << '\n';
    }
    return 0;
}


https://codeforces.com/problemset/problem/2275/E


#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];

        std::vector<int> w(n + 1), p(n + 1), q(n + 1);
        for (int i = 1; i <= n; ++i) {
            w[i] = (a[i - 1] == b[i - 1]) ? 2 : 1;
        }
        for (int i = 1; i < n; ++i) {
            p[i] = (a[i - 1] == b[i]) ? 2 : 1; // a_i - b_{i+1}
            q[i] = (b[i - 1] == a[i]) ? 2 : 1; // b_i - a_{i+1}
        }

        const long long NEG = -1e18;

        std::vector<std::vector<std::vector<long long>>> dp(
            4, std::vector<std::vector<long long>>(
                   2, std::vector<long long>(3, NEG)));

        dp[0][0][0] = 0;
        long long ans = NEG;

        for (int i = 1; i <= n; ++i) {
            std::vector<std::vector<std::vector<long long>>> ndp(
                4, std::vector<std::vector<long long>>(
                       2, std::vector<long long>(3, NEG)));

            for (int L = 0; L < 4; ++L) {
                for (int conn = 0; conn < 2; ++conn) {
                    for (int ep = 0; ep <= 2; ++ep) {
                        long long val = dp[L][conn][ep];
                        if (val == NEG) continue;

                        for (int V = 0; V <= 1; ++V) {
                            for (int R = 0; R < 4; ++R) {
                                if (i == n && R != 0) continue;
                                if (i < n && R == 0) continue;

                                int degA_left = (L >> 1) & 1;
                                int degB_left = (L >> 0) & 1;
                                int dA = degA_left + V + ((R >> 0) & 1);
                                int dB = degB_left + V + ((R >> 1) & 1);

                                if (dA < 1 || dA > 2 || dB < 1 || dB > 2)
                                    continue;
                                if (i == 1 && dA != 1) continue;

                                int new_ep = ep + (dA == 1) + (dB == 1);
                                if (new_ep > 2) continue;

                                long long add = 0;
                                if (V == 1) add += w[i];
                                if (i < n) {
                                    if (R & 1) add += p[i];
                                    if (R & 2) add += q[i];
                                }

                                if (i < n) {
                                    int new_conn = 0;
                                    int connV = conn | V;
                                    if (R == 3) {
                                        new_conn = connV;
                                    } else if (R == 1 || R == 2) {
                                        new_conn = 0;
                                    } else {
                                        continue;
                                    }
                                    long long new_val = val + add;
                                    if (new_val > ndp[R][new_conn][new_ep]) {
                                        ndp[R][new_conn][new_ep] = new_val;
                                    }
                                } else {
                                    int connV = conn | V;
                                    if (connV != 1) continue;
                                    if (new_ep != 2) continue;
                                    ans = std::max(ans, val + add);
                                }
                            }
                        }
                    }
                }
            }
            if (i < n) dp = std::move(ndp);
        }

        std::cout << ans << '\n';
    }
    return 0;
}



https://codeforces.com/problemset/problem/2276/A


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        if (a > b) {
            count = a - b;
        } else {
            count = -1;
        }
        if (count != -1 and b < count) {
            count = b;
        }
        std::cout << count << '\n';
    }
    return 0;
}


https://codeforces.com/problemset/problem/2276/B


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int count1 = 1;
        int count2 = 0;  
        int count3 = 0;
        for(int i = 1; i < s.size() - 1; ++i){
            if(s[i-1] == s[i] and s[i] == s[i+1]) {
                count2 = 1;
            }
            if(s[i-1] != s[i] and s[i] != s[i+1]) {
                count3 = 1;
            }
        }
        
        std::cout << count1 +count2 +count3 << '\n';
    }
    return 0;
}