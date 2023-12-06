import heapq
from collections import defaultdict, Counter

# 定义哈夫曼树的节点类
class Node:
    def __init__(self, char, freq, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

# 生成哈夫曼编码
def encode(node, prefix="", code={}):
    if node is None:
        return {}

    if node.left is None and node.right is None:
        code[node.char] = prefix

    encode(node.left, prefix + "0", code)
    encode(node.right, prefix + "1", code)

    return code

# 读取文件并统计字母频率
with open('a.txt', 'r') as f:
    text = f.read().lower()
    counter = Counter(filter(str.isalpha, text))

# 创建优先队列
queue = [Node(char, freq) for char, freq in counter.items()]
heapq.heapify(queue)

# 构建哈夫曼树
while len(queue) > 1:
    left = heapq.heappop(queue)
    right = heapq.heappop(queue)
    heapq.heappush(queue, Node(None, left.freq + right.freq, left, right))

# 生成哈夫曼编码
huffman_code = encode(queue[0])

print(huffman_code)