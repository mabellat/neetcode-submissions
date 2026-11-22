class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0, j = n-1;
        int score = 0;
        int max_score = score;
        sort(begin(tokens), end(tokens));
        while(i<=j)
        {
            if(power>=tokens[i]){
                power-=tokens[i];
                score+=1;
                max_score = max(max_score, score);
                i++;
            }else{
                if(score>=1){
                    power+=tokens[j];
                    score-=1;
                    j--;
                    max_score = max(max_score, score);
                }else j--;
            }
        }
        return max_score;
    }
};