#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

void output(int knights, int row, int col) {
    printf("%d knights may be placed on a %d row %d column board.\n", knights, row, col);
}

int main() {
    int row, col;
    while (cin>>row>>col) {
        if (!row && !col)
            break;
        if (row==1 || col==1)
            output(max(row,col), row, col);
        else if (row==2 || col==2) {
            int l = row==2 ? col : row;
            output((l/4*2+min(l%4,2))*2, row, col);
        } else
            output(ceil((row*col)/2.0), row, col);
    }
    return 0;
}
