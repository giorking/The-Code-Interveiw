public class MyQueue<T> {
    Stack<T> stk1, stk2;
    public MyQueue() {
        stk1 = new Stack<T>();
        stk2 = new Stack<T>();
    }
    public int size() {
        return stk1.size() + stk2.size();
    }
    public void add(T value) {
        stk1.push(value);
    }
    private void shiftStacks() {
        if (stk2.isEmpty()) {
            while (!stk1.isEmpty()) {
                stk2.push(stk1.pop());
            }
        }
    }
    public T peek() {
        shiftStacks();
        return stk2.peek();
    }
    public T remove() {
        shiftStacks();
        return stk2.pop();
    }
}