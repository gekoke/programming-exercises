#include <bits/stdc++.h>

using namespace std;

int substrings(string n) {
    const int MOD = pow(10, 9) + 7;
    int len = n.size();
    long long out = 0LL;

    vector<long> weight(len), add(len);
    weight[0] = 1, add[0] = 1;

    for (int i = 1; i < len; i++) {
        weight[i] = (10 * weight[i - 1]) % MOD;
        add[i] = (add[i - 1] + weight[i]) % MOD;
    }
    
    for (int i = 0; i < len; i++) {
        int val = n[i] - '0';  // Convert char value to corresponding int.
        out += (val * add[len - i - 1] * (i + 1)) % MOD;
        out %= MOD;
    }
    
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

