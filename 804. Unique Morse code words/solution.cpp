class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> st;
        for(auto str:words)
        {
            string gen;
            for(auto x:str)
            {
                gen = gen+morse[x-'a'];
            }
            st.insert(gen);
        }

        return st.size();
    }
};

