class Solution {
public:
    string makeGood(string s) {
        int n=s.size();stack<char> st;
    
for(int i=0;i<n;i++){
    
   if(!st.empty()){
       
       if(isupper(st.top()) and islower(s[i]) and st.top()==toupper(s[i])){
           st.pop();
       }
       
       else if(islower(st.top()) and isupper(s[i]) and st.top()==tolower(s[i])){
           st.pop();
       }
       
       else{
           st.push(s[i]);
       }
       
   }
    
   else{
       st.push(s[i]);
   }        
       
  }
    
string ans="";
    
while(!st.empty()){
    
  ans+=st.top();
  st.pop();       
    
} 
    
 reverse(ans.begin(),ans.end());
    
    return ans;
    
}
    }
};