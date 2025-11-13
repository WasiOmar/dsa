# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        dummy=ListNode(0)
        it=dummy
        while(list1 or list2):
            if(list1 and list2):
                if(list1.val<=list2.val):
                    it.next=ListNode(list1.val)
                    list1=list1.next
                else:
                    it.next=ListNode(list2.val)
                    list2=list2.next
            elif(not list1):
                it.next=ListNode(list2.val)
                list2=list2.next
            elif(not list2):
                it.next=ListNode(list1.val)
                list1=list1.next
            it=it.next
        
        return dummy.next
        