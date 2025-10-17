[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.





## Forewarnings

The .csv was modified to remove "unusual line endings" as per Visual Studio Code's warning. This included "Paragraph Ending" and "Line Ending" characters. Overall, it should not be a large enough change to cause a difference in results.
## Planning Process

Here, I will document my thought process as I think of how to approach the PA.\
It probably won't be too coherent, as I am mostly writing stuff as I think of it, but that's all just part of the fun lol.\
(I will try to highlight key parts in this section)

So the PA wants me (other than creating a REPL system which I will have to figure out) essentially store Amazon inventory, and let the user query using an inventoryid or category.

So in essence, I need to keep track of inventoryids and categories.

A trivial solution is to have two hashtables, which 'sort' the products based on their inventoryid and category. This feels pretty space inefficient, but it is currently the best idea off the top of my head.

Another trivial solution is a linked list, which would be very time inefficient for lookups, so I am ruling that out.

I feel pretty confident about the hashtable solution, it definately works for the inventoryid problem, because I can hash the id to find an index, but my main issue lies with the category part of it all.


Ok, random idea. What if I had a tree of hashtables. Each node in the tree consisted of a category, and each node contained a hashtable that contained products in that category?

But then how would I do the inventoryid with that?\
Bruhhh

Ok I took a break to eat an incredibly overcooked baked potato.

I think I had a brain blast though.

I can do the two hashtable idea. But instead of storing an object of the product, it stores a pointer to an object of the product.

Additionally, I think it would be a good idea to simply have each index in the hashmap contain a doubly linked list of duplicates, rather than having to do something like linear or quadradic probing, or double hashing. Honestly, this approach kind of acts like probing, considering I would have to go through the list to try and find the element in the list if it exists. I don't think I really need to watch the load factor either, considering duplicate idex calls will simply be added to the index's list.

**So here is the current plan I guess:**

- 2 hashtables, hashes by id and the other hashes by category
- Hashtable indexes contain a list, which stores duplicate entries/inserts
- Each list node contains pointers to a 'data' container, or something similar. 
- Each data container has a value that indicates how many things a given data node is connected to
- During deletion, if the 'linked' value reaches 0, then the node itself gets deleted (shouldn't happen for this PA, but figured it would be good to include)
