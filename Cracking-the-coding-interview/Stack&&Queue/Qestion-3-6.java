public class CareerUp {
    public static Stack<Integer> sort(Stack<Integer> stk) {
        Stack<Integer> cur = new Stack<Integer>();
        while (!stk.isEmpty()) {
            int temp = stk.pop();
            while (!cur.isEmpty() || cur.peek() > temp) {
                stk.push(cur.pop());
            }
            cur.push(temp);
        }
        return cur;
    }
}