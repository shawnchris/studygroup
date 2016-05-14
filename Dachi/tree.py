class Node:
  _left = None
  _right = None

  def __init__(self,key,val,n):
    self.key = key
    self.val = val
    self.n = n

class BST:

  _root = None

  def __init__(self,key,val):
    self._root = Node(key,val,1)

  @staticmethod
  def _size(node):
    return 0 if node == None else node.n

  def size(self):
    return BST._size(self._root)

  @staticmethod
  def _get(node,key):
    if node is None:
      return None
    if node.key == key:
      return node.val
    elif node.key < key:
      return BST._get(node._right,key)
    else:
      return BST._get(node._left,key)

  def get(self,key):
    return BST._get(self._root,key)

  @staticmethod
  def _put(node,key,val):
    if node is None:
      return Node(key,val,1)
    if node.key == key:
      node.val = val
    elif node.key < key:
      node._right = BST._put(node._right,key,val)
    else:
      node._left = BST._put(node._left,key,val)
    node.n = BST._size(node._left) + BST._size(node._right) + 1
    return node

  def put(self,key,val):
    self._root = BST._put(self._root,key,val)
  
  @staticmethod
  def _delete(node,key):
    pass
 
class RBNode:
  # Using bst and color information to represent 2-3 tree
  # Node1.left = Node2(RED) represents 3 node

  _left = None
  _right = None

  def __init__(self,key,val,n,color):
    self.key = key
    self.val = val
    self.n = n
    self.color = color

class RBT:
  '''
  2-3 树，2-node有两个children,3-node有三个children
  流程
     root                
     /(red link)          
   left 
  '''
  _root = None

  def __init__(self,key,val):
    self._root = Node(key,val,1)

  @staticmethod
  def isRed(node):
    if node is None:
      return False
    return node.color == True

  @staticmethod
  def _size(node):
    return 0 if node == None else node.n

  def size(self):
    return BST._size(self._root)

  @staticmethod
  def _rotateLeft(node):
    x = node.right
    node.right = x.left
    x.left = node
    x.color = node.color
    node.color = True
    x.n = node.n
    node.n = 1 + BST._size(node.left) + BST._size(node.right)
    return x

  @staticmethod
  def _rotateRight(node):
    x = node.left
    node.left = x.right
    x.right = node
    x.color = node.color
    node.color = x.color
    x.color = True
    x.n = node.n
    node.n = 1 + BST._size(node.left) + BST._size(node.right)
    return x

  @staticmethod
  def _flipColor(node):
    node.color = True
    node._left.color = False
    node._right.color = False

  def put(self,key,val):
    pass

  @staticmethod
  def _put(node,key,val):
    pass

  def get(self,key):
    pass

  @staticmethod
  def _get(node,key,val):
    pass

class Trie:
  #### Data Structure:
 
  # root.next[R] every node in next also has node.next[R] 
  # root.next[R] nodes.val != empty represent a collectable key
  
  #### properties

  #### methods
  def put(self,key,val):
    pass

  @staticmethod
  def _put(node,key,val,d):
    pass

  def get(self,key):
    pass

  @staticmethod
  def _get(node,key,d):
   pass

if __name__ == "__main__":
  print "Contructing a binary search tree..."
  bsTree = BST("S","S")
  bsTree.put("E","E")
  bsTree.put("X","X")
  print "root      : ",bsTree._root.key
  print "root.left : ",bsTree._root._left.key
  print "root.right: ",bsTree._root._right.key
