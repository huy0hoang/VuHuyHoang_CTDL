def count_chars(string):
    char_count = {}
    
    for char in string.lower():  #cú pháp chuyển chữ hoa về chữ thường
        if char.isalpha():
            char_count[char] = char_count.get(char, 0) + 1
    
    return char_count

# Test case
print(count_chars("Happiness"))  # Output: {'h': 1, 'a': 1, 'p': 2, 'i': 1, 'n': 1, 'e': 1, 's': 2}
