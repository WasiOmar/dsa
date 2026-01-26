class Solution:
    def goodNodes(self, root) :
        def dfs(node, maxval):
            if not node:
                return 0

            good = 1 if node.val >= maxval else 0
            maxval = max(maxval, node.val)

            return good + dfs(node.left, maxval) + dfs(node.right, maxval)

        return dfs(root, root.val)
