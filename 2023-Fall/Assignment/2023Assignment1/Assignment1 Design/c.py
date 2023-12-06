import string

# 初始化一个字典，用于存放字母和其出现的次数
letter_count = dict.fromkeys(string.ascii_lowercase, 0)

# 打开文件并读取内容
with open('a.txt', 'r') as file:
    for line in file:
        # 将每一行的字母转换为小写
        line = line.lower()
        # 遍历每一行中的每个字符
        for char in line:
            # 如果字符是一个字母，就在字典中对应的计数上加一
            if char in letter_count:
                letter_count[char] += 1

# 计算频率并打印结果
# for letter, count in sorted(letter_count.items()):
#     frequency = count
#     print(f'{letter}: {frequency}')
print(letter_count)
import heapq
from collections import defaultdict

def encode(frequency):
    heap = [[weight, [symbol, ""]] for symbol, weight in frequency.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    return sorted(heapq.heappop(heap)[1:], key=lambda p: (len(p[-1]), p))

huff = encode(letter_count)
print("Symbol".ljust(10) + "Weight".ljust(10) + "Huffman Code")
for p in huff:
    print(p[0].ljust(10) + str(letter_count[p[0]]).ljust(10) + p[1])