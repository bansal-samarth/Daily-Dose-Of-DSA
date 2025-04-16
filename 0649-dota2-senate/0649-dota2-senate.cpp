class Solution {
public:
    string predictPartyVictory(string senate) {
        int rmvR = 0;
        int rmvD = 0;
        int R = 0;
        int D = 0;

        queue<char> q;
        for(char ch : senate){
            q.push(ch);

            if(ch == 'R')
                R++;
            else
                D++;
        }
        
        while(q.size() > 1 && R && D) {
            char sen = q.front();
            q.pop();

            if(sen == 'R') {
                if(rmvR)
                    rmvR--;
                else {
                    D--;
                    rmvD++;
                    q.push(sen);
                }
            } else {
                if(rmvD)
                    rmvD--;
                else {
                    R--;
                    rmvR++;
                    q.push(sen);
                }
            }
        }

        return R ? "Radiant" : "Dire";
    }
};