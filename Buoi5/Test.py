class TreeNode: 
    def __init__(self, data): 
        self.data = data 
        self.children = [] 
        self.parent = None  

    def add_child(self, child): 
        child.parent = self 
        self.children.append(child)

    def get_level(self):  
        level = 0 
        p = self.parent 
        while p: 
            level += 1 
            p = p.parent 
        return level 

    def print_tree(self): 
        space = ' ' * self.get_level() * 3  
        prefix = space + "|-- " if self.parent else ""  

        print(prefix + self.data)  

        if self.children: 
            for child in self.children: 
                child.print_tree()


def create_tree(): 
    a_node = TreeNode("A") 
    b_node = TreeNode("B") 
    c_node = TreeNode("C") 
    d_node = TreeNode("D") 
    e_node = TreeNode("E") 
    f_node = TreeNode("F") 
    g_node = TreeNode("G") 

    a_node.add_child(b_node) 
    a_node.add_child(c_node) 
    b_node.add_child(d_node) 
    b_node.add_child(e_node) 
    c_node.add_child(f_node) 
    c_node.add_child(g_node) 

    return a_node 


tree = create_tree()
tree.print_tree()
