#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a petrol pump
struct petrolpump {
    int petrol;
    int distance;
};

// Function to find the starting point for the petrol pump tour
int tour(vector<petrolpump>& p) {
    int n = p.size(); // Get the number of petrol pumps
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0) {
        return start;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    vector<petrolpump> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter petrol and distance for petrol pump " << i + 1 << ": ";
        cin >> p[i].petrol >> p[i].distance;
    }

    int start = tour(p);

    if (start == -1) {
        cout << "No possible tour exists." << endl;
    } else {
        cout << "The starting point of the tour is petrol pump " << start + 1 << endl;
    }

    return 0;
}
