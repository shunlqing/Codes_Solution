/**
 * "I am a student!" --> "student a am I"
*/


#include <iostream>
using namespace std;

void reverse(string& str, int first, int last)
{
    while(first < last) {
        char tmp = str[first];
        str[first] = str[last];
        str[last] = tmp;
        first++;
        last--;
    }
}

//以单词为单位，做翻转
// 如： “I am a struent” --> "student a am I"
void reverseString(string& str) {
    if(str.size() == 0) {
        return;
    }
    
    reverse(str, 0, str.size()-1);
    int first = -1;
    int last = -1;
    for(int i = 0; i < str.size(); i++) {
        first = first != -1 ? first : (((i == 0) || (str[i-1] == ' ')) ? i : -1); //如果first已经不是-1，不能改变
        last = last != -1 ? last : (((i == str.size()-1) || (str[i+1] == ' ')) ? i : -1);
        if(first != -1 && last != -1) {
            reverse(str, first, last);
            first = -1;
            last = -1;
        }
    }

}

//翻转指定位数
// 如 “ABCDE”, 3 --> "DEABC"

void reverseString(string& str, int size)
{
    if(str.size() == 0 || size > str.size())
        return;
    
    reverse(str, 0, size-1);
    reverse(str, size, str.size()-1);
    reverse(str, 0, str.size() - 1);
}
 
int main()
{
    string s = "long ba tian xia";
    reverseString(s);
    
    string s1 = "ABCDE";
    reverseString(s1, 3);
    cout << s << endl;
    cout << s1 << endl;
}
