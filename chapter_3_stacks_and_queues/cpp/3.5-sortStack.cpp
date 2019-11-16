#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int> *s1)
{
    stack<int> s2;
    int temp;

    while (!s1->empty())
    {
        temp = s1->top();
        s1->pop();
        while (!s2.empty() && temp < s2.top())
        {
            s1->push(s2.top());
            s2.pop();
        }
        s2.push(temp);
    }
    while (!s2.empty())
    {
        s1->push(s2.top());
        s2.pop();
    }
}

int main()
{
    stack<int> *s = new stack<int>;
    int arr[] = {4, 5, 2, 8, 1, 9, 6, 7, 3, 0};

    for (auto i : arr)
        s->push(i);
    sortStack(s);
    while (!s->empty())
    {
        cout << s->top() << " ";
        s->pop();
    }
    /* 0 1 2 3 4 5 6 7 8 9 */

    return 0;
}