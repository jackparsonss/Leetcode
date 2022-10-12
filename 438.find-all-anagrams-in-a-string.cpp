/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string p) {
        unordered_map<char, int> m;
        for(char c: s) {
            m[c]++;
        }
        for(char c: p) {
            m[c]--;
            if(m[c] == 0) {
                m.erase(c);
            }
        }
        for(auto [key, value]: m) {
            if(value != 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int sk = s.size();
        int pk = p.size();

        if(sk < pk) {
            return {};
        }

        vector<int> pfreq(26);
        vector<int> window(26);

        for(int i = 0; i < pk; i++) {
            pfreq[p[i]-'a']++;
            window[s[i]-'a']++;
        } 

        vector<int> out;
        if(pfreq == window) {
            out.push_back(0);
        }

        for (int i = pk; i < sk; i++){
            window[s[i-pk] - 'a']--;
            window[s[i] - 'a']++; 

            if(pfreq == window) {
                out.push_back(i-pk+1);
            }
        }

        return out;
    }
};
// @lc code=end

