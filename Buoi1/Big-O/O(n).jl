# Vòng lặp đơn trong Julia

function printNumber(n)
    for i in 1:n
        print("$i ")
    end
    println()  # In xuống dòng sau khi hoàn thành vòng lặp
end

function main()
    n = 5
    printNumber(n)  # Output: 1 2 3 4 5
end

main()
