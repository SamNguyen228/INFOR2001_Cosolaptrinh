import tkinter as tk
from tkinter import messagebox
from PIL import Image, ImageTk 

class Node:
    def __init__(self, data, color="R"):
        self.data = data
        self.color = color
        self.left = self.right = self.parent = None

class RedBlackTree:
    def __init__(self):
        self.TNULL = Node(0, "B")
        self.root = self.TNULL

    def search_tree_helper(self, node, key):
        if node == self.TNULL or key == node.data:
            return node

        if key < node.data:
            return self.search_tree_helper(node.left, key)
        return self.search_tree_helper(node.right, key)

    def minimum(self, node):
        while node.left != self.TNULL:
            node = node.left
        return node

    def maximum(self, node):
        while node.right != self.TNULL:
            node = node.right
        return node

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.TNULL:
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.TNULL:
            y.right.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert_fixup(self, k):
        while k.parent.color == "R":
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left
                if u.color == "R":
                    u.color = "B"
                    k.parent.color = "B"
                    k.parent.parent.color = "R"
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.right_rotate(k)
                    k.parent.color = "B"
                    k.parent.parent.color = "R"
                    self.left_rotate(k.parent.parent)
            else:
                u = k.parent.parent.right

                if u.color == "R":
                    u.color = "B"
                    k.parent.color = "B"
                    k.parent.parent.color = "R"
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self.left_rotate(k)
                    k.parent.color = "B"
                    k.parent.parent.color = "R"
                    self.right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = "B"

    def insert(self, key):
        node = Node(key)
        node.parent = None
        node.data = key
        node.left = self.TNULL
        node.right = self.TNULL
        node.color = "R"

        y = None
        x = self.root

        while x != self.TNULL:
            y = x
            if node.data < x.data:
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y is None:
            self.root = node
        elif node.data < y.data:
            y.left = node
        else:
            y.right = node

        if node.parent is None:
            node.color = "B"
            return

        if node.parent.parent is None:
            return

        self.insert_fixup(node)

    def delete_fixup(self, x):
        while x != self.root and x.color == "B":
            if x == x.parent.left:
                s = x.parent.right
                if s.color == "R":
                    s.color = "B"
                    x.parent.color = "R"
                    self.left_rotate(x.parent)
                    s = x.parent.right

                if s.left.color == "B" and s.right.color == "B":
                    s.color = "R"
                    x = x.parent
                else:
                    if s.right.color == "B":
                        s.left.color = "B"
                        s.color = "R"
                        self.right_rotate(s)
                        s = x.parent.right

                    s.color = x.parent.color
                    x.parent.color = "B"
                    s.right.color = "B"
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == "R":
                    s.color = "B"
                    x.parent.color = "R"
                    self.right_rotate(x.parent)
                    s = x.parent.left

                if s.right.color == "B" and s.right.color == "B":
                    s.color = "R"
                    x = x.parent
                else:
                    if s.left.color == "B":
                        s.right.color = "B"
                        s.color = "R"
                        self.left_rotate(s)
                        s = x.parent.left

                    s.color = x.parent.color
                    x.parent.color = "B"
                    s.left.color = "B"
                    self.right_rotate(x.parent)
                    x = self.root
        x.color = "B"

    def rb_transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    def delete_node_helper(self, node, key):
        z = self.TNULL
        while node != self.TNULL:
            if node.data == key:
                z = node

            if node.data <= key:
                node = node.right
            else:
                node = node.left

        if z == self.TNULL:
            return False

        y = z
        y_original_color = y.color
        if z.left == self.TNULL:
            x = z.right
            self.rb_transplant(z, z.right)
        elif z.right == self.TNULL:
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = self.minimum(z.right)
            y_original_color = y.color
            x = y.right
            if y.parent == z:
                x.parent = y
            else:
                self.rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y

            self.rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if y_original_color == "B":
            self.delete_fixup(x)
        return True

    def delete_node(self, data):
        if not self.delete_node_helper(self.root, data):
            print("Không tìm thấy giá trị trong cây.")
            return False
        return True

    def print_tree(self, node, indent, last, canvas, x, y, dx):
        if node != self.TNULL:
            color = 'red' if node.color == "R" else 'black'
            canvas.create_oval(x-15, y-15, x+15, y+15, fill=color)
            canvas.create_text(x, y, text=f"{node.data}", fill='white', font=('Times New Roman', 15, 'bold'))
            if node.left != self.TNULL:
                canvas.create_line(x, y, x - dx, y + 40, fill='black')
                self.print_tree(node.left, indent, False, canvas, x - dx, y + 40, dx // 2)
            if node.right != self.TNULL:
                canvas.create_line(x, y, x + dx, y + 40, fill='black')
                self.print_tree(node.right, indent, True, canvas, x + dx, y + 40, dx // 2)

    def get_root(self):
        return self.root


class RedBlackTreeApp:
    def __init__(self, root):
        self.tree = RedBlackTree()

        self.root = root
        self.root.title("Cây Đỏ-Đen")
        self.root.geometry("400x300")  # Đặt kích thước cửa sổ chính

        # Đặt hình nền cho cửa sổ chính
        self.background_image = Image.open("C:/Users/fptshop/Desktop/A.jpg")  # Đổi tên file hình ảnh theo nhu cầu của bạn
        self.background_photo = ImageTk.PhotoImage(self.background_image)

        self.bg_label = tk.Label(root, image=self.background_photo)
        self.bg_label.place(relwidth=1, relheight=1)  # Đặt Label để phủ toàn bộ cửa sổ

        self.label = tk.Label(root, text="Chức năng Cây Đỏ-Đen", bg='white')
        self.label.pack()

        self.insert_frame = tk.Frame(root, bg='white')
        self.insert_frame.pack()
        self.insert_label = tk.Label(self.insert_frame, text="Chèn:", bg='white')
        self.insert_label.pack(side=tk.LEFT)
        self.insert_entry = tk.Entry(self.insert_frame)
        self.insert_entry.pack(side=tk.LEFT)
        self.insert_button = tk.Button(self.insert_frame, text="Chèn", command=self.insert)
        self.insert_button.pack(side=tk.LEFT)

        self.delete_frame = tk.Frame(root, bg='white')
        self.delete_frame.pack()
        self.delete_label = tk.Label(self.delete_frame, text="Xóa:", bg='white')
        self.delete_label.pack(side=tk.LEFT)
        self.delete_entry = tk.Entry(self.delete_frame)
        self.delete_entry.pack(side=tk.LEFT)
        self.delete_button = tk.Button(self.delete_frame, text="Xóa", command=self.delete)
        self.delete_button.pack(side=tk.LEFT)

        self.search_frame = tk.Frame(root, bg='white')
        self.search_frame.pack()
        self.search_label = tk.Label(self.search_frame, text="Tìm kiếm:", bg='white')
        self.search_label.pack(side=tk.LEFT)
        self.search_entry = tk.Entry(self.search_frame)
        self.search_entry.pack(side=tk.LEFT)
        self.search_button = tk.Button(self.search_frame, text="Tìm kiếm", command=self.search)
        self.search_button.pack(side=tk.LEFT)

        self.min_button = tk.Button(root, text="Tìm giá trị nhỏ nhất", command=self.find_min)
        self.min_button.pack()

        self.max_button = tk.Button(root, text="Tìm giá trị lớn nhất", command=self.find_max)
        self.max_button.pack()

        self.print_button = tk.Button(root, text="In cây", command=self.print_tree)
        self.print_button.pack()

        self.quit_button = tk.Button(root, text="Thoát", command=root.quit)
        self.quit_button.pack()

    def insert(self):
        values = self.insert_entry.get().split(',')
        for value in values:
            value = value.strip()
            if value.isdigit():
                self.tree.insert(int(value))
                messagebox.showinfo("Thông báo", f"Đã chèn giá trị {value}")
            else:
                messagebox.showerror("Lỗi", f"Giá trị '{value}' không hợp lệ! Vui lòng nhập một số nguyên.")
        self.insert_entry.delete(0, tk.END)

    def delete(self):
        value = self.delete_entry.get()
        if value.isdigit():
            if self.tree.delete_node(int(value)):
                messagebox.showinfo("Thông báo", f"Đã xóa giá trị {value}")
            else:
                messagebox.showerror("Lỗi", "Không tìm thấy giá trị trong cây.")
        else:
            messagebox.showerror("Lỗi", "Giá trị không hợp lệ! Vui lòng nhập một số nguyên.")
        self.delete_entry.delete(0, tk.END)

    def search(self):
        value = self.search_entry.get()
        if value.isdigit():
            node = self.tree.search_tree_helper(self.tree.get_root(), int(value))
            if node != self.tree.TNULL:
                messagebox.showinfo("Thông báo", f"Đã tìm thấy giá trị {value}")
            else:
                messagebox.showerror("Lỗi", "Không tìm thấy giá trị.")
        else:
            messagebox.showerror("Lỗi", "Giá trị không hợp lệ! Vui lòng nhập một số nguyên.")
        self.search_entry.delete(0, tk.END)

    def find_min(self):
        node = self.tree.minimum(self.tree.get_root())
        messagebox.showinfo("Thông báo", f"Giá trị nhỏ nhất là {node.data}")

    def find_max(self):
        node = self.tree.maximum(self.tree.get_root())
        messagebox.showinfo("Thông báo", f"Giá trị lớn nhất là {node.data}")

    def print_tree(self):
        window = tk.Toplevel(self.root)
        window.title("Cây Đỏ-Đen")
        window.geometry("800x600")  # Đặt kích thước cửa sổ con

        # Đặt hình nền cho cửa sổ con
        bg_image = Image.open("C:/Users/fptshop/Desktop/A.jpg")  # Đổi tên file hình ảnh theo nhu cầu của bạn
        bg_photo = ImageTk.PhotoImage(bg_image)

        bg_label = tk.Label(window, image=bg_photo)
        bg_label.place(relwidth=1, relheight=1)

        canvas = tk.Canvas(window, width=800, height=600, bg='white')
        canvas.pack()

        # Draw tree
        self.tree.print_tree(self.tree.get_root(), "", True, canvas, 400, 20, 200)
        window.mainloop()

if __name__ == "__main__":
    root = tk.Tk()
    app = RedBlackTreeApp(root)
    root.mainloop()
