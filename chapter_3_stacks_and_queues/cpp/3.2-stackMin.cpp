#include <iostream>
#include <limits>
#include <stack>

using namespace std;

class StackWithMin
{
public:
    stack<int> s1;
    stack<int> s2;

    StackWithMin(){};
    void push(int value);
    int pop();
    int min();
};

void StackWithMin::push(int value)
{
    if (value < this->min())
        s2.push(value);
    s1.push(value);
}

int StackWithMin::pop()
{
    int value;

    value = s1.top();
    if (value == this->min())
        s2.pop();
    s1.pop();
    return value;
}

int StackWithMin::min()
{
    if (s2.empty())
        return INT32_MAX;
    return s2.top();
}

int main()
{
    StackWithMin swm;
    swm.push(1);
    swm.push(-5);
    swm.push(10);
    cout << swm.min() << endl; // -5
    swm.push(-10);
    cout << swm.min() << endl; // -10
    cout << swm.pop() << endl; // -10
    cout << swm.min() << endl; // -5
    return 0;
}