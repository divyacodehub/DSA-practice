#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& position, int m, int mid) {

    int ballCount = 1;
    int lastPos = position[0];

    for(int i = 1; i < position.size(); i++) {

        if(position[i] - lastPos >= mid) {

            ballCount++;
            lastPos = position[i];

            if(ballCount == m)
                return true;
        }
    }

    return false;
}

int maxDistance(vector<int>& position, int m) {

    sort(position.begin(), position.end());

    int start = 1;
    int end = position[position.size() - 1] - position[0];

    int ans = -1;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        if(isPossible(position, m, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {

    vector<int> position = {1, 2, 3, 4, 7};
    int m = 3;

    cout << maxDistance(position, m);

    return 0;
}