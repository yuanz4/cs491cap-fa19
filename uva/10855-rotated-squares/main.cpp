#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

void rotate(vector<vector<char>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n-1-i; j++) {
            swap(matrix[i][j], matrix[j][n-1-i]);
            swap(matrix[i][j], matrix[n-1-j][i]);
            swap(matrix[n-1-j][i], matrix[n-1-i][n-1-j]);
        }
    }
}

int main() {
    int big, small;
    while (cin>>big>>small) {
        if (!big && !small)
        	break;
        vector<vector<char>> B(big, vector<char>(big, '.'));
        vector<vector<char>> S(small, vector<char>(small, '.'));
        string tmp;
        for (int i = 0; i < big; i++) {
        	cin >> tmp;
            for (int j = 0; j < big; j++)
                B[i][j] = tmp[j];
        }
        for (int i = 0; i < small; i++) {
            cin >> tmp;
            for (int j = 0; j < small; j++)
                S[i][j] = tmp[j];
        }
        int output[4] = {0};
        for (int r = 0; r < 4; r++) {
            for (int X = 0; X <= big-small; X++) {
                for (int Y = 0; Y <= big-small; Y++) {
                    bool found = true;
                    for (int x = 0; x < small; x++) {
                        for (int y = 0; y < small; y++) {
                            if (S[x][y] != B[X+x][Y+y]) {
                                found = false;
                                goto end;
                            }
                        }
                    }
                    end:
                    if (found)
                        output[r]++;
                }
            }
            rotate(S);
        }
        printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
    }
    return 0;
}
