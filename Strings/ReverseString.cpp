#include <iostream>
using namespace std;

void ReverseString(string &str) {

    int st = 0;
    int end = str.length() - 1;

    while(st < end) {
        swap(str[st], str[end]);
        st++;
        end--;
    }
}

int main() {

    string str;
    cout << "Enter String: ";
    cin >> str;

    ReverseString(str);

    cout << "Reversed String: " << str << endl;

    return 0;
}