class Solution {
    public:
        bool verifyExpression(string exp, int target)
        {
            long long result = 0;
            long long currentNumber = 0;
            long long lastOperand = 0;
            char lastOp = '+';
    
            for (int i = 0; i < exp.size(); i++)
            {
                if (isdigit(exp[i])) {
                    currentNumber = currentNumber * 10 + (exp[i] - '0');
                }
    
                if (!isdigit(exp[i]) || i == exp.size() - 1) {
                    if (lastOp == '+') {
                        result += lastOperand;
                        lastOperand = currentNumber;
                    } else if (lastOp == '-') {
                        result += lastOperand;
                        lastOperand = -currentNumber;
                    } else if (lastOp == '*') {
                        lastOperand *= currentNumber;
                    }
                    currentNumber = 0;
                    lastOp = exp[i];
                }
            }
    
            result += lastOperand;
            return result == target;
        }
    
        string removeLeadingZeros(string exp)
        {
            int n = exp.size();
            string result = "";
            int i = 0;
            
            // Remove leading zeros before numbers
            while (i < n && exp[i] == '0') {
                i++;
            }
    
            while (i < n) {
                result += exp[i++];
            }
    
            return result;
        }
    
        void generateExpression(string num, int idx, long long prevOperand, long long currentOperand, long long value, string exp, vector<string>& ans, int target) 
        {
            if (idx == num.size()) {
                if (value == target) {
                    ans.push_back(exp);
                }
                return;
            }
    
            for (int i = idx + 1; i <= num.size(); i++) {
                string currentNumStr = num.substr(idx, i - idx);
                if (currentNumStr.size() > 1 && currentNumStr[0] == '0') break;  // Skip numbers with leading zeros
                long long currentNum = stol(currentNumStr);
    
                if (idx == 0) { // First number, no operator needed
                    generateExpression(num, i, currentNum, currentNum, currentNum, currentNumStr, ans, target);
                } else {
                    generateExpression(num, i, currentNum, currentNum, value + currentNum, exp + "+" + currentNumStr, ans, target);
                    generateExpression(num, i, -currentNum, currentNum, value - currentNum, exp + "-" + currentNumStr, ans, target);
                    generateExpression(num, i, prevOperand * currentNum, currentNum, value - prevOperand + prevOperand * currentNum, exp + "*" + currentNumStr, ans, target);
                }
            }
        }
    
        vector<string> addOperators(string num, int target) 
        {
            vector<string> ans;
            if (num.empty()) return ans;
    
            generateExpression(num, 0, 0, 0, 0, "", ans, target);
            return ans;
        }
    };