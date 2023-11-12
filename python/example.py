#primeiro definir uma classe para o nó
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

#segundo definir uma classe para a arvore
class BinaryTree:
    def __init__(self, root):
        self.root = TreeNode(root)

    #inserir nó na arvore
    def insertNode(self, value):
        self._insert_recursively(self.root, value)
        
    def _insert_recursively(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = TreeNode(value)
            else:
                self._insert_recursively(current_node.left, value)
        elif value > current_node.value:
            if current_node.right is None:
                current_node.right = TreeNode(value)
            else:
                self._insert_recursively(current_node.right,value)
    #pesquisar nó na arvore
    def search(self, value):
        self._search_recursively(self.root, value)

    def _search_recursively(self, current_node, value):
        if current_node is None:
            return print("Não foi encontrado o valor " + str(value))
        if current_node.value == value:
            return print("Encontrei o valor " + str(value))
        elif (value < current_node.value):
            return self._search_recursively(current_node.left, value)
        else:
            return self._search_recursively(current_node.right, value)
        
    #percorrer in order transversal
    def inOrderTraversal(self):
        elements = []
        self._inOrderTraversal_recursively(self.root, elements)
        return elements

    def _inOrderTraversal_recursively(self, current_node, elements):
        if current_node:
                self._inOrderTraversal_recursively(current_node.left, elements)
                elements.append(current_node.value)
                self._inOrderTraversal_recursively(current_node.right, elements)
    #printar 
    def printInOrder(self):
            self._printInOrder(self.root)

    def _printInOrder(self, node):
        if node is not None:
            self._printInOrder(node.left)
            print(node.value)
            self._printInOrder(node.right)
            
if __name__ == "__main__":
    tree = BinaryTree(10)
    
    for i in range(0, 10):
        tree.insertNode(i)
        
    tree.printInOrder()
    
    print(tree.search(20))

        