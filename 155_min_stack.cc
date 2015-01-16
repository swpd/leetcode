class MinStack {
public:
    void push(int x) {
        if (min_stk.empty() || x <= min_stk.top())
            min_stk.push(x);
        stk.push(x);
    }

    void pop() {
        if (stk.top() == min_stk.top())
            min_stk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
private:
    stack<int> stk;
    stack<int> min_stk;
};
