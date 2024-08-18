#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode*next;
};
/*
Given the head of a singly linked list, group all the ListNodes with odd indices together
 followed by the ListNodes with even indices, and return the reordered list.

The first ListNode is considered odd, and the second ListNode is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it 
was in the input.
*/


/*BRUTE
using extra space(vector)
store odd ListNodes in vector first, then even ListNodes(in the same vector)
now the ListNodes are arranged, transfer the data in LL 

NOTE: when travesing with two steps at one time(temp=temp->next->next) we have to make
sure the condition of while loop to be temp!=NULL&&temp->next!NULL
because if our temp is on the last node, then next is null and next of null is error

but by doing this we cannot access the last node so we have to manually add it

T.C O(2N)
S.C O(N)

*/

ListNode* BRUTE(ListNode*head)
{
if(head==NULL||head->next==NULL)
{
    return head;
}    
vector<int>v;
ListNode*temp=head;

while(temp!=NULL&&temp->next!=NULL)
{
    v.push_back(temp->val);
    temp=temp->next->next;//taking odd in
}
if(temp)//temp->next!=NULL means we cant access the last node, so we have to add it manually
//if(temp) means if temp is not NULL (condsider null as 0)

{
    v.push_back(temp->val);
}
temp=head->next;
while(temp!=NULL&&temp->next!=NULL)//if temp is on last node, next will be NULL and next of NULL is undefined behaviour(error)
{
    v.push_back(temp->val);
    temp=temp->next->next;
}
if(temp)//temp->next!=NULL means we cant access the last node, so we have to add it manually
//if(temp) means if temp is not NULL (condsider null as 0)
{
    v.push_back(temp->val);
}

temp=head;
int i=0;
while(temp!=NULL)
{
    temp->val=v[i];
    i++;
    temp=temp->next;
}
return head;
}

/*OPTIMAL
instead of changing shifting the data, we will change links itself,
so we maintain two pointers odd and even
odd at head, even at next of head
odd changes its next to next odd node and moves there, same goes for even

at last we need to connect the last odd with first even, but we don't have access
to it after changing links so we store first even in a pointer to be used later

our even wiil always be ahead of odd so we will apply while conditions on even only
*/

ListNode* OPTIMAL(ListNode*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    ListNode*even=head->next;
    ListNode*odd=head;
    ListNode* even_first=head->next;//will be used later

    while(even!=NULL&&even->next!=NULL)
    {
       odd->next=odd->next->next;
       odd=odd->next;
       even->next=even->next->next;
       even=even->next;
    }
    odd->next=even_first;
    return head;
    
}
