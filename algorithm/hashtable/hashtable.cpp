#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isanagram(string s, string t){
        int arr[26] = {0};
        for (int i = 0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }
        for (int i = 0; i<s.size(); i++){
            arr[t[i]-'a']--;
        }
        for (int i = 0; i<26; i++){
            if (arr[i] != 0) return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "anagram";
    string t = "tagaram";
    Solution sol;
    cout << "is anagram: " << sol.isanagram(s, t);

    return 0;
}
