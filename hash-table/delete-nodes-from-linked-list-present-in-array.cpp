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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            if(toDelete.count(temp->val)){
                if(prev==NULL){
                    head = head->next;
                    temp = head;
                    continue;
                }
                prev->next = temp->next;
                temp = prev->next;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};