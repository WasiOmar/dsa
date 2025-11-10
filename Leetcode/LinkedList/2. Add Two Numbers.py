class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        current = ListNode(0)
        head= current

        while l1 or l2 or carry:
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0

            total = l1val + l2val + carry
            carry = total // 10
            value = total % 10

            current.next = ListNode(value)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return head.next
