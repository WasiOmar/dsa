# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        slow=head
        fast=head
        while(fast and fast.next):
            fast=fast.next.next
            slow=slow.next
            if(fast==slow):
                slow=head
                while(fast!=slow):
                    fast=fast.next
                    slow=slow.next
                return slow
                
        return None
        