class Solution {
public:
bool vaild(string s){
    int cnt=0;
    int i;
    for (i=0;i<s.size();i++){
        if(s[i]=='('){
            cnt++;
        }else{
            if(s[i]==')'){
                cnt--;
            }if(cnt<0){
                return false;
            }
        }
    }return cnt==0;
}
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        bool found=false;
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            if(vaild(cur)){
                ans.push_back(cur);
                found=true;
            }
            if(found) 
            continue;
            for(int i=0;i<cur.size();i++){
                if(cur[i]!='(' &&cur[i] !=')') 
                continue;
                string next=cur.substr(0,i)+cur.substr(i+1);
                
                if(vis.find(next)==vis.end()){
                    vis.insert(next);
                    q.push(next);
                    
                }
            }
        }return ans;
           }
};