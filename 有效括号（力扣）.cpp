class Solution {
public:
    bool isValid(string s) {
        char *zhan;
        if(s.size()%2!=0) return false;
        zhan = (char*)malloc(s.size());
        int j = 0;
        for(unsigned int i = 0; i < s.size(); i++)
        {
            if(s[i]!=' ')
            {
                zhan[j] = s[i];
                if(j!=0)
                {
                    if(zhan[j-1] == '(' && zhan[j] == ')')
                        j--;
                    else if(zhan[j-1] == '[' && zhan[j] == ']')
                        j--;
                    else if(zhan[j-1] == '{' && zhan[j] == '}')
                        j--;
                    else
                        j++;
                }
                else
                    j++;
            }
        }
        if(j == 0)
            return true;
        else
            return false;
    }
};