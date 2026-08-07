#include<iostream>
#include<vector>
using namespace std;

int CompressString(vector<char>&chars) {

    int n = chars.size();
    int idx = 0;
    int i=0;

    while(i<n) {
        char ch = chars[i];
        int count = 0;

        while(i<n && chars[i]==ch) {
            count++;
            i++;
        }

        chars[idx++] = ch;

        if(count>1) {
            string str = to_string(count);

            for(auto dig:str) {
                chars[idx++] = dig;
            }
        }
    }

    return idx;
}

int main() {

    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = CompressString(chars);
    chars.resize(len);

    cout << "Compressed String: ";

    for(int i = 0; i < len; i++) {
        cout << chars[i];
    }

    return 0;
}