class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string firstWord = strs[0];
        for (int i = 0; i < firstWord.size(); i++) {
            char currentChar = firstWord[i];
            for (int j = 1; j < strs.size(); j++) {
                string currentWord = strs[j];
                if (i >= currentWord.size() || currentChar != currentWord[i]) {
                    return firstWord.substr(0, i);
                }
            }
        }
        return firstWord;
    }
};