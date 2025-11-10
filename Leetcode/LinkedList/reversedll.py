class Solution:
    def reverseDLL(self, head):
        temp = head
        prev = None

        while temp:
       
            temp.prev, temp.next = temp.next, temp.prev
      
            prev = temp
            temp = temp.prev  
        
        return prev
