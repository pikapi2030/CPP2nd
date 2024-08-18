#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next; // stores address of the next ListNode, so is of ListNode* data type(JESE INT KE ADDRESS KO STORE KARANE KE LIYE INT * CHAIYE)

    ListNode(int data1)
    {
        data = data1;
        next = NULL; // newly formed ListNodes do not have any ListNode next to them so they store NULL
    }
};
ListNode *ArrayToLL(vector<int> v)
{
    ListNode *head = new ListNode(v[0]); // creating a new ListNode(by DMA, using parametrised constructor)
    // v[0] is stored as data, next is NULL(due to constructor)
    ListNode *mover = head;
    // loop to create more ListNodes
    for (int i = 1; i < v.size(); i++) // starting from 1 as ListNode of v[0] is already created
    {
        ListNode *temp = new ListNode(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; // we address of head we can do various tasks in LL
}
int LenghtOfLL(ListNode *head)
{
    ListNode *temp = head; // DO NOT TAMPER HEAD
    int cnt = 0;
    while (temp) // will stop when temp==NULL
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void displayArrByLL(ListNode *head)
{
    ListNode *temp = head; // DO NOT TAMPER HEAD

    while (temp) // will stop when temp==NULL
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// WAP to delete head of a linked list, return the new head

/*
to delete a head, we can technicaly move our head pointer to next ListNode
we can use temp to point it to current head then move head,
then use delete operator to delete temp

cpp does not have garbage collector, so we have to manally create temp
and delete it to actually free the memory used by previous ListNode(head ListNode)
*/

ListNode *HeadRemove(ListNode *head)
{
    if (head == NULL) // empety LL, can't do anything on it
    {
        return head;
    }
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// WAP TO DELETE TAIL OF LL (THE LAST ListNode)

/*
to delete a tail, we will delete temp pointing to it and then
change the stored address of second last ListNode to null

we are on second last ListNode if temp->next->next==NULL

{

NOTE:temp->next->next means (temp->next) ->next

lets say be have a LL: A-B-C-D-E (alphabets represent ListNodes)

if out temp point to A, temp->next will be address of B,
and (temp->next)->next will mean  (address of B)->next which
means returning next sotred in C, so we are on A(our temp)
still we can access C's stored next
when temp->next->next==NULL means we are on D
(it gives E's stored next which is NULL)

}

*/
ListNode *TailRemove(ListNode *head)
{
    if (head == NULL || head->next == NULL) // if no element or only one element present
    {
        return NULL;
    }
    ListNode *temp = head;
    while (temp->next->next != NULL) // if temp does not point to second last, keep moving
    {
        temp = temp->next;
    }
    // temp reached second last
    delete temp->next; // element next to second last(last) is deleted
    temp->next = NULL; // second last points to NULL
    return head;
}

// WAP TO delete kth ListNode of LL

/*
There are three 4 cases
1st :- if k=1 it is same as delete head of ll
2nd :- if k= last element, same as delete tail
3rd :- k= is between 1 nad last (genral case)
4th :- k is greater than the nuber of ListNodes present, no changes to be made
5th :- ll is empty

For case 3rd
do delete kth ListNode, we have to change next of previous ListNode and make it point to
the next(after the kth ListNode)
we also have to free the mem of kth ListNode
so check if we are on kth ListNode or not we keep a cnt, a temp and a previous
temp traverses the ll, prev stores next of ListNode before temp(will be needed)

2nd (tail case),and 4th comes inside the general case

T.C O(K)
*/

ListNode *KthListNodeDelete(ListNode *head, int k)
{
    if (head == NULL)
    {
        return head; // Return if the list is empty
    }

    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next; // Move head to the next ListNode
        delete temp;       // Delete the original head
        return head;       // Return the updated head
    }

    ListNode *temp = head;
    ListNode *prev = NULL;
    int cnt = 1;

    while (temp != NULL && cnt < k)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp != NULL)
    {                            // Ensure k is within the bounds of the list
        prev->next = temp->next; // Skip the k-th ListNode
        delete temp;             // Delete the k-th ListNode
    }

    return head;
}
