#include <iostream>
#include <vector>
#include <utility>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int t = 0; t < test_cases; t++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<long long, long long>> kv(n);
        for (int i = 0; i < n; i++) {
            long long k, v;
            std::cin >> k >> v;
            kv[i] = std::make_pair(k, v);
        }

        int q;
        std::cin >> q;
        for (int i = 0; i < q; i++) {
            long long kq;
            std::cin >> kq;

            long long v = 0;
            for (int i = 0; i < n; i++) {
                if (kv[i].first == kq) {
                    v = kv[i].second;
                }
            }
            std::cout << v << '\n';
        }
    }
}
