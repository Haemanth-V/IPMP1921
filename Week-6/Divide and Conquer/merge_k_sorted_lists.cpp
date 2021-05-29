//Question link: https://leetcode.com/problems/merge-k-sorted-lists/

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
        if(lists.size() == 0)
            return NULL;
        do{
            vector<ListNode*> mergedList; 
            for(int i=0; i<lists.size(); i+=2){
                if(i+1 == lists.size() || lists[i+1] == NULL){
                    if(lists[i] != NULL)
                        mergedList.push_back(lists[i]);
                }
                else if(lists[i] == NULL)
                    mergedList.push_back(lists[i+1]);
                else 
                    mergedList.push_back(sortedMerge(lists[i], lists[i+1]));
            }
            lists = mergedList;
        }while(lists.size() > 1);
        return lists[0];
    }
    ListNode * sortedMerge(ListNode *a, ListNode *b){
        ListNode *res = NULL;
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        if(a->val < b->val){
            res = a;
            res->next = sortedMerge(a->next, b);
        }
        else{
            res = b;
            res->next = sortedMerge(a, b->next);
        }
        return res;
    }
};
