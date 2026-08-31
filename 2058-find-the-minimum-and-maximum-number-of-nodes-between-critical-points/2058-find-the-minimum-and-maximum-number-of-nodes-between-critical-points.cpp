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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int first = -1;
        int previous = -1;

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != nullptr && curr->next != nullptr){
            bool critical = (curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val);

            if(critical){
                if(first == -1){
                    first = index;
                }
                else{
                    minDist = min(minDist, index-previous);
                }

                previous = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if(first == -1 || first == previous){
            return {-1, -1};
        }

        int maxDist = previous - first;

        return {minDist, maxDist};
    }
};