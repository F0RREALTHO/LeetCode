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
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp=temp->next;
        }

        int count = cnt/2;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(count--){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        if(cnt&1) curr=curr->next;
        ListNode* h1 = prev;
        ListNode* h2 = curr;
        while(h1&&h2){
            if(h1->val!=h2->val) {
                return false;
            }
            h1=h1->next;
            h2 = h2->next;
        }
        return true;

    }
};