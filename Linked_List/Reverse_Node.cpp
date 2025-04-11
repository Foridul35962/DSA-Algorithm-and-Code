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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        {
            return head;
        }
        ListNode* tamp=head;
        int cnt=0;
        while(cnt<k)
        {
            if(tamp==NULL)
                return head;
            tamp=tamp->next;
            cnt++;
        }

        ListNode* pre=reverseKGroup(tamp,k);
        tamp=head;
        cnt=0;
        while(cnt<k)
        {
            ListNode* next=tamp->next;
            tamp->next=pre;
            pre=tamp;
            tamp=next;
            head=pre;
            cnt++;
        }
        return head;

    }
};