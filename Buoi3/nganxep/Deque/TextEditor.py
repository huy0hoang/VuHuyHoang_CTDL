class TextEditor:
    def __init__(self):
        self.text = ""
        self.undo_stack = []
        self.redo_stack = []

    def type_text(self, new_text):
        # Lưu trạng thái hiện tại vào undo_stack
        self.undo_stack.append(self.text)
        self.text += new_text
        # Xóa redo_stack vì có hành động mới
        self.redo_stack.clear()
        print(f"Đã gõ: '{new_text}'")
        self.display()

    def undo(self):
        if self.undo_stack:
            # Lưu trạng thái hiện tại vào redo_stack
            self.redo_stack.append(self.text)
            # Lấy trạng thái trước đó từ undo_stack
            self.text = self.undo_stack.pop()
            print("Đã hoàn tác hành động.")
            self.display()
        else:
            print("Không có hành động nào để hoàn tác.")

    def redo(self):
        if self.redo_stack:
            # Lưu trạng thái hiện tại vào undo_stack
            self.undo_stack.append(self.text)
            # Lấy trạng thái từ redo_stack
            self.text = self.redo_stack.pop()
            print("Đã làm lại hành động.")
            self.display()
        else:
            print("Không có hành động nào để làm lại.")

    def display(self):
        print(f"Văn bản hiện tại: '{self.text}'\n")

# Minh họa
editor = TextEditor()
editor.type_text("Hello")
editor.type_text(" World")
editor.undo()
editor.undo()
editor.redo()
