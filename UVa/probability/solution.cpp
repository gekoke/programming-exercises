#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void solve() {
    double a, b, S;
    cin >> a >> b >> S;

    double P;                       // Probability.
    double R = a * b;               // Rectangle (one quadrant) area.

    if      (R <= S) P = 0;         // Given area smaller than needed area, impossible.
    else if (S == 0) P = 1;         // Area (almost) 0, will always happen.
    else {
        double C = S * log(R / S);  // Curve area.
        P = (R - C - S) / R;
    }

    printf("%f\%\n", P * 100);
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) solve();
}
