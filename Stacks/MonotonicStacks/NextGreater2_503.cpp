#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
}

/*
Find next greater of each element in vector and return thres vector, but array is circular
*/

/*BRUTE
iterate to every element,find it's next greater

index=(j)%size

//!Time Complexity: O(n^2)
//!S.C O(N)
*/

vector<int> BRUTE(vector<int> v)
{
    int n = v.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = i + 1; j < i + n; j++)
        {

            int index = j % n;
            if (v[index] > v[i])
            {
                ans.push_back(v[index]);
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            ans.push_back(-1);
        }
    }
    return ans;
}

/*OPTIMAL
we will use monotonic stack travesal like in gerater element 1,
to implement circular concept we have to asume an hyypothetical copy array ahead of our
oringnal array, we will travese that copy then our orignal(will feel like circular traversal)

basically we have to do reverse traversal two times while using same stack

//!T.C O(4N)
//!S.C O(N)+O(2N)
*/

vector<int> OPTIMAL(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n,0);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int index = i % n;
        while (!st.empty() && v[index] >= st.top())
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[index]=-1;
        }
        else
        {
            ans[index]=st.top();
        }
        st.push(v[index]);
    }
    return ans;
}

int main()
{
    vector<int> v;
    v = {1, 2, 1};
    printv(OPTIMAL(v));
}