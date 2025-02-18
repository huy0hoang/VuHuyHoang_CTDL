def undo(self):
    if self.undo_stack:  # Kiểm tra nếu undo_stack không rỗng
        # Lưu trạng thái hiện tại vào redo_stack
        self.redo_stack.append(self.text)
        # Lấy trạng thái trước đó từ undo_stack
        self.text = self.undo_stack.pop()
        print("Đã hoàn tác hành động.")
        self.display()
    else:
        print("Không có hành động nào để hoàn tác.")
