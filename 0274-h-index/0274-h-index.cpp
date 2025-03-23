class Solution {
public:
    int hIndex(vector<int>& cit) {
        ranges::sort(cit);

        int n = cit.size();

        int h = 1;
        for(int i = n-1; i >= 0; i--) {
            if(h > cit[i])
                return h - 1;
            h++;
        }

        return n;
    }
};