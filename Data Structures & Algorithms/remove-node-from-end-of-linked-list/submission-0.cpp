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
    void remove(ListNode* head, int& n) {
        if(head==NULL) {
            return;
        }
        remove(head->next, n);
        if(n==0) {
            flag=true;
            head->next=head->next->next;
        }
        n--;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        remove(head, n);
        if(!flag) {
            return head->next;
        }
        return head;
    }   
};
