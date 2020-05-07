# ECommerce-CMS #
An E-Commerce CMS Written Entirely In C++ As A University Project/Assignment

### Functionality ### 
1) Separate Portal for Employees and Customers

2) FOR CUSTOMERS

		* Buy Menu
    	* Show which items are in cart (In the buy menu)
    	* Option to edit item quantity that you already have in the cart (From the buy menu screen)
		* Search Menu
			* Search By Name
			* Search By ID
			* Search By Product Quantity In Cart
			* Search By Price
		* Check Cart Items
  	* Buy & Checkout
    	* Confirm Buy
		* Discard Items & Checkout
		* Pretty Colors
 
3) FOR EMPLOYEES
	* Separate (working) Login & Sign Up page for employees
	* Sign up page requires Master password (Hard coded into the code: 8531F1C0 ) to sign up so that anyone who doesn't have the source code can't sign up
	* Advanced Analytics menu which shows extra data about how products are performing, such as:
	  * List of most profitable items
	  * List of items low on stock
	  * Average Sale Amount of a specific product, i.e, average buy rate by the customers 
	  * Know how long your stock will last in the Advanced Analytics menu -> Average Sale Amount
	* Pretty Colors

4) Extensive Error Handling to ensure user does not encounter any bugs

### Challenges I Made For Myself ###
	1) Main() should only call only ONE function, and do nothing else
	2) Remove all unnecessary code 
	3) Play with addresses as much as possible
	4) Reuse functions by repurposing them in a manner that allows the same task with slight modifications to be done using them
	5) Try to use Function Overloading for atleast one thing. Verdict: It is only useful in bigger programs when you run out of names, and confusing 

### What I've Learnt Through This Project: ###
	1) Importance of documentation
	2) How Recursions work and what happens when you call a function within a function, and how to properly terminate recursion in a manner that doesn't break the program/cause unwanted code execution
	3) How to reduce code by modifying existing functions
	4) How to work with global variables
	5) How to work with pointers and addresses
	6) How passing by reference reduces code and decreases complexity of code
	7) How to make sort function work with most input types

### Questions At The End Of The Project: ###
	 1) How to do file-handling to save variables for later use (TAUGHT IN LATEST LAB)
	 2) How safe global variables are and is it better to use them or should I create local variables and pass a reference to them?
	 3) Why does cin sometimes not work? This is expecially true when trying to take in input with space. I have to use fflush() and cin.ignore(), 
		but if not used correctly, it can cause the first letter to get ignored, a big no no if you have a login system! 
		Another problem I've noticed is that if the user enters a character where the input is to be stored in an INT variable, it causes the input system
		to completely break. You will run into infinite loop of automatic input and error messages running on screen unless you terminate the program.
	 4) When I point a pointer to an address stored in another pointer which stores the address of an array (i.e, another pointer), 
		it only shows the first value stored in the array, but not the rest of it. e.g:

		int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int * ptr = arr;
		int * ptr2 = ptr;

		If I try to access ptr2, it will only show the first value stored in arr in the debugger (auto watch variable), i.e, arr[0] = 0, whereas the array arr
		in the debugger shows all of its indexes.
		I assume it has something to do with the program not being able to tell where the array ends, but if that is the case, then how do dynamic arrays work? 
		I mean I understand that they are created and allotted memory dynamically at run time, but what if that array uses all the continous memory locations 
		available, will the array get copied to a new address with more space available? How will the programmer access the new elements of it then?
