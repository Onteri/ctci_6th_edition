#include <iostream>
#include <stack>

using namespace std;

/* first in, first out*/
class MyQueue
{
public:
    stack<int> newest;
    stack<int> oldest;

    MyQueue(){};
    void enqueue(int value);
    void shiftStacks();
    int dequeue();
    int peek();
};

void MyQueue::enqueue(int value)
{
    this->newest.push(value);
}

void MyQueue::shiftStacks()
{
    /* If oldest is empty, push everything from newest to oldest */
    if (this->oldest.empty())
        while (!this->newest.empty())
        {
            this->oldest.push(this->newest.top());
            this->newest.pop();
        }
}

int MyQueue::dequeue()
{
    int value;

    this->shiftStacks();
    value = this->oldest.top();
    this->oldest.pop();
    return value;
}

int MyQueue::peek()
{
    this->shiftStacks();
    return this->oldest.top();
}

int main()
{
    MyQueue mq;
    int arr[] = {1, 2, 3, 4, 5};

    for (auto i : arr)
        mq.enqueue(i);
    cout << mq.dequeue() << endl; // 1
    cout << mq.peek() << endl;    // 2

    return 0;
}