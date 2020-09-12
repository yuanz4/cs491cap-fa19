#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int w = 60, h = 25;
const int width = 512;
const double alpha = 1;
const int threshold = 10;
const int factor = 2;


vi centroid(vector<vi>& target) {
    int wc = 0, wv = 0;
    int hc = 0, hv = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (target[i][j]) {
                wc++, hc++;
                wv += j, hv += i;
            }
        }
    }
    int wCenter = wv / wc;
    int hCenter = hv / hc;
    return {wCenter, hCenter};
}

const int dir_r[] = {-1, -1, 0};
const int dir_c[] = {-1, 0, -1};

map<double, vi> detect(vector<vi>& target, vector<vi>& scene, int wCenter, int hCenter) {
    map<double, vi> m;
    for (int i = 0; i < width-h; i++) {
        for (int j = 0; j < width-w; j++) {
            double cost = 0;
            for (int k = 1; k < h; k++) {
                for (int l = 1; l < w; l++) {
                    for (int dir = 0; dir < 1; dir++) {
                        int targetDiff = target[k+dir_r[dir]][l+dir_c[dir]]-target[k][l];
                        int sceneDiff = scene[i+k+dir_r[dir]][j+l+dir_c[dir]]-scene[i+k][j+l];
                        cost += pow(sceneDiff-targetDiff*alpha, 2);
                    }
                }
            }
            m[cost] = {i+hCenter, j+wCenter};
        }
    }
    return m;
}

int main()
{
    vector<vector<int>> target(25);
    for (int i = 0; i < 25; i++) {
        target[i].resize(60);

        for (int j = 0; j < 60; j++) {
            cin >> target[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> scene(512);
    int biggest = 0;
    for (int i = 0; i < 512; i++) {
        scene[i].resize(512);

        for (int j = 0; j < 512; j++) {
            cin >> scene[i][j];
            biggest = max(biggest, scene[i][j]);
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vi cen = centroid(target);
    int wCenter = cen[0];
    int hCenter = cen[1];

    map<double, vi> m = detect(target, scene, wCenter, hCenter);
    vector<vi> ret;
    double start = -1;
    for (auto it: m) {
        // printf("%f %d %d\n", it.first, it.second[1], it.second[0]);
        if (start == -1)
            start = it.first;
        int curW = it.second[1], curH = it.second[0];
        for (int i = 0; i < ret.size(); i++) {
            if (abs(ret[i][0]-curW) < threshold && abs(ret[i][1]-curH) < threshold)
                goto next;
        }
        ret.push_back({curW, curH});
        next:
        if (it.first > factor*start)
            break;
    }
    for (int i = 0; i < ret.size(); i++)
        printf("%d %d\n", ret[i][0], ret[i][1]);
    return 0;
}
