#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    int index = 1, tmp;
    bool success = true;
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &tmp);
        while (tmp != index) {
            printf("%d\n", index++);
            success = false;
        }
        if (tmp == index) {
            index++;
            continue;
        }
    }
    if (success) {
        printf("good job\n");
    }
    return 0;
}
