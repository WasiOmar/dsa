class Solution:
    def lowestCommonAncestor(self, root, p, q):
        it = root
        while it:
            if it.val > p.val and it.val > q.val:
                it = it.left
            elif it.val < p.val and it.val < q.val:
                it = it.right
            else:
                return it
