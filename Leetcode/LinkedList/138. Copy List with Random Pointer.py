# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return None

        # Hash map to store old node → new node mapping
        hash_table = {}

        # First pass: copy nodes and next pointers
        curr = head
        while curr:
            hash_table[curr] = Node(curr.val)
            curr = curr.next

        # Second pass: set next and random pointers
        curr = head
        while curr:
            if curr.next:
                hash_table[curr].next = hash_table[curr.next]
            if curr.random:
                hash_table[curr].random = hash_table[curr.random]
            curr = curr.next

        # Return the head of the copied list
        return hash_table[head]
