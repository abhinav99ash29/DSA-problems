class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int tot = 0;
        for(int i=0;i<n;i++) {
            if (i+1<n && s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X')) {
                tot-=1;
                i++;
            }
            if (i+1<n && s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C')) {
                tot-=10;
                i++;
            }
            if (i+1<n && s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M')) {
                tot-=100;
                i++;
            }
            
            if (s[i]=='I') tot+=1;
            else if(s[i]=='V') tot+=5;
            else if(s[i]=='X') tot+=10;
            else if(s[i]=='L') tot+=50;
            else if(s[i]=='C') tot+=100;
            else if(s[i]=='D') tot+=500;
            else if(s[i]=='M') tot+=1000;
        }
        return tot;
        
    }
};
