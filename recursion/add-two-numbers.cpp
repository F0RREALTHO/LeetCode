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

    // int convertListtoNumber(ListNode* head){
    //     string s="";
    //     ListNode* temp = head;
    //     while(temp){
    //         s += to_string(temp->val);
    //         temp = temp->next;
    //     }
    //     reverse(s.begin(),s.end());
    //     return stoi(s);
    // }

    // ListNode* convertNumbertoList(int num){
    //     string s = to_string(num);
    //     reverse(s.begin(),s.end());
    //     ListNode* head = new ListNode(s[0]-'0',nullptr);
    //     ListNode* mover = head;
    //     for(int i = 1; i < s.size(); i++){
    //         ListNode* temp = new ListNode(s[i]-'0',nullptr);
    //         mover->next = temp;
    //         mover = temp;
    //     }
    //     return head;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int carry = 0;

        while(l1||l2||carry){
            int sum = carry;
            if(l1){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2= l2->next;
            }
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }
        return head->next;
    }
};