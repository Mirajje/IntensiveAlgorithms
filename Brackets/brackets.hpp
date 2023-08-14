class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char, char> map = 
        {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        stack<char> stack;
        for (auto el : s)
            if (!stack.empty() && stack.top() == map[el])
                stack.pop();
            else
                stack.push(el);
        
        return (stack.empty());
    }
};
