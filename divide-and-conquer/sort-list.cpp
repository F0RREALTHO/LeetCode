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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        if (arr.empty()) return nullptr;
        sort(arr.begin(),arr.end());
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* mover = newHead;
        for(int i = 1; i< arr.size(); i++){
            ListNode* hehe = new ListNode(arr[i]);
            mover->next = hehe;
            mover = hehe;
        }
        return newHead;
    }
};