class Solution {
public:
    vector<string> path;
    void dfs(unordered_map<string, vector<string>>& map, vector<string> &ans, string port, int n) {
        if(path.size()) return;
        
        if(ans.size() == n) {
            path = ans;
            return;
        }
        
        for(int i = 0; i < map[port].size(); i++) {
            string comeTo = map[port][i];
            map[port].erase(map[port].begin() + i);
            ans.push_back(comeTo);
            
            dfs(map, ans, comeTo, n);

            ans.pop_back();
            map[port].insert(map[port].begin() + i, comeTo);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> map;
        for(auto pair : tickets)
            map[pair[0]];
        
        sort(tickets.begin(), tickets.end());
        
        for(auto pair : tickets)
            map[pair[0]].push_back(pair[1]);
        
        vector<string> ans;
        ans.push_back("JFK");

        dfs(map, ans, "JFK", tickets.size()+1);

        return path;
    }
};
