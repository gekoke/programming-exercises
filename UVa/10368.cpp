#include <iostream>

using namespace std;

int main() {

    int a;
    int b;
    bool first_wins;

    while (true) {
        cin >> a; if (a == 0) break;
        cin >> b;

        first_wins = true;

        while (true) {
            if (a < b) swap(a, b);  // Always keep min number in same var.

            if ((a % b) == 0 || (a / b) > 1) {
                if (first_wins) cout << "Stan wins" << endl;
                else cout << "Ollie wins" << endl;
                break;
            }

            first_wins = !first_wins;
            a %= b;
        }
    }
}
