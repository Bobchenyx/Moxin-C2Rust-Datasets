class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.val = []
        self.min_num = []
        

    def push(self, x: int) -> None:
        self.val.append(x)
        if self.min_num == []:
            self.min_num.append(x)
        else:
            if x < self.min_num[-1]:
                self.min_num.append(x)
            else:
                self.min_num.append(self.min_num[-1])
        

    def pop(self) -> None:
        self.val.pop()
        self.min_num.pop()


    def top(self) -> int:
        return self.val[-1]
        

    def getMin(self) -> int:
        return self.min_num[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()