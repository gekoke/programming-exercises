#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int counts[201] = {0};
    bool even = (d % 2 == 0);
    deque<int> history;
    
    int notifications = 0;
    for (int exp : expenditure) {
        int median;

        // Get sum of median elements, not median itself
        // to avoid float imprecision later.
        if (history.size() == d) {
           int elements = 0;
           int mid = d / 2 + 1;
           int otherMid; 
           if (even) otherMid = d / 2;
            
           for (int i = 0; i < 200; i++) {
               elements += counts[i];
               if (elements >= mid) {
                   median = i;
                   break;
               }
           }
           if (even) {
               elements = 0;
               for (int i = 0; i < 200; i++) {
                   elements += counts[i];
                   if (elements >= otherMid) {
                       median += i;
                       break;
                   }
               }
           }
           if (!even) median *= 2;
           if (exp >= median) notifications++;
       }

        // Add new num to queue and counts.
        history.push_back(exp);
        counts[exp]++;

        // Shift the queue if over the limit. Decrement counts then also.
        if (history.size() > d) {
            counts[history.front()]--;
            history.pop_front();
        } 
    }
    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
