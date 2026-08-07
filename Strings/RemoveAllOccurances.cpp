#include <iostream>
#include <string>
using namespace std;

string RemoveOccurrences(string s, string part) {

    while(s.length() > 0 && s.find(part) != string::npos) {

        int idx = s.find(part);

        s.erase(idx, part.length());
    }

    return s;
}

int main() {

    string s, part;

    cout << "Enter String: ";
    cin >> s;

    cout << "Enter Part to Remove: ";
    cin >> part;

    cout << "Final String: " << RemoveOccurrences(s, part) << endl;

    return 0;
}