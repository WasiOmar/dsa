# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        fast=head
        for i in range(0,n):
            fast=fast.next
        slow=head
        prev=None
        while(fast):
            prev=slow
            slow=slow.next
            fast=fast.next
        if(prev):
            prev.next=slow.next
        else:
            return head.next
        return head

            