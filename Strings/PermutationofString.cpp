#include<iostream>
#include<vector>
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

    int freq1[26] = {0};
    int freq2[26] = {0};

    // Frequency of s1
    for(int i = 0; i < s1.length(); i++) {
        freq1[s1[i] - 'a']++;
    }

    int windowSize = s1.length();

    // Frequency of first window in s2
    for(int i = 0; i < windowSize; i++) {
        freq2[s2[i] - 'a']++;
    }

    if(checkEqual(freq1, freq2))
        return true;

    // Sliding Window
    for(int i = windowSize; i < s2.length(); i++) {

        // Add incoming character
        freq2[s2[i] - 'a']++;

        // Remove outgoing character
        freq2[s2[i - windowSize] - 'a']--;

        if(checkEqual(freq1, freq2))
            return true;
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