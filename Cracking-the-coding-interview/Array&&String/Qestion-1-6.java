public class CareerUp{
    public void rotate(int[][] matrix, int n) {
        for (int layer = 0; layer < n / 2; ++ layer) {
            int first = layer;
            int last = n - 1 - layer;
            for (int i = first; i < last; ++ i) {
                int offset = i - first;
                //store the up
                int top = matrix[first][i];
                //left to up
                matrix[first][i] = matrix[last - offset][first];
                //down to left
                matrix[last - offset][first] = matrix[last][last - offset];
                //right to down
                matrix[last][last - offset] = matrix[i][first];
                //up tp right
                matrix[i][last] = top;
            }
        }
    }
}