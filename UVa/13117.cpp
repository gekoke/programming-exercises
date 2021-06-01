#include <iostream>
#include <vector>
#include <math.h>
#include <float.h>

using namespace std;

const double EPSILON = 1e-7;

struct line {
    double a;
    double b;
    double c;
};

struct edge {
    pair<double, double> p1;
    pair<double, double> p2;
};

void findAllEdges(vector<edge>& edges, int N) {
    // Essentially a queue with length = 2.
    pair<double, double> firstVertex;
    pair<double, double> prevVertex;

    for (int i = 0; i < N; i++) {
        double xV, yV; cin >> xV >> yV;
        pair<double, double> currentVertex = {xV, yV};

        if (i == 0) firstVertex = currentVertex;
        else edges.push_back({prevVertex, currentVertex});
        prevVertex = currentVertex;
    }
    // Connect last vertex to first vertex.
    edges.push_back({prevVertex, firstVertex});
}

line findLine(pair<double, double> p1, pair<double, double> p2) {
    double a = p1.second - p2.second;
    double b = -(p1.first - p2.first);
    double c = p1.first * p2.second - p2.first * p1.second;

    line output = {a, b, c};
    return output;
}

pair<double, double> closestPointOnLine(line l, pair<double, double> point) {
    // https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
    double a, b, c; a = l.a; b = l.b; c = l.c;
    double x = (b * (b * point.first - a * point.second) - a * c) / (pow(a, 2) + pow(b, 2));
    double y = (a * (-1 * b * point.first + a * point.second) - b * c) / (pow(a, 2) + pow(b, 2));

    return {x, y};
}

bool isBetweenPoints(pair<double, double> examined, pair<double, double> bound1, pair<double, double> bound2) {
    if (bound1.first < bound2.first && (examined.first < bound1.first || examined.first > bound2.first)) return false;
    if (bound1.first > bound2.first && (examined.first > bound1.first || examined.first < bound2.first)) return false;
    if (bound1.second < bound2.second && (examined.second < bound1.second || examined.second > bound2.second)) return false;
    if (bound1.second > bound2.second && (examined.second > bound1.second || examined.second < bound2.second)) return false;
    if (abs(bound1.first - bound2.first) < EPSILON && abs(bound2.first - examined.first) < EPSILON) return true;
    if (abs(bound1.second - bound2.second) < EPSILON && abs(bound2.second - examined.second) < EPSILON) return true;
    return abs(
        (examined.second - bound1.second) / (bound2.second - bound1.second)
        - (examined.first - bound1.first) / (bound2.first - bound1.first)
    ) < EPSILON;
}

double euclidianDistance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

void solve(int N) {
    double xR, yR; cin >> xR >> yR;
    const pair<double, double> REDIS = {xR, yR};

    // Find all edges by going over all the vertices.
    vector<edge> edges; findAllEdges(edges, N);

    // For every edge, find its closest point to REDIS (xR, yR).
    double closestPointDist = DBL_MAX;
    for (edge e : edges) {
        line l = findLine(e.p1, e.p2);

        // Find closest point to REDIS on the line drawn by the edge.
        pair<double, double> closestPoint = closestPointOnLine(l, REDIS);
        double pointDist;

        if (isBetweenPoints(closestPoint, e.p1, e.p2)) {
            // Check that this point is on the edge. If so, this is the closest point.
            pointDist = euclidianDistance(closestPoint, REDIS);
        } else {
            // If not on line segment (edge), closest point on edge is one of the vertices.
            pointDist = min(euclidianDistance(e.p1, REDIS), euclidianDistance(e.p2, REDIS));
        }

        if (pointDist < closestPointDist) closestPointDist = pointDist;
    }

    printf("%.3f\n", closestPointDist);
}

int main() {
    int N;
    while (cin >> N) solve(N);
}
