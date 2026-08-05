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
    ListNode* deleteDuplicates(ListNode* head) {
        // map<int,int> seen;
        // ListNode* temp = head;
        // ListNode* prev = nullptr;
        // while(temp){
        //     if(!seen[temp->val]){
        //         seen[temp->val]++;
        //         prev = temp;
        //         temp = temp->next;
        //     }
        //     else {
        //         prev->next = temp->next;
        //         delete temp;
        //         temp = prev->next;
        //     }
        // }

        ListNode* curr = head;
        while(curr && curr->next){
            if(curr->val==curr->next->val){
                curr->next = curr->next->next;
            }
            else curr = curr->next;
        }
        return head;
    }
};