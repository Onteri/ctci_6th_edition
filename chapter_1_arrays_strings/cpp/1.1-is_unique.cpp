#include <iostream>
#include <string>

using namespace std;

/* O(n) solution */
bool is_unique(string str)
{
    const int ASCII_LENGTH = 128;
    int map[ASCII_LENGTH] = {0};

    for (auto ch : str)
    {
        if (map[ch] == 1)
            return false;
        map[ch] = 1;
    }
    return true;
}

// bit vector solution, will only work for a-z chars
bool is_unique_alpha(string str)
{
    unsigned int bit_map = 0;
    int val;

    for (auto ch : str)
    {
        val = ch - 'a';
        if ((bit_map & (1 << val)) > 0)
            return false;
        bit_map |= (1 << val);
    }
    return true;
}

int main()
{
    cout << is_unique("abcdef") << endl; // 1
    cout << is_unique("abcdea") << endl; // 0
    cout << is_unique("aa") << endl;     // 0
    cout << is_unique("a") << endl;      // 1
    cout << is_unique("abc123") << endl; // 1

    cout << is_unique_alpha("abcdef") << endl; // 1
    cout << is_unique_alpha("abcdea") << endl; // 0
    cout << is_unique_alpha("aa") << endl;     // 0
    cout << is_unique_alpha("a") << endl;      // 1
    cout << is_unique_alpha("") << endl;       // 1

    return 0;
}