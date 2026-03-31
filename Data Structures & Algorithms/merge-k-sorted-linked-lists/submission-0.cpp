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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode();
        ListNode* node=head;
        pair<ListNode*, int> minNode={new ListNode(INT_MAX), -1};
        bool flag=false;
        while(!flag) {
            flag=true;
            minNode={new ListNode(INT_MAX), -1};
            for(int i=0; i<lists.size(); i++) {
                if(lists[i]!=NULL) {
                    flag=false; 
                    if(minNode.first->val>lists[i]->val) {
                        minNode.first->val=lists[i]->val;
                        minNode.second=i;
                    }
                }
            }
            if(!flag) {
                lists[minNode.second]=lists[minNode.second]->next;
                head->next=minNode.first;
                head=head->next;
            }
        }
        return node->next;
    }
};
