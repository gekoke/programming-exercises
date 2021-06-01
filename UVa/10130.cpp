#include <iostream>

using namespace std;

void solve() {
  const int maxWeight = 30;

  int N; cin >> N;  // Number of objects.
  int bestValueByWeight[maxWeight + 1] = {};

  // Read objects, determine best value we can get for each specific weight.
  for (int i = 0; i < N; i++) {
    int value; int weight;
    scanf("%d %d", &value, &weight);

    // Update all weight indices for which the best may have changed.
    for (int j = maxWeight; j >= weight; j--) {
      bestValueByWeight[j] = max(bestValueByWeight[j], bestValueByWeight[j - weight] + value);
    }
  }

  int G; cin >> G;  // Number of people in group.
  int total = 0;    // Total value of objects we can get.

  for (int i = 0; i < G; i++) {
    int personCarryCapacity; cin >> personCarryCapacity;
    total += bestValueByWeight[personCarryCapacity];
  }

  cout << total << endl;
}

int main() {
  int T; cin >> T;

  for (int i = 0; i < T; i++) solve();
  return 0;
}
