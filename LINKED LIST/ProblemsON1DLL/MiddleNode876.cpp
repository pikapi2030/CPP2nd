#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode*next;
};
/*
return middle ListNode of linked list, if even numbers, return the second middle
*/

/*BRUTE
calculate lenght of ll, then ((n/2)+1)th ListNode will be middle
T.C O(N+N/2)
*/

ListNode* BRUTE(ListNode*head)
{
    ListNode*temp=head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    int cnt=0;
    temp=head;
    while(cnt!=(n/2)+1)
    {
     cnt++;
     temp=temp->next;
    }
    return temp;


}

/*OPTI
use tortoise and hare algo
T.C O(N/2)
*/
ListNode* optimal(ListNode*head)
{
ListNode*slow=head;
ListNode*fast=head;
int cnt=0;
while(fast!=NULL&&(fast->next)!=NULL)//if number of nodes are odd, fast will end at last node, if even fast will end at NULL

{
slow=slow->next;
fast=fast->next->next;
}
return slow;
}


