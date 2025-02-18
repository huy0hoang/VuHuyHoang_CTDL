def printPairs(n):
    for i in range(1, n + 1):  # Vòng lặp bên ngoài chạy từ 1 đến n
        for j in range(1, n + 1):  # Vòng lặp bên trong chạy từ 1 đến n
            print(f"({i}, {j})")  # In cặp (i, j)

printPairs(3)
