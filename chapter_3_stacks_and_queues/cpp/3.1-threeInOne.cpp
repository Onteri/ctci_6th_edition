#include <iostream>

using namespace std;

class FixedMultiStack
{
public:
  int numOfStacks = 3;
  int stackCapacity;
  int *values;
  int size;
  /* Array of sizes of sub-arrays */
  int sizes[3] = {0};

  FixedMultiStack(int stackSize);
  void printStack(int *arr, int len);
  void push(int stackNum, int value);
  int pop(int stackNum);
  int indexOfTop(int stackNum);
  bool isEmpty(int stackNum);
  bool isFull(int stackNum);
};

FixedMultiStack::FixedMultiStack(int stackSize)
{
  this->stackCapacity = stackSize;
  this->size = stackSize * this->numOfStacks;
  this->values = new int[size]{0};
};

void FixedMultiStack::printStack(int *arr, int len)
{
  int i;
  for (i = 0; i < len - 1; i++)
    cout << arr[i] << ", ";
  cout << arr[i] << endl;
}

void FixedMultiStack::push(int stackNum, int value)
{
  int index;

  if (stackNum < 0 || stackNum > 2)
    throw runtime_error("invalid index");
  if (this->isFull(stackNum))
    throw runtime_error("stack is full");
  this->sizes[stackNum]++;
  index = this->indexOfTop(stackNum);
  this->values[index] = value;
}

int FixedMultiStack::pop(int stackNum)
{
  int index, value;

  if (stackNum < 0 || stackNum > 2)
    throw runtime_error("invalid index");
  if (this->isEmpty(stackNum))
    throw runtime_error("stack is empty");
  index = this->indexOfTop(stackNum);
  value = this->values[index];
  this->values[index] = 0;
  this->sizes[stackNum]--;
  return value;
}

int FixedMultiStack::indexOfTop(int stackNum)
{
  int offset, index;

  offset = stackNum * this->stackCapacity;
  index = this->sizes[stackNum];
  return offset + index - 1;
}

bool FixedMultiStack::isEmpty(int stackNum)
{
  return this->sizes[stackNum] == 0;
}

bool FixedMultiStack::isFull(int stackNum)
{
  return this->sizes[stackNum] == this->stackCapacity;
}

int main()
{
  FixedMultiStack *fms;

  fms = new FixedMultiStack(4);
  fms->printStack(fms->values, fms->size);
  /* 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 */
  fms->printStack(fms->sizes, fms->numOfStacks);
  /* 0, 0, 0 */
  cout << fms->indexOfTop(0) << endl; // -1
  cout << fms->indexOfTop(1) << endl; // 3
  cout << fms->indexOfTop(2) << endl; // 7
  cout << fms->isEmpty(2) << endl;    // 1
  fms->push(1, 32);
  fms->push(1, 64);
  fms->push(1, 128);
  fms->push(1, 256);
  // fms->push(1, 256); exception
  cout << fms->isEmpty(1) << endl; // 0
  cout << fms->isFull(1) << endl;  // 1
  fms->printStack(fms->values, fms->size);
  /* 0, 0, 0, 0, 32, 64, 128, 256, 0, 0, 0, 0 */
  fms->printStack(fms->sizes, fms->numOfStacks);
  /* 0, 4, 0 */
  cout << fms->pop(1) << endl; // 256
  // fms->pop(2); exception
  fms->printStack(fms->values, fms->size);
  /* 0, 0, 0, 0, 32, 64, 128, 0, 0, 0, 0, 0 */
  fms->printStack(fms->sizes, fms->numOfStacks);
  /* 0, 3, 0 */

  delete fms->values;
  delete fms;
  return 0;
}