#include <iostream>
using namespace std;

int findSquareCorner(int arr[], int lowerBound, int arrLength) {
    // Since the row is sorted (non-descending), we can implement
    // a binary search-like algorithm.


    // Instead of finding the given element, this search
    // finds the smallest value greater than or equal to the given lower bound.
    
    // Handle some cases where we know the solution immediately.
    if (arr[0] >= lowerBound) return 0;
    if (arr[arrLength - 1] < lowerBound) return -1;

    // Begin adapted binary search. This is like a normal binary search,
    // except the break condition is slightly modified.
    // This is effectively equivalent to the "lower_bound" function in the C++ std library.
    int low = 0;
    int high = arrLength - 1;

    while (low <= high) {
        // Examine the middle element of the search space.
        int pivot = low + (high - low) / 2;
        
        // If we found the number, return it.
        if (arr[pivot] >= lowerBound && arr[pivot - 1] < lowerBound) return pivot;

        // Otherwise, continue searching the appropriate half of the array.
        if (arr[pivot] < lowerBound) low = pivot + 1; 
        else high = pivot - 1;
    }

    // Not found.
    return -1;
}

int main() {

    // While there exists valid input.
    while (true) {
        int n; cin >> n; 
        int m; cin >> m;
        if (n == 0 && m == 0) break;

        // Get area as 2D array.
        int area[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> area[i][j];
            }
        }

        // Respond to queries.
        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            int lower; cin >> lower;
            int upper; cin >> upper;
            int maxSide = 0; 

            // For each row in area, find smallest number
            // that is greater or equal to the lower bound.
            for (int row = 0; row < n; row++) {
                int startIndex = findSquareCorner(area[row], lower, m);
                if (startIndex == -1) continue;

                // Since the values are non-decreasing when moving
                // towards the bottom-right, and we're looking for a square,
                // we can examine candidate squares by checking whether integers
                // along the diagonal remain within bounds.
                int rowMaxSide = maxSide;
                int y = row + rowMaxSide; // Don't need to check squares smaller than the ones we've already seen.
                int x = startIndex + rowMaxSide;

                while (y < n && x < m && area[y][x] <= upper) {
                    rowMaxSide++;  
                    y++;
                    x++;
                }

                // Update largest square seen so far.
                if (rowMaxSide > maxSide) {
                    maxSide = rowMaxSide;
                }
            }
            cout << maxSide << endl;
        }
        cout << "-" << endl;
    }
}
