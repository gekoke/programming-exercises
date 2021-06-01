#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int i, j, k, l;
    int gp = 2 * pow(10, 9);  // Greatest product where sum is < 2000.
    int scale = pow(10, 6);

    for (i = 1; i <= 2000; i++) {
        if (pow(i, 4) > gp) break;
        for (j = i; j <= 2000 - i; j++) {
            if (i * pow(j, 3) > gp) break;
            for (k = j; j <= 2000 - i - j; k++) {
                if (i * j * pow(k, 2) > gp) break;

                // Given initial constraints, only variable we don't yet
                // know is the fourth cent value.
                // Instead of iterating, we can just solve an equation for it.

                //       10^6 * (i + j + k)
                // l = -----------------------
                //        i * j * k - 10^6

                // We can't divide, so let's just skip this iteration if any
                // of the constraints of the equation are not satisfied.

                int p = (i * j * k);
                if (p == scale) continue;  // Avoid DivZero.
                int s = (i + j + k);

                int u = scale * s;
                int d = p - scale;

                if (u % d != 0) continue;  // Division has to be non-fractional.

                int l = u / d;

                if (k > l) continue;  // Filter out already occurred combinations
                                      // (solution has to be in sorted order)

                if (s + l > 2000) continue;  // Sum constraint.
                if (p * l > gp) continue;    // Product constraint.

                // All non-solutions eliminated, therefore current iteration is a solution.
                // Format cents to EUR.CC format
                printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i / 100, i % 100, j / 100, j % 100, k / 100, k % 100, l / 100, l % 100);
            }
        }
    }
    return 0;
}