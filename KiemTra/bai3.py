import collections
import re

def count_chars_in_file(file_path):
    char_count = collections.defaultdict(int)
    
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            chars = re.findall(r'[a-zA-Z]', line.lower())  # Lấy tất cả các ký tự a-z, A-Z
            for char in chars:
                char_count[char] += 1
    
    return dict(char_count)


# Example: 
file_path = 'C:/Users/Admin/Documents/code c++/.vscode/buoi4/TUAN-4/P1_data.txt'

print(count_chars_in_file(file_path))
