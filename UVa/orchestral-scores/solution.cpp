#include <iostream>
#include <functional>
#include <cstdlib>
#include <queue>

using namespace std;

int getMaxPeoplePerScore(int n, int p) {
    return (n % p == 0) ? (n / p) : ((n / p) + 1);
}

// Custom sort for our heap. Makes sure
// that the instruments which we can reduce
// more by adding a single score are closer
// to the root of the tree.
struct Compare {
    bool operator() (array<int, 2> arrA, array<int, 2> arrB) {
        // Heap contains elements arr[2], where arr[0] is people of a
        // particular type of instrument, arr[1] is the amount of scores they have.
        return (
            getMaxPeoplePerScore(arrA[0], arrA[1])
            <  getMaxPeoplePerScore(arrB[0], arrB[1])
        );
    }
};

int main() {

    int temp;
    while (cin >> temp) {
        int p, n;
        p = temp; cin >> n;

        priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> pq;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pq.push({x, 1});
        }

        // (p - n) because we're guaranteed to already have
        // assigned at least 1 score to all groups.
        for (int i = 0; i < (p - n); i++) {
            // Add a score to the group that would minimize
            // our counts the most.
            array<int, 2> modified = {pq.top()[0], pq.top()[1] + 1};
            pq.pop();
            pq.push(modified);
        }

        // The root node now contains our answer.
        cout << (getMaxPeoplePerScore(pq.top()[0], pq.top()[1])) << endl;
    }
}
