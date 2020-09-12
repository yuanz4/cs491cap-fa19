#include <iostream>

using namespace std;

void output(bool success, int day) {
	if (success)
        cout << "success on day ";
    else
        cout << "failure on day ";
    cout << day << endl;
}

int main() {
    float H, U, D, F;
    while (cin>>H>>U>>D>>F) {
        if (H == 0)
            break;
        int day = 1;
        float cur = 0, rate = 1;
        while (true) {
            float up = 0;
            if (rate > 0)
                up = U*rate;
            cur += up;
            if (cur > H) {
            	output(1, day);
            	break;
            }
            cur -= D;
            if (cur < 0) {
            	output(0, day);
            	break;
            }
            day++;
            rate -= F/100;
        }

    }
    return 0;
}
