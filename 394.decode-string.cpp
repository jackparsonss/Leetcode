/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(string &s, int &i) {
        string out;
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i])) {
                out += s[i];
                i++;
                continue;
            }

            int n = 0;
            while(i < s.size() && isdigit(s[i])) {
                n = n * 10 + s[i] - '0';
                i++;
            }

            i++;
            string str = decode(s, i);
            i++;

            while(n-- > 0) {
                out += str;
            }
        }
        return out;
    }
};
// @lc code=end


        // int idx = 0;
        // while(s[idx] && isdigit(s[idx])) {
        //     string curr_num, curr_out;
        //     while(s[idx] != '[') {
        //         curr_num += s[idx];
        //         idx++;
        //     }
        //     idx++;

        //     while(s[idx] != ']') {
        //         curr_out += s[idx];
        //         idx++;
        //     }
        //     idx++;

        //     for(int i = 0; i < stoi(curr_num); i++) {
        //         output += curr_out;
        //     }
        // }

        // while(s[idx]) {
        //     output += s[idx];
        //     idx++;
        // }