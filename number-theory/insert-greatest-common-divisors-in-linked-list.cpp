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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 1;
        while(temp){
            if(cnt==2){
                int gcd = __gcd(prev->val,temp->val);
                ListNode* newNode = new ListNode(gcd,temp);
                prev->next=newNode;
                cnt =1;
            }
            prev=temp;
            temp = temp->next;
            cnt++;
        }
        return head;
    }
};