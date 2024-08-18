#include <stack>
#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
};

/*
check if L list is palindrome or not
*/

/*BRUTE
using stack, we store all the data of ll in stack, then again traverse LL and check if
stack is same as ll if yes it is a palindrome

T.C O(2N)
S.C O(N)
*/

bool BRUTE(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
/*OPTIMAL
we reach the middle of the LL and reverse the second half, if second half is equal to
first half it is a palindrome

T.C O(n/2+n/2+n/2)
T.C can be O(n/2+n/2+n/2+n/2) if we reverse LL again(so not alter out ll)

POINTS TO NOTE:
when finding middle using tortoise and hare, we get the second middle in case of
even and middle in case of odd, we want to reverse all nodes ahead of middle
(in case of odd) and ahead of first middle(in case of even)
(BUT WE GET SECOND MIDDLE FROM TORTOISE AND HARE)

so we modify our middle function such that it returns first middle in case of even
and middle in case of odd so that we can return slow->next from middle
func to reverse func as head, then reverse func will reverse from
our desired position(ahead of middle and first middle(for even))

for that, we stop fast at second last node to get first middle(even case)
and stop fast at last node to get middle(odd case)

after reversing, we return prev from reverse func as the head to be stored in a temp2
pointer

BUT WHY WE NEED TO REVERSE AFTER FIRST MIDDLE?

to make  sure that our temp2 to pointer will always reach NULL first(odd case)
or at same time(even case) than our temp(pointing at head)
pointer(there us NULL present from where LL was reversed)
so we can use condition while(temp2!=NULL) to traverse and check for palindrome

*/
ListNode *reverse(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    ListNode *front;
    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && (fast->next->next) != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->next; // we will reverse smaller half in case of odd
}

bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    ListNode *temp = head;
    ListNode *temp2 = reverse(middle(head));
    while (temp2 != NULL)
    {
        if (temp2->data != temp->data)
        {
            return false;
        }
        temp2 = temp2->next;
        temp = temp->next;
    }
    return true;
}
