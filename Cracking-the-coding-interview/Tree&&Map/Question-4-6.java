class TreeNode {
    public int val;
    public TreeNode left, right, parent;
    public TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

public class CareerUp {
    public TreeNode leftMostChile(TreeNode n) {
        if (n == null) return null;
        while (n.left != null) {
            n = n.left;
        }
        return n;
    }
    public TreeNode inorderSucc(TreeNode n) {
        if (n == null) return null;
        if (n.right != null) {
            return leftMostChile(n.right);
        } else {
            TreeNode q = n;
            TreeNode x = q.parent;
            while (x != null && x.left != q) {
                q = x;
                x = x.parent;
            }
            return x;
        }
    }
}