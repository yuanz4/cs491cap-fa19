#include <bits/stdc++.h> 

using namespace std; 

const int MX = 1000+7;
const int INF = 0x3f3f3f3f;

int ini_seg_max[MX][MX>>2];
int fin_seg_max[MX>>2][MX>>2];
int ini_seg_min[MX][MX>>2];
int fin_seg_min[MX>>2][MX>>2];
int rect[MX][MX];
int size;

void segment(int low, int high, int pos, int strip) {
    if (high == low) {
        ini_seg_max[strip][pos] = rect[strip][low];
        ini_seg_min[strip][pos] = rect[strip][low];
    } else {
        int mid = (low + high) / 2;
        segment(low, mid, 2 * pos, strip);
        segment(mid + 1, high, 2 * pos + 1, strip);
        ini_seg_max[strip][pos] = max(ini_seg_max[strip][2 * pos], ini_seg_max[strip][2 * pos + 1]);
        ini_seg_min[strip][pos] = min(ini_seg_min[strip][2 * pos], ini_seg_min[strip][2 * pos + 1]);
    }
}

void finalSegment(int low, int high, int pos) {
    if (high == low) {
        for (int i = 1; i < 4 * size; i++) {
            fin_seg_max[pos][i] = ini_seg_max[low][i];
            fin_seg_min[pos][i] = ini_seg_min[low][i];
        }
    } else {
        int mid = (low + high) / 2;
        finalSegment(low, mid, 2 * pos);
        finalSegment(mid + 1, high, 2 * pos + 1);
        for (int i = 1; i <= 4 * size; i++) {
            fin_seg_max[pos][i] = max(fin_seg_max[2 * pos][i], fin_seg_max[2 * pos + 1][i]);
            fin_seg_min[pos][i] = min(fin_seg_min[2 * pos][i], fin_seg_min[2 * pos + 1][i]);
        }
    }
}

pair<int, int> finalQuery(int pos, int start, int end, int y1, int y2, int node) { 
    if (y2 < start || end < y1)
        return {-INF, INF};
    if (y1 <= start && end <= y2)
        return {fin_seg_max[node][pos], fin_seg_min[node][pos]};
    int mid = (start + end) / 2;
    pair<int, int> p1 = finalQuery(2 * pos, start, mid, y1, y2, node);
    pair<int, int> p2 = finalQuery(2 * pos + 1, mid + 1, end, y1, y2, node);
    int first = max(p1.first, p2.first);
    int second = min(p1.second, p2.second);
    return {first, second};
}

pair<int, int> query(int pos, int start, int end, int x1, int x2, int y1, int y2) {
    if (x2 < start || end < x1)
        return {-INF, INF};
    if (x1 <= start && end <= x2)
        return finalQuery(1, 1, size, y1, y2, pos);
    int mid = (start + end) / 2;
    pair<int, int> p1 = query(2 * pos, start, mid, x1, x2, y1, y2);
    pair<int, int> p2 = query(2 * pos + 1, mid + 1, end, x1, x2, y1, y2);
    int first = max(p1.first, p2.first);
    int second = min(p1.second, p2.second);
    return {first, second};
}

void finalUpdate(int pos, int low, int high, int y, int val, int node) { 
    if (low == high) {
        fin_seg_max[node][pos] = val;
        fin_seg_min[node][pos] = val;
    } else { 
        int mid = (low + high) / 2;
        if (low <= y && y <= mid)
            finalUpdate(2 * pos, low, mid, y, val, node);
        else
            finalUpdate(2 * pos + 1, mid + 1, high, y, val, node);
        fin_seg_max[node][pos] = max(fin_seg_max[node][2 * pos], fin_seg_max[node][2 * pos + 1]);
        fin_seg_min[node][pos] = min(fin_seg_min[node][2 * pos], fin_seg_min[node][2 * pos + 1]);
    }
}

void update(int pos, int low, int high, int x, int y, int val) { 
    if (low == high)
        finalUpdate(1, 1, size, y, val, pos);
    else { 
        int mid = (low + high) / 2;
        if (low <= x && x <= mid)
            update(2 * pos, low, mid, x, y, val);
        else
            update(2 * pos + 1, mid + 1, high, x, y, val);
        for (int i = 1; i < 4 * size; i++) {
            fin_seg_max[pos][i] = max(fin_seg_max[2 * pos][i], fin_seg_max[2 * pos + 1][i]); 
            fin_seg_min[pos][i] = min(fin_seg_min[2 * pos][i], fin_seg_min[2 * pos + 1][i]); 
        }
    }
}

