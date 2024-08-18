#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;
};


/*
WAP a program to reverse a LL
*/

/*BRUTE
using stack, we can traverse LL and stores its data in stack,
 then we can again traverse LL to modify the data, due LIFO of stack it will be easier to reverse
T.C O(N)+O(N)
S.C O(N)
*/

Node*BRUTE(Node*head)
{
stack<int> st;
Node*temp=head;
while(temp!=NULL)
{
    st.push(temp->data);
    temp=temp->next;
}
temp=head;
while(temp!=NULL)
{
    temp->data=st.top();
    st.pop();
}
return head;


}

/*BETTER
instead of changing the data we can reverse the links(to avoid using extra space)

to do this we traverse using temp, maintaining a prev and a front, prev initialised to NULL
front is ahead of temp, prvent losing of front node after revesing the link
we set temp's next to prev, then move temp to front, and front one node ahead 

at the end aour prev will be acting as head
T.C O(N)
S.C O(1)
*/
Node*OPTIMAL(Node*head)
{
    Node*temp=head;
    Node*prev=NULL;
    Node*front;
    while(temp!=NULL)
    {
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}




