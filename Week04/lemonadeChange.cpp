class Solution {
public:
    int haveFive = 0;
    int haveTen = 0;
    
    bool lemonadeChange (vector<int>& bills) {
        for (const auto& bill : bills) {
            if (bill == 5) {
                haveFive++;    
            }
            else if (bill == 10) {
                bool ret = isJudge(10);
                if(ret == false) {
                    return false;
                }
                haveTen++;
            }
            else if (bill == 20) {
                bool ret = isJudge(20);
                if(ret == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isJudge(int bill) {
        if(bill == 10) {
            if(haveFive == 0) {
                return false;
            }
            haveFive--;
            return true;
        }
        else if(bill == 20) {
            if (haveFive >=1 && haveTen >= 1) {
                haveFive = haveFive -1;
                haveTen = haveTen -1;
                return true;
            }
            else if (haveFive >=3 && haveTen < 1) {
                haveFive = haveFive - 3;
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
};