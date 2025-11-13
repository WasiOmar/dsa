# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        temp=head
        count=0
        while(temp):
            count=count+1
            temp=temp.next
        
        position=count+1-n
        print(position)
        count=0
        temp=head
        prev=None
        while(temp):
            count=count+1
            if (count==position):
                break;
            prev=temp
            temp=temp.next
        if(prev):
            prev.next=temp.next
        else:
            return head.next

        return head

        