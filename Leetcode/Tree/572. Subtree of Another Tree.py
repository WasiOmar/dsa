class Solution:
    def issame(self, p, q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        return self.issame(p.left, q.left) and self.issame(p.right, q.right)

    def isSubtree(self, root, subroot):
        if not root:
            return False
        if self.issame(root, subroot):
            return True
        return self.isSubtree(root.left, subroot) or self.isSubtree(root.right, subroot)
