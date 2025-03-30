class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int i = 0;
        while(i < len && n) {
            if(flowerbed[i] == 1) {
                i++;
                continue;
            }
            int prev = i == 0 ? 0 : flowerbed[i-1];
            int next = i == len-1 ? 0 : flowerbed[i+1];
            
            if(!prev && !next) {
                n--;
                cout << i << endl;
                i += 2;
            }
            else {
                i++;
            }
        }

        return n == 0;
    }
};