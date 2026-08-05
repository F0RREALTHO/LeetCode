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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dumb;
        ListNode* hehe = &dumb;
        ListNode* head = hehe;

        while(list1 && list2){
            if(list1->val<=list2->val){
                hehe->next = list1;
                list1 = list1->next;
            }else{
                hehe->next = list2;
                list2 = list2->next;
            }
            hehe = hehe->next;
        }
        if(list1) hehe->next = list1;
        if(list2) hehe->next = list2;

        return head->next;
    }
};