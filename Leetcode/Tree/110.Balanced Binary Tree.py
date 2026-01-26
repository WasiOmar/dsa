# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def isBalancedhelper(self, root: Optional[TreeNode]) -> bool:
        if(root==None):
            return (0,True)
        
        (leftheight,flagl)=self.isBalancedhelper(root.left)
        (rightheight,flagr)=self.isBalancedhelper(root.right)
        
        if(abs(leftheight-rightheight)<=1):
            if(flagl and flagr ):
                return (1+max(leftheight,rightheight),True)
            else:
                return (1+max(leftheight,rightheight),False)
        
        else:
            return (1+max(leftheight,rightheight),False)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.isBalancedhelper(root)[1]

        


        
        