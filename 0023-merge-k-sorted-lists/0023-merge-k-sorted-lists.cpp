class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val>b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                pq.push(lists[i]);}
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* cur=pq.top();
            pq.pop();
            tail->next=cur;
            tail=cur;
            if(cur->next!=NULL)
                pq.push(cur->next);}
        tail->next=NULL;
        return dummy->next;
    }
};