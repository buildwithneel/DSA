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
    ListNode* middleNode(ListNode* head) {
    int n=0;
    ListNode* save=head;
    while(save!=nullptr){
        n++;
        save=save->next;
    }
    save=head;
    for(int i=0;i<n/2;i++){
        save=save->next;
    }
    return save;
    }
};