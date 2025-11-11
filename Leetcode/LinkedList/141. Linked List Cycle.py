# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        a=head
        while(a!=None):
            if(a.val=='visited'):
                return True
            a.val='visited'
            a=a.next
        return False
        