#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
   // In order for the algorithm to be efficient,
   // we need to be able to access the middle-most
   // element of the collection without iteration.
   
   // We can divide the collection in half, and delegate
   // a data structure to keep track of both halves.
   
   // For example, the left side can be a max-heap,
   // and the right side can be a min-heap.
   // This way, we can access the mid - 1 element using the max-heap,
   // and the mid + 1 element using the min-heap (both in O(1) time).
    
   vector<double> output;
    
   if (a.size() == 1) {
       output.push_back(double(a[0]));
       return output;
   }
    
   priority_queue<int, vector<int>> leftHalf;
   priority_queue<int, vector<int>, greater<int>> rightHalf;
   // Bootstrap the heaps, so no accessing empty heaps.
   int first = a[0];
   int second = a[1];
   leftHalf.push(min(first, second)); rightHalf.push(max(first, second));
   output.push_back(static_cast<double>(first));
   output.push_back((static_cast<double>(first) + static_cast<double>(second)) / 2.0);
   
   for (int i = 2; i < a.size(); i++) {
       if (leftHalf.size() < rightHalf.size()) {
            if (a[i] > rightHalf.top()) {
                leftHalf.push(rightHalf.top()); rightHalf.pop();
                rightHalf.push(a[i]);
            } else leftHalf.push(a[i]);
       } else if (leftHalf.size() > rightHalf.size()) {
           if (a[i] < leftHalf.top()) {
               rightHalf.push(leftHalf.top()); leftHalf.pop();
               leftHalf.push(a[i]);
           } else rightHalf.push(a[i]);
       } else {
           if (a[i] < leftHalf.top()) {
               leftHalf.push(a[i]);
           } else {
               rightHalf.push(a[i]);
           }
       }
       
       double median;
       if (leftHalf.size() < rightHalf.size()) median = static_cast<double>(rightHalf.top());
       else if (leftHalf.size() > rightHalf.size()) median = static_cast<double>(leftHalf.top());
       else median = (static_cast<double>(rightHalf.top()) + static_cast<double>(leftHalf.top())) / 2.0;
       
       output.push_back(median);
   }
   return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
