# BinaryTree
Binary Tree Boilerplate

Binary Tree infrastructure along with Queues one 
In order to display the trees content,we implemented a queue,a temporarily 
buffer for display
The Queue each time enqueue a whole "struct noeud" and checks if that 
cell has a "left" and "right" cells ,if it does it will enqueue both of 
them and so on..


Added a function that checks if two binary trees are equal using the built-in
infrastructures(queues),so each tree will have its own queue that stores nodes
and we compare these queue elements with each others

NB: two trees are identical unless they have the same structure aswell the same
node contents.


Module contains:
-Binary tree construction
-Binary tree queue display
-degenerated/pathological function check
-Tree-similarity check function
-Display a binary tree in a sequential way (ordered) using both queue and list
