# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        c=None
        a=head
        while(a!=None):
            b=a.next
            a.next=c
            c=a
            a=b
        return c
        