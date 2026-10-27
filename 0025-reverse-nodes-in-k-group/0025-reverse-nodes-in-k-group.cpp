/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i;
        ListNode dummy(0,head);
        ListNode* prev=&dummy;
        while(true){
            ListNode* tail=prev;
            for(i=0;i<k;i++){
                tail=tail->next;
                if(!tail) return dummy.next;
            }
            ListNode* groupStart=prev->next;
            ListNode* nextGroup=tail->next;
            ListNode* cur=groupStart;
            ListNode* before=nextGroup;
            while(cur!=nextGroup){
                ListNode* next=cur->next;
                cur->next=before;
                before=cur;
                cur=next;
            }
            prev->next=tail;
            prev=groupStart;
        }
    }
};