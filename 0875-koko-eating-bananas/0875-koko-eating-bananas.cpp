class Solution {
public:
    bool canEat(vector<int>&piles , int mid , int h){
        int time = 0;

        for(int x : piles){
            time += x/mid;

            if(x%mid != 0){
                time++;
            }

        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        int e = *max_element(begin(piles) , end(piles));
     

        while(s<e){
            int mid = s+(e-s)/2;
            if(canEat(piles , mid , h)){
               
                e = mid;
            }
            else {
                s = mid+1;
            }
        }

        return s;
    }
};