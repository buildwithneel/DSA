class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=s.size(),m=words.size();
        if(m==0) return ans;
        int len=words[0].size();
        unordered_map<string,int> mp;
        for(auto &w:words) mp[w]++;

        for(int i=0;i<len;i++){
            unordered_map<string,int> cur;
            int l=i,cnt=0;
            for(int j=i;j+len<=n;j+=len){
                string w=s.substr(j,len);
                if(!mp.count(w)){
                    cur.clear();
                    cnt=0;
                    l=j+len;
                    continue;
                }
                cur[w]++;
                cnt++;
                while(cur[w]>mp[w]){
                    cur[s.substr(l,len)]--;
                    cnt--;
                    l+=len;
                }
                if(cnt==m){
                    ans.push_back(l);
                    cur[s.substr(l,len)]--;
                    cnt--;
                    l+=len;
                }
            }
        }
        return ans;
    }
};