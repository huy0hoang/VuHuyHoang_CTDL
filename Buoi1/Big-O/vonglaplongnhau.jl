function printPairs(n)
    for i in 1:n         # Vòng lặp ngoài
        for j in 1:n     # Vòng lặp trong
            println("($i, $j)")  # In cặp (i, j)
        end
    end
end

function main()
    n = 3
    printPairs(n)  # Gọi hàm với n = 3
end

main()
