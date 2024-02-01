class ListNode:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.nodeMap = {}
        self.capacity = capacity
        self.head = ListNode(0, 0)
        self.tail = ListNode(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def remove(self, node: ListNode):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.nodeMap.pop(node.key)

    def insertToHead(self, node: ListNode):
        self.head.next.prev = node
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        self.nodeMap[node.key] = node

    def get(self, key: int) -> int:
        if key not in self.nodeMap:
            return -1
        node = self.nodeMap[key]
        self.remove(node)
        self.insertToHead(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        newNode = ListNode(key, value)
        if key in self.nodeMap:
            oldNode = self.nodeMap.get(key)
            self.remove(oldNode)
        else:
            if len(self.nodeMap) >= self.capacity:
                tailNode = self.tail.prev
                self.remove(tailNode)
        self.insertToHead(newNode)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
