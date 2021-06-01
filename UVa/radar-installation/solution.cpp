#include <iostream>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;

struct Comparator {
    bool operator() (array<float, 4> a, array<float, 4> b) {
        return (a[2] < b[2]);
    }
};

// Return the X coordinate of radar with range d
// at which this island would exit its range.
float get_radar_exit(float x, float y, float d) {
    return x - (pow(pow(d, 2) - pow(y, 2), 0.5));
}

// Return the X coordinate of radar with range d
// at which this island would enter its range.
float get_radar_enter(float x, float y, float d) {
    return x + (pow(pow(d, 2) - pow(y, 2), 0.5));
}

int main() {

    string trash;
    int case_num = 1;

    while (true) {
        int n, d;
        cin >> n; cin >> d;
        if (n == 0 && d == 0) break;
        bool no_solution = false;
        int total = 0;

        // Maintain a heap of islands sorted by X coordinate.
        priority_queue<array<float, 4>, vector<array<float, 4>>, Comparator> pq;
        for (int i = 0; i < n; i++) {
            float x, y;
            cin >> x; cin >> y;
            if (no_solution) continue;

            // At least one island is too far, return -1
            if (y > d) {
                no_solution = true;
                continue;
            }

            pq.push(array<float, 4>{x, y, get_radar_exit(x, y, d), get_radar_enter(x, y, d)});
        }

        // Add islands to a single radar's range until one would leave it.
        if (!no_solution) {
            float radar_x;

            if (!pq.empty()) {
                // Place initial radar as left as possible.
                radar_x = pq.top()[2];
                pq.pop(); total++;
            }

            while (!pq.empty()) {
                // If island in range of radar, no need for a new radar.
                if (pq.top()[2] <= radar_x && pq.top()[3] >= radar_x) {
                    pq.pop();
                } else {  // Create a new radar, again as left as possible.
                    radar_x = pq.top()[2];
                    pq.pop(); total++;
                }
            }
        }

        if (no_solution) cout << "Case " << case_num << ": " << -1 << endl;
        else cout << "Case " << case_num << ": " << total << endl;
        case_num++;
        getline(cin, trash);
    }
}
