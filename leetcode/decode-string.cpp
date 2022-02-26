class Solution {
public:
    string decodeString(string s, string sofar = "") {
        if (s.size()==0) return "";
        if (s.find("[") == string::npos) return s;
        int i = 0;
        
        int reps = 0;
        
        while(s[i]>='a'&&s[i]<='z') { // add all preceding characters
            sofar+=s[i];
            i++;
        }
        
        while(s[i]>='0'&&s[i]<='9') { // check the repetitions required
            reps = s[i]-'0'+reps*10;
            i++;
        }
        int j = i;
        int bracketsCnt = 0; // to find the actual closing bracket instead of intermediate
        if (s[j] == '[') {
            bracketsCnt=1;
            j++;
        }
        
        while(bracketsCnt != 0) {
            if (s[j]=='[') bracketsCnt++;
            if (s[j]==']') bracketsCnt--;
            j++;   
        }
        j--; // getting back to the last closing bracket
        
        for(int k=0;k<reps;k++) {
            sofar+=decodeString(s.substr(i+1,j-i-1),"");
        }
        i=j+1;
        
        return sofar + (i<s.size() ? decodeString(s.substr(i,s.size()-i+1),"") : "");
        
    }
};
