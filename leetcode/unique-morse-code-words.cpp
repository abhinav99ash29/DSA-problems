class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string, int> mp;
        for(auto& s: words) {
            string tfn="";
            for(auto& c: s) {
                tfn+=morse[c-'a'];
            }
            mp[tfn]++;
        }
        return mp.size();
    }
};
