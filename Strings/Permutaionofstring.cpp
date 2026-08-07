#include <iostream>
#include <vector>
using namespace std;

bool checkEqual(int freq1[], int freq2[]) {
    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i])
            return false;
    }
    return true;
}

bool checkPermutation(string s1, string s2) {

    if(s1.length() > s2.length())
        return false;

    int freq[26] = {0};

    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    
    for(int i=0;i<s2.length();i++) {
        int windIdx = 0;
        int idx = i;

        int Windfreq[26] = {0};
        while(windIdx<windowSize && idx<s2.length()) {
            Windfreq[s2[idx]-'a']++;
            windIdx++;
            idx++;
        }

        if(checkEqual(freq, Windfreq)) {
            return true;
        }

    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if(checkPermutation(s1, s2))
        cout << "Permutation exists." << endl;
    else
        cout << "Permutation does not exist." << endl;

    return 0;
}