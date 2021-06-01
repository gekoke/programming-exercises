#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestPermutation function below.
vector<int> largestPermutation(int k, vector<int> arr) {
    int n = arr.size();
    
    // If we can swap more than the length of the array,
    // return array sorted, but in reverse. (k can be larger than n).
    if (k >= n) {
        auto copy = arr;
        sort(copy.rbegin(), copy.rend());
        return copy;
    }
    
    // Save positions of each specific number.
    int positions[n + 1];
    for (int i = 0; i < n; i++) {
        positions[arr[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        if (k == 0) break;
        if (arr[i] == n - i) continue;

        int target = positions[n - i];
        
        // Swap positions in position array.
        positions[arr[i]] = positions[n - i];
        positions[n - i] = i;
        
        // Swap in actual array.
        swap(arr[target], arr[i]);
        
        k--;
    }
    
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = largestPermutation(k, arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

