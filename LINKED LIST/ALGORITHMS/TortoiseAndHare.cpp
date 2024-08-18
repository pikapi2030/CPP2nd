#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode*next;
};

 
/*
this is opti solution to calculate length of LL
*/ 

/*
in this algorithm we have two pointers, one is slow, one is fast
the fast pointer is incremented 2 times mean while slow one is incremented 1 times
when fast pointer reaches end of LL, the slow one is at middle of LL
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



