#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
};

/*
calculate the lenght of loop if present
*/

/*BRUTE
we use hashing, we keep track of visited nodes and a timer(step count)
if we find a visited node, we simply subract current timer by visited nodes timer to
get length

T.C O(N*2*LOGN)
*/
int BRUTE(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 1;
    map<ListNode *, int> mp;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return cnt - mp[temp];
        }
        mp[temp] = cnt;
        temp = temp->next;
        cnt++;
    }
    return 0; // no loop zero length
}

/*OPTIMAL
tortoise and hare
we detect the loop
at collison point we move slow pointer again, until it touches fast pointer
(fast pointer is not moved), the number of steps slow moves is the length of the loop)
*/

int OPTIMAL(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            int cnt = 0;
            do
            {
                slow = slow->next;
                cnt++;
                
            } while (slow != fast);
            return cnt;
        }
    }
    return 0;
}
