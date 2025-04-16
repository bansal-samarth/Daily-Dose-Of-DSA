class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack <int> res;

        for(int i=0; i<asteroids.size(); i++)
        {
            if(asteroids[i] < 0)
            {
                while(!res.empty() && res.top() > 0 && res.top() < abs(asteroids[i])) {
                    res.pop();
                }
                if(res.empty() || res.top() < 0) {
                    res.push(asteroids[i]);
                }
                else if(res.top() + asteroids[i] == 0)
                    res.pop();
            }
            else {
                res.push(asteroids[i]);
            }
        }

        vector <int> ans;

        while(!res.empty() )
        {
            ans.push_back(res.top());
            res.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};