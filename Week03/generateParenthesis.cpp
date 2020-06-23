¡¢class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
          generate(0,0,n,"");
          return result;
    }

    void generate(int left,int right,int n,string str) {
        //terminator
        if(left == n && right == n) {
             //process result
            result.push_back(str);
            return;
        }
         //process current logic

         //drill down

        if(left < n) {
            generate(left+1,right,n,str + "(");
        }
        if(left > right) {
            generate(left,right + 1,n,str + ")");
        }
        // restore current status
    }
};