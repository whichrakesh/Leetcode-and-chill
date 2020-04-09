class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i1 = 0, i2 = 0;
          for(int i=0; i<S.length(); i++){
             if(S[i] == '#'){
                 if(i1 > 0){
                    i1--;    
                 }
                 
             } else {
                S[i1] = S[i];   
                 i1++;
             }
          }
          for(int i=0; i<T.length(); i++){
             if(T[i] == '#'){
                 if(i2 > 0){
                  i2--;   
                 }
             } else {
                T[i2] = T[i];
                 i2++;
             }
          }
          return (i1 == i2 && S.substr(0, i1) == T.substr(0, i2));
    }
};