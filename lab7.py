class CircularQueue:
    def __init__(self, size):
        self.data = [None] * size
        self.size = size
        self.start = size // 2
        self.end = size // 2 + 1


    def enqueue(self, item):
        if self.data[self.start] == None:
            self.data[self.start] = item
        else:
            self.data[self.end] = item
            if self.end + 1 == self.size:
                self.end = 0
            else:
                self.end += 1

    def dequeue(self):
        # return self.data.pop()
        ret_val = self.data[self.start]
        self.data[self.start] = None # O(n), because need to move self.data[1:] to self.data[0:]
        if self.start + 1 >= self.size:
            self.start = 0
        else:
            self.start += 1
        return ret_val

    def __str__(self):
        # res = ""
        # res += "index\t"
        # for i in range(self.size):
        #     res += f"{i}\t"
        # res += "\n"
        # for i in range(self.size):
        #     if(self.data[i] == None):
        #         res += "\t"
        #     else:
        #         res += f"{self.data[i]}\t"
        # res += "\n"
        # res += f"Begin at index: {self.start}\n"
        # res += f"End at index: {self.end}\n"
        # return res
        if(self.end >= self.start):
            self_size = self.end - self.start
        else:
            self_size = self.end + self.size - self.start
        ind = self.start
        res = ""
        for i in range(self_size-1):
            res += str(self.data[ind]) + "->"
            if ind + 1 >= self.size:
                ind = 0
            else:
                ind += 1
        res += str(self.data[ind])
        return res


    def __lt__(self, other):
        ind_self = self.start
        ind_other = other.start
        
        while(ind_self != self.end+1 or ind_other != other.end+1):
            if self.data[ind_self] != other.data[ind_other]:
                return self.data[ind_self] < other.data[ind_other]
            else:
                ind_self += 1
                ind_other += 1
                if ind_self >= self.size:
                    ind_self = 0
                if ind_other >= other.size:
                    ind_other = 0
        return True

my_queue = CircularQueue(10)
my_queue.enqueue(6)
print(my_queue)
my_queue.enqueue(2)
print(my_queue)
my_queue.enqueue(7)
print(my_queue)
my_queue.dequeue()
print(my_queue)