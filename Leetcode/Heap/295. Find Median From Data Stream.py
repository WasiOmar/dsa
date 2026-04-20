import heapq

class MedianFinder:

    def __init__(self):
        self.maxheap = []  # left side (max heap via negatives)
        self.minheap = []  # right side (min heap)

    def addNum(self, num: int) -> None:
        heapq.heappush(self.maxheap, -num)

        # ensure order property
        if self.minheap and (-self.maxheap[0] > self.minheap[0]):
            val = -heapq.heappop(self.maxheap)
            heapq.heappush(self.minheap, val)

        # balance sizes
        if len(self.maxheap) > len(self.minheap) + 1:
            val = -heapq.heappop(self.maxheap)
            heapq.heappush(self.minheap, val)

        if len(self.minheap) > len(self.maxheap) + 1:
            val = heapq.heappop(self.minheap)
            heapq.heappush(self.maxheap, -val)

    def findMedian(self) -> float:
        if len(self.maxheap) > len(self.minheap):
            return -self.maxheap[0]
        elif len(self.minheap) > len(self.maxheap):
            return self.minheap[0]
        return (-self.maxheap[0] + self.minheap[0]) / 2.0