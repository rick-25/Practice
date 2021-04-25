package DataStructures;

public class TreeNode {
    public int val;
    public TreeNode left, right;

    public TreeNode(int val) {
        this.val = val;
        left = right = null;
    }

    public void printPreorder() {
        printPreorder(this);
    }

    private void printPreorder(TreeNode root) {
        if(root == null) {
            System.out.print(null+" ");
            return;
        }
        System.out.printf("%d ", root.val);
        printPreorder(root.left);
        printPreorder(root.right);
    }
    
    public String toString() {
        return Integer.toString(val);
    }
}
