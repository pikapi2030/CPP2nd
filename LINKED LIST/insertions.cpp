#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int k, Node *address)
    {
        data = k;
        next = address;
    }

};

// WAP to inset k element before head(T.C O(1))
//we will create a new node with its next address as address of head,data as k, and return it
Node* InsertHead(Node*head,int k)
{
return new Node(k,head);
}

//WAP to inset K element after tail
// we will reach at last element(by temp), and creat a new node pointing to null,temp->next=newnode

Node* InsertTail(Node*head,int k)
{
    if(head==NULL)//list is empty
    {
        return new Node(k,NULL);
    }
    Node*temp=head;
    while(temp->next!=NULL)//to reach last element
    {
     temp=temp->next;
    }
    //temp at last element
    temp->next=new Node(k,NULL);//last element's next points to the new node created(which point to NULL)
    return head;
}
 
//WAP to insert and elemet(EL) at kth node( before kth node )
/*
to insert a new node before k, we need out temp previous to kth node,
then we will create a new node pointing to the kth node,
then will will link temp node to the newly created node

NOTE: if we link temp to newly created node first, we would lose the address of the KTH node
, and there will be no way to link newly formed
node to the kth node
so fist we have to link new node to kth node

EDGE CASES
if list is empty :-
if list is empty, and k==1 then we can create new node, if k>1,it is invalid

if k==1(create head)
*/

Node* InsertNode(Node* head,int EL,int k)
{
if(head==NULL)//empty ll
{
    if(k==1)//only valid case for empty ll
    {
        return new Node(EL,NULL);
    }
    else
    {
        cout<<"INVALID K";
        return NULL;
    }
}
if(k==1)
{
    return new Node(EL,head);
}    
int cnt=0;
Node*temp=head;
while(temp!=NULL)
{
    cnt++;
    if(cnt==(k-1))//temp is previous to kth node
    {
        Node*new_node= new Node(EL,temp->next);
        temp->next=new_node;
        break;
    }
    temp->next=temp;
}
return head;
}

//WAP to insert and element (EL) before given value(K)(insertion by value)

Node*InsertBeforeValue(Node* head,int EL,int k)
{
    if(head==NULL)//no value to insert before
{
    cout<<"invalid case";
    return NULL;
}
if(head->data==k)//insert before k
{
    return new Node(EL,head);
}    
Node*temp=head;
while(temp!=NULL)
{
    if(temp->next->data==k)//temp is at node previous to node having data=k
    {
        Node*new_node= new Node(EL,temp->next);
        temp->next=new_node;
        break;
    }
    temp->next=temp;
}
return head;

}
