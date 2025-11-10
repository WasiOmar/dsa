class Node:
    def __init__(self,data):
        self.data=data
        self.next=None


class ll:
    def __init__(self):
        self.head=None
        self.tail=None
    
    def push_back(self, data):
        temp = Node(data)
        if self.head is None:
            self.head = temp
            self.tail = temp
        else:
            self.tail.next = temp
            self.tail = temp

    def printlist(self):
        temp = self.head
        while temp != None:
            print(f'{temp.data} ')
            temp = temp.next

    def delhead(self):
        temp=self.head
        self.head=self.head.next
        del temp
    def deltail(self):
        temp=self.head
        while(temp.next!=self.tail):
            temp=temp.next
        temp.next=None

    def insert(self,data,at):
        count=0
        temp=self.head
        val=Node(data)
        while((count+1)!=at):
            count=count+1
            temp=temp.next
        val.next=temp.next
        temp.next=val



ll1=ll()
ll1.push_back(2)
ll1.push_back(3)
ll1.push_back(2)
ll1.push_back(3)
ll1.insert(9,2)
ll1.printlist()