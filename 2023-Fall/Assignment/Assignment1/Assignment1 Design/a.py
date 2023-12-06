import string

# 初始化一个字典，用于存放字母和其出现的次数
letter_count = dict.fromkeys(string.ascii_lowercase, 0)

# 打开文件并读取内容
total_letters = 0
with open('a.txt', 'r') as file:
    for line in file:
        # 将每一行的字母转换为小写
        line = line.lower()
        # 遍历每一行中的每个字符
        for char in line:
            # 如果字符是一个字母，就在字典中对应的计数上加一
            if char in letter_count:
                letter_count[char] += 1
                total_letters += 1

# 计算频率并打印结果
for letter, count in sorted(letter_count.items()):
    frequency = count / total_letters
    print(f'{letter}: {frequency}')