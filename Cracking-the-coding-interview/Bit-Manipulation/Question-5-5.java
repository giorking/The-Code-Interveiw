public class CareerUp {
    public int bitSwapRequired(int a, int b) {
        int count = 0, res = a ^ b;
        while (res != 0) {
            res = res & (res - 1);
            count ++;
        }
        return count;
    }
}
