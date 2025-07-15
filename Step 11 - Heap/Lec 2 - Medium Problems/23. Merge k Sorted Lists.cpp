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
        int n = lists.size();
       
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < n; i++) 
        {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (!pq.empty()) 
        {
            auto [val, node] = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next) 
                pq.push({node->next->val, node->next});
        }

        return ans->next;
    }
};
