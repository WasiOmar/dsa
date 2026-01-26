class MinStack:

    def __init__(self):
        self.store=[]

    def push(self, val: int) -> None:
        self.store.append(val)
        return None

    def pop(self) -> None:
        self.store.pop()
        return None

    def top(self) -> int:
        return self.store[-1]

    def getMin(self) -> int:
        mini=self.store[-1]
        for i in range(0,len(self.store)):
            mini=min(mini,self.store[i])
        
        return mini
