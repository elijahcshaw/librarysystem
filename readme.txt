------------------------------------------------------------------------------
IMPORTANT - DO NOT COPY
------------------------------------------------------------------------------
If you have found this project and it's similar to an class assignment you
have been given - do not copy it. This assignment was a group-based design and
partner-based implementation, meaning the spec was relatively vague in what 
the requirements were, and many of the coding decisions made here were choices
personally discussed and implemented by the project partners. Beyond the moral
implications of copying this, it's very likely this would not be entirely
appropriate for whatever assignment you may have been given. 

This project has been uploaded for resume purposes without a class, professor,
or assignment name. If a student finds and copies this for their own personal
assignment, the partners for this project take no responsibility for their
academic misconduct.


------------------------------------------------------------------------------
COMPILING & RUNNING
------------------------------------------------------------------------------
1. Compile the library system with "g++ *.cpp" (Compile on legacy C++, may not
compile or run properly on newer versions)

2. Run the program with ./a.out (or valgrind ./a.out if you would like to see
memory information)

3. The program can handle some errors (such as incorrect item type, missing or
invalid operation information, nonexistent patron, etc.). If you'd like to 
change the data read by the program, modification should be made to the
.txt files.

4. Other more advanced changes can be implemented through code editing. Adding
new items simply means you need to create a new class inheriting from Item (or
the applicable child of Item, like Book), and insert it into ItemFactory's
constructor as has been done for the three types of books. A similar method
allows you to add new types of transactions, although that may require more
involved editing of the code depending on the transaction to be added.


------------------------------------------------------------------------------
ADDITIONAL NOTES
------------------------------------------------------------------------------
1. Our Library program is fully functional. A library can be built using data 
from .txt files for books and patrons, and it can execute commands based on a 
third file. The library can be displayed, as well as a specific patron's 
history. Patrons can check out and return books in the library. The program 
runs with no memory leaks.

2. - HashTable: This is our coded-from-scratch table designed to store our 
patrons in the library. It's found in "hashtable.h" and "hashtable.cpp".
   - ItemFactory: This is a factory that uses a hash function to make items 
for the library (books, in this case). It can be found in "itemfactory.h" and
"itemfactory.cpp".
   - TransactionFactory: This is a factory that uses a hash function to make
transactions for executing the library commands and saving to patron history.
It can be found in "transactionfactory.h" and "transactionfactory.cpp".

3. Book data is initially opened by library.cpp with buildBooksFromFile(), but
the file is then read line by line in each of the book subclasses' setData()
methods (fictionbook.cpp, childrenbook.cpp, periodicalbook.cpp).

4. Command data is initially opened by library.cpp with the method
acceptTransactions(), but the file is then read line by line in each of
the transaction subclasses' execute() methods (checkout.cpp, return.cpp, 
display.cpp, history.cpp).

5. Dirty Secrets - We're not currently aware of any part of this that violates
the design principles/assignment spec. No switches are used.

6. We're particularly proud of expanding our design to work with any potential
item or transaction in the future. The program is fully object-oriented, so if
we wanted to add music as a type of item, we could easily add that class across
the program, as well as any subclasses like CD or cassette. The same applies to
our transaction design. 
