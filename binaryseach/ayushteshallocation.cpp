#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool ispossible(int n, int m, int time[], int mid) {
    int chapter = 1;
    int timeofstudy = 0;


    for (int i = 0; i < m; i++) {
        if (time[i] > mid) {
            return false;
        }
        if (timeofstudy + time[i] <= mid) {
            timeofstudy += time[i];
        } else {
            chapter++;
            if (chapter > n) {
                return false;
            }
            timeofstudy = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, int time[]) {
    long long s = 0;
    long long sum = 0;
    long long ans = -1;
    for (int i = 0; i < m; i++) {
        sum += time[i];  // Fix: Use += instead of =+
    }
    long long e = sum;

    while (s <= e) {
        long long mid = s + (e - s) / 2;  // Move mid calculation inside the loop

        if (ispossible(n, m, time, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 3;
    int m = 5;
    int pages[5] = {1, 2, 2, 3, 1};

    cout << "The minimum value of the maximum number of pages in book allocation is " << ayushGivesNinjatest(3, 5, pages) << endl;

    return 0;
}
