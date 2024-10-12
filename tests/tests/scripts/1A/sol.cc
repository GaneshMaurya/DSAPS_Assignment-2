#include <iostream>
#include <map>

int main() {
    int test_cases;
    std::cin >> test_cases;
    for (int t = 0; t < test_cases; t++) {
        int n;
        std::cin >> n;
        std::map<long long, long long> map;
        for (int i = 0; i < n; i++) {
            long long k, v;
            std::cin >> k >> v;
            map.insert_or_assign(k, v);
        }

        int q;
        std::cin >> q;
        for (int i = 0; i < q; i++) {
            long long kq;
            std::cin >> kq;
            std::cout << map[kq] << '\n';
        }
    }
}
