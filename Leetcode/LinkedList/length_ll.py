class Solution:
    def getLength(self, head):
        # Your code goes here
        count=1
        temp=head
        while(temp.next!=None):
            count=count+1
            temp=temp.next
        
        return count