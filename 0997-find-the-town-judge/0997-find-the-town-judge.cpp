class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1,0);
        for(auto relation:trust){
            int person=relation[0];
            int trusted=relation[1];
            score[person]--;
            score[trusted]++;
        }
        for(int person=1;person<=n;person++){
            if(score[person]==n-1){
                return person;
            }
        }return -1;
    }
};