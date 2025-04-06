class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int maxfreq = 0;
        int hash[26] = {0};
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            hash[s[right] - 'A']++;
            maxfreq = max(maxfreq, hash[s[right] - 'A']);

            int len = right - left + 1;
            int changes  = len - maxfreq;

            if (changes > k) {
                hash[s[left] - 'A']--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
