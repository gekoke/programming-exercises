#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> pass1(n);
    int prev;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pass1[i] = 1;
            prev = pass1[i];
            continue;
        }
        if (arr[i - 1] < arr[i]) pass1[i] = prev + 1;
        else pass1[i] = 1;
        prev = pass1[i];
    }
    
    vector<int> pass2(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            pass2[i] = 1;
            prev = pass2[i];
            continue;
        }
        if (arr[i + 1] < arr[i]) pass2[i] = prev + 1;
        else pass2[i] = 1;
        prev = pass2[i];
    }
    
    long total = 0;
    for (int i = 0; i < n; i++) total += max(pass1[i], pass2[i]);
    
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

