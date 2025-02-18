# Vòng lặp đơn trong Python

def print_number(n):
    for i in range(1, n + 1):
        print(i, end=" ")  # In trên cùng một dòng với khoảng trắng
    print()  # Xuống dòng sau khi hoàn thành vòng lặp

def main():
    n = 5
    print_number(n)  # Output: 1 2 3 4 5

if __name__ == "__main__":
    main()
