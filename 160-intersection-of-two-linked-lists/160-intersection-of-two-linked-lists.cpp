/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDifference(ListNode* headA,ListNode* headB) {
     int len1 = 0,len2 = 0;
        while(headA != NULL || headB != NULL) {
            if(headA != NULL) {
                ++len1; headA = headA->next;
            }
            if(headB != NULL) {
                ++len2; headB = headB->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //DIFFERENCE OF LENGTHS APPROACH
        int diff = getDifference(headA,headB);
        if(diff < 0) 
            while(diff++ != 0) headB = headB->next; 
        else while(diff-- != 0) headA = headA->next;
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};