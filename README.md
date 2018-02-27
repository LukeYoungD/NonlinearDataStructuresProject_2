# NonlinearDataStructuresProject_2
[C++]Take a Parenthesized infix expression [i.e. (5+(6*(2+1))) ] and convert it into a Postfix expression using a binary tree. Then evaluate the tree

This was my first project involving a non-linear data structure.
The biggest challenge was deciding how to structure the tree so that it could be evaluated. I eventually decided to read in the PostFix expression in reverse so that the head wouldn't change nearly every time a node was added.

The algorithm used is referred as a LRC(left, right, center) Tree Traversal. In that it evaluates the left-most node first, then the right one, and then computes the value of the current node. Example:

              Last---> +
                     /   \
          Third---> *     4 <---fourth
                  /   \
       First---> 2     3 <---Second

This means not only is it represented in as a Postfix equation, but it is also evaluated in the same way: 2 3 * 4 +

I note that I need to rewrite some functions to handle integers greater than 9, and added a bit of code to put spaces in between integers. In one of my future projects in the course, I actually do add the code necessary to evaluate multi-digit integers in expressions.

I was really proud of how clean this code turned out as opposed to my previous assignment, Project_1
