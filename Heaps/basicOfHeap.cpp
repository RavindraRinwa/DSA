/*

What is Heap ?
heap is complete Binary Tree(CBT) that comes with a heap ordered property

What is CBT ?
every level completly fill expect last level which is filled from
left side

here meaning of filled from left side  is :- 1. first fill leftmost  left node
                                             2. second fill leftmost right node  like this follow rule from
                                             left side
                                             NOTE :- if no one  node is missing (except last level) from this mannar you can CBT

                                             in last level right node missing but left node can not miss


Max-Heap = always parent element has grater value then child this applicable for
           each element
Min-Heap = always parent element has lesser value then child this applicable for
           each elment

IN heap  if parent index =  i         // not for zero based indexed.
        then left child index = 2*i
        or right child index = 2*i+1


*/