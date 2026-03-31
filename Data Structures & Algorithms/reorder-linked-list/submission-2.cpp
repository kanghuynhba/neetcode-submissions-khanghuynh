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
private:
    bool flag=false;
public:
    void reorder(ListNode* tail, ListNode*& head) {
        if(tail==NULL) {
            return;
        }
        reorder(tail->next, head);
        if(flag) {
            return;
        }
        if(head==tail || head->next==tail) {
            tail->next=NULL;
            flag=true;
            return;
        }
        ListNode* node=new ListNode(tail->val, head->next);
        head->next=node;
        head=head->next->next;
    }
    void reorderList(ListNode* head) {
        reorder(head, head);
    }
};