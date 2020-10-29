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
    class compare
    {
        public:
            bool operator()(ListNode* lhs,ListNode* rhs)
            {
                return lhs->val > rhs->val;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& a) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(int i = 0;i<a.size();i++)
        {
            if(a[i] != NULL)
            {
                pq.push(a[i]);
            }
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while(pq.size() > 0)
        {
            ListNode* topNode = pq.top();
            pq.pop();
            if(topNode->next != NULL)
            {
                pq.push(topNode->next);
                topNode->next = NULL;
            }
            cur->next = topNode;
            cur = topNode;
        }
        return dummyHead->next;
    }
};