int main() {
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &rect[i][j]);
        }
    }
    for (int strip = 0; strip < size; strip++)
        segment(0, size-1, 1, strip);
    finalSegment(0, size-1, 1);
    int Q;
    scanf("%d", &Q);
    char type;
    int x1, y1, x2, y2, x, y, v;
    while (Q--) {
        scanf(" %c", &type);
        if (type == 'q') {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            pair<int, int> p = query(1, 1, size, x1, x2, y1, y2);
            printf("%d %d\n", p.first, p.second);
        } else {
            scanf("%d %d %d", &x, &y, &v);
            update(1, 1, size, x, y, v);
        }
    }
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// const int MAXN = 512, INF = 0x7f7f7f7f;

// int data[MAXN][MAXN];
// pair<int, int> st[4 * MAXN * MAXN];

// void pushUp(int p)
// {
//     int high = -INF, low = INF;
//     for (int i = 1; i <= 4; i++) {
//         high = max(high, st[4 * p + i].first);
//         low = min(low, st[4 * p + i].second);
//     }
//     st[p].first = high, st[p].second = low;
// }

// void build(int p, int r1, int c1, int r2, int c2)
// {
//     if (r1 > r2 || c1 > c2) {
//         st[p] = make_pair(-INF, INF);
//         return;
//     }
//     if (r1 == r2 && c1 == c2) {
//         st[p] = make_pair(data[r1][c1], data[r1][c1]);
//         return;
//     }

//     int mr = (r1 + r2) >> 1, mc = (c1 + c2) >> 1;
//     build(4 * p + 1, r1, c1, mr, mc);
//     build(4 * p + 2, r1, mc + 1, mr, c2);
//     build(4 * p + 3, mr + 1, c1, r2, mc);
//     build(4 * p + 4, mr + 1, mc + 1, r2, c2);
//     pushUp(p);
// }

// void update(int p, int r1, int c1, int r2, int c2, int ur, int uc, int v)
// {
//     if (r1 > r2 || c1 > c2) return;
//     if (r1 == r2 && c1 == c2 && r1 == ur && c1 == uc) st[p] = make_pair(v, v);
//     else
//     {
//         int mr = (r1 + r2) >> 1, mc = (c1 + c2) >> 1;
//         if (ur >= r1 && ur <= mr && uc >= c1 && uc <= mc)
//             update(4 * p + 1, r1, c1, mr, mc, ur, uc, v);
//         else if (ur >= r1 && ur <= mr && uc >= mc + 1 && uc <= c2)
//             update(4 * p + 2, r1, mc + 1, mr, c2, ur, uc, v);
//         else if (ur >= mr + 1 && ur <= r2 && uc >= c1 && uc <= mc)
//             update(4 * p + 3, mr + 1, c1, r2, mc, ur, uc, v);
//         else if (ur >= mr + 1 && ur <= r2 && uc >= mc + 1 && uc <= c2)
//             update(4 * p + 4, mr + 1, mc + 1, r2, c2, ur, uc, v);
//         pushUp(p);
//     }
// }

// pair<int, int> query(int p, int r1, int c1, int r2, int c2, int qr1, int qc1, int qr2, int qc2)
// {
//     if (r1 > r2 || c1 > c2) return make_pair(-INF, INF);
//     if (r2 < qr1 || c2 < qc1 || r1 > qr2 || c1 > qc2) return make_pair(-INF, INF);
//     if (qr1 <= r1 && r2 <= qr2 && qc1 <= c1 && c2 <= qc2) return st[p];

//     int mr = (r1 + r2) >> 1, mc = (c1 + c2) >> 1;
//     pair<int, int> q1 = query(4 * p + 1, r1, c1, mr, mc, qr1, qc1, qr2, qc2);
//     pair<int, int> q2 = query(4 * p + 2, r1, mc + 1, mr, c2, qr1, qc1, qr2, qc2);
//     pair<int, int> q3 = query(4 * p + 3, mr + 1, c1, r2, mc, qr1, qc1, qr2, qc2);
//     pair<int, int> q4 = query(4 * p + 4, mr + 1, mc + 1, r2, c2, qr1, qc1, qr2, qc2);
//     int high = max(max(q1.first, q2.first), max(q3.first, q4.first));
//     int low = min(min(q1.second, q2.second), min(q3.second, q4.second));

//     return make_pair(high, low);
// }

// int main(int argc, char *argv[])
// {
//     cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

//     int n;
//     cin >> n;
        
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> data[i][j];

//     build(0, 0, 0, n - 1, n - 1);

//     int q, x1, y1, x2, y2, v;
//     char action;

//     cin >> q;
//     for (int i = 1; i <= q; i++)
//     {
//         cin >> action;
//         if (action == 'c')
//         {
//             cin >> x1 >> y1 >> v;
//             update(0, 0, 0, n - 1, n - 1, x1 - 1, y1 - 1, v);
//         }
//         else
//         {
//             cin >> x1 >> y1 >> x2 >> y2;
//             x2 = min(x2, n), y2 = min(y2, n);
//             pair<int, int> r = query(0, 0, 0, n - 1, n - 1, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
//             cout << r.first << ' ' << r.second << '\n';
//         }
//     }

//     return 0;
// }