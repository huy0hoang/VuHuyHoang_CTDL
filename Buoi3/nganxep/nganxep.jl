import Base: push!, pop!, display

mutable struct Stack
    elements::Vector{Any}  # Định nghĩa rõ kiểu của `elements`
    Stack() = new(Vector{Any}())  # Tạo một ngăn xếp mới rỗng
end

# Hàm thêm phần tử vào ngăn xếp
function push!(s::Stack, item)
    push!(s.elements, item)  # Sử dụng push! trực tiếp với `s.elements`
    println("Đã thêm '$item' vào ngăn xếp.")
end

# Hàm lấy phần tử từ ngăn xếp
function pop!(s::Stack)
    if !isempty(s.elements)  # Kiểm tra xem ngăn xếp có trống không
        item = pop!(s.elements)  # Sử dụng pop! trực tiếp với `s.elements`
        println("Đã lấy '$item' ra khỏi ngăn xếp.")
        return item
    else
        println("Ngăn xếp trống!")
        return nothing
    end
end

# Hàm xem phần tử trên đỉnh ngăn xếp
function peek(s::Stack)
    if !isempty(s.elements)
        return s.elements[end]
    else
        println("Ngăn xếp trống!")
        return nothing
    end
end

# Hàm kiểm tra ngăn xếp có trống hay không
function is_empty(s::Stack)
    return isempty(s.elements)
end

# Ghi đè hàm `display` để in ra nội dung ngăn xếp
function Base.display(s::Stack)
    println("Ngăn xếp (đỉnh → đáy): ", reverse(s.elements))
end

# Hàm chính để kiểm tra chức năng
function main()
    stack = Stack()  # Tạo một ngăn xếp mới
    push!(stack, "Sách A")
    push!(stack, "Sách B")
    push!(stack, "Sách C")
    display(stack)  # Hiển thị ngăn xếp

    top_item = peek(stack)  # Xem phần tử ở đỉnh ngăn xếp
    println("Phần tử ở đỉnh ngăn xếp: ", top_item)

    pop!(stack)  # Lấy phần tử ra khỏi ngăn xếp
    display(stack)  # Hiển thị lại ngăn xếp

    println("Ngăn xếp có trống không? ", is_empty(stack) ? "Có" : "Không")
end

# Gọi hàm chính
main()
