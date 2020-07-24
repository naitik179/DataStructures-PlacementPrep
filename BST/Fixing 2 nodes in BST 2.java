class Solution {
    public void recoverTree(TreeNode root) {
        inOrder(root);
        if (swaps[0] != null && swaps[1] != null) {
            int tmp = swaps[0].val;
            swaps[0].val = swaps[1].val;
            swaps[1].val = tmp;
        }
    }

    TreeNode cur;
    TreeNode[] swaps = new TreeNode[2]; 
    private void inOrder(TreeNode node) {
        if (null == node) {
            return;
        }

        inOrder(node.left);
        if (cur != null && cur.val > node.val) {
          /** first met, shoule put both cur & node, because maybe this two nodes will be swaped */
          if (swaps[0] == null) {
            swaps[0] = cur;
          }
          swaps[1] = node;
        }
        cur = node;
        inOrder(node.right);
    }
}