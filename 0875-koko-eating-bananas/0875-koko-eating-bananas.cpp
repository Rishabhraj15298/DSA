class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {
    long long time = 0;  // Change here

    for (int x : piles) {
        time += x / mid;

        if (x % mid != 0) {
            time++;
        }

        if (time > h) return false;  // Optional optimization
    }

    return time <= h;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(begin(piles), end(piles));

        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (canEat(piles, mid, h)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};