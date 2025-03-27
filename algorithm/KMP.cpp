//  arr:   a b c a b c
// next:   0 0 0 1 2 3

class Solution {
public:
    void getNext(int* next, const string& s){
        next[0] = 0;
        int j = 0;
        for (int i=1; i<s.size(); i++){
            while(j>0 && s[i] != s[j]){ // keep roll back until find the same or j = 0
                j = next[j-1];
            }
            if (s[i] == s[j]){ // when s[i] == s[j] to end the above while or j = 0 already (start comparison from the head of arrau)
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;
        int next[s.size()];
        getNext(next, s);
        for (int i=0; i<s.size(); i++) std::cout << next[i] << " ";
        int len = s.size();
        if (next[len-1] != 0 && len%(len-(next[len-1]))==0) return true;
        return false;
    }
};