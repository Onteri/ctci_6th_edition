#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_one_edit_replace(string str1, string str2)
{
    int differences = 0, i;

    for (i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i])
            differences++;
    return differences <= 1;
}

bool is_one_edit_insert(string str1, string str2)
{
    string short_str, long_str;
    int i, j, len1, len2;
    bool found_difference = false;

    len1 = str1.length();
    len2 = str2.length();
    short_str = (len1 > len2) ? str2 : str1;
    long_str = (len1 > len2) ? str1 : str2;
    for (i = 0, j = 0; i < short_str.length(); i++, j++)
        if (short_str[i] != long_str[j])
        {
            if (found_difference)
                return false;
            found_difference = true;
            j++;
        }
    return true;
}

bool is_one_edit_away(string str1, string str2)
{
    int len1, len2;

    len1 = str1.length();
    len2 = str2.length();
    if (len1 == len2)
        return is_one_edit_replace(str1, str2);
    if (abs(len1 - len2) == 1)
        return is_one_edit_insert(str1, str2);
    return false;
}

int main(void)
{
    cout << is_one_edit_away("beal", "bal") << endl;     // 1
    cout << is_one_edit_away("val", "bal") << endl;      // 1
    cout << is_one_edit_away("val", "bale") << endl;     // 0
    cout << is_one_edit_away("mail", "mailman") << endl; // 0
    cout << is_one_edit_away("abc", "abcde") << endl;    // 0
    cout << is_one_edit_away("", "a") << endl;           // 1
    return 0;
}