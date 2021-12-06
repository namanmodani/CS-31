### Programming Assignment 4  
### Array of Sunshine
--------------------------------------------

### Part 1

Go through the following sections of the class zyBook, doing the Participation Activities and Challenge Activities. We will be looking at whether you have ever successfully completed them; it does not matter how many attempts you make before a successful completion (or how many attempts you make after a successful completion if you want to experiment).

*   5.16 through 5.22
*   6.1
*   6.3 through 6.5

### Part 2

Before you ask questions about this specification, see if your question has already been addressed by the [Project 4 FAQ](faq.html). And read the FAQ before you turn in this project, to be sure you didn't misinterpret anything.

As you gain experience with arrays, you'll discover that many applications do the same kinds of things with them (e.g., find where an item is in an array, or check whether two arrays differ). You'll find that it's helpful to have a library of useful functions that manipulate arrays. (For our purposes now, a library is a collection of functions that developers can call instead of having to write them themselves. For a library to be most useful, the functions in it should be related and organized around a central theme. For example, a screen graphics library might have functions that allow you to draw shapes like lines and circles on the screen, move them around, fill them with color, etc. In this view, the Standard C++ library is really a collection of libraries: a string library, a math library, an input/output library, and much more.)

Your assignment is to produce a library that provides functions for many common manipulations of arrays of strings. For example, one function will find where a string occurs in an unordered array of strings. Another will change the order of strings in an array. For each function you must write, this specification will tell you its interface (what parameters it takes, what it returns, and _what_ it must do). It's up to you to decide on the implementation (_how_ it will do it).

The source file you turn in will contain all the functions and a main routine. You can have the main routine do whatever you want, because we will rename it to something harmless, never call it, and append our own main routine to your file. Our main routine will thoroughly test your functions. You'll probably want your main routine to do the same. If you wish, you may write functions in addition to those required here. We will not directly call any such additional functions. If you wish, your implementation of a function required here may call other functions required here.

The program you turn in must build successfully, and during execution, no function (other than main) may read anything from `cin` or write anything to `cout`. If you want to print things out for debugging purposes, write to `cerr` instead of `cout`. When we test your program, we will cause everything written to `cerr` to be discarded instead — we will never see that output, so you may leave those debugging output statements in your program if you wish.

All of the functions you must write take at least two parameters: an array of strings, and the number of items the function will consider to be part of the array, starting from the beginning. For example, in

string people\[5\] = { "merida", "tiana", "raya", "ariel", "moana" };
int i = locate(people, 3, "moana");  // should return -1 (not found)

even though the array has 5 elements, we're telling the function that only the first 3 have values we're interested in for this call; the function must not examine the others.

Notwithstanding each function's behavior described below, all functions that return an int must return −1 if they are passed any bad arguments (e.g. a negative array size, or a position that would require looking at the contents of an element past the last element we're interested in). Unless otherwise noted, passing 0 to the function as the array size is not itself an error; it merely indicates the function should examine no elements of the array.

The one error your function implementations don't have to handle (and thus we won't test for) is when the caller of the function says to examine _more_ items in the array than it actually has. For example, in this situation, it is _impossible_ for the function `locate` to detect that the caller is lying by telling the function that it can safely access _more_ elements of the `people` array than that array was declared to have:

string people\[5\] = { "merida", "tiana", "raya", "ariel", "moana" };
int i = locate(people, 25, "belle");  // Bad call of function, but your
		// locate implementation doesn't have to try to check for
		// this, because there is no way it can do so.

To make your life easier, whenever this specification talks about strings being equal or about one string being less than or greater than another, the case of letters matters. This means that you can simply use comparison operators like == or < to compare strings. Because of the character collating sequence on the platforms you're likely using, if you see every upper case letter comparing less than every lower case letter, don't be surprised. The [FAQ](faq.html) has a note about string comparisons.

Here are the functions you must implement:

`int reduplicate(string a[], int n);`

For each of the `n` elements of the array, append that element to that same element. Return `n`. \[Of course, in this and other functions, if `n` is negative, the [paragraph above that starts "Notwithstanding"](#badargs) trumps this by requiring that the function return −1. Also, in the description of this function and the others, when we say "the array", we mean the `n` elements that the function is told to consider to be part of the array.\] Here's an example:

string stuff\[6\] = { "mahi", "bon", "cous", "", "tar", "mur" };
int j = reduplicate(stuff, 6);  // returns 6
    // now stuff\[0\] is "mahimahi", stuff\[1\] is "bonbon", stuff\[2\] is "couscous",
    // stuff\[3\] is "", stuff\[4\] is "tartar", and stuff\[5\] is "murmur"

`int locate(const string a[], int n, string target);`

Return the position of a string in the array that is equal to `target`; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "ELsa" to be equal to "eLsA".  
  

`int locationOfMax(const string a[], int n);`

Return the position of a string in the array such that that string is >= every string in the array. If there is more than one such string, return the smallest position number of such a string. Return −1 if the function should examine no elements of the array. Here's an example:

string cast\[6\] = { "elsa", "ariel", "mulan", "tiana", "belle", "moana" };
int k = locationOfMax(cast, 6);   // returns 3, since  tiana  is latest
                                  // in alphabetic order

`int circleLeft(string a[], int n, int pos);`

Eliminate the item at position `pos` by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array that the function knows about. Return the original position of the item that was moved to the end. Here's an example:

string folks\[5\] = { "moana", "elsa", "ariel", "raya", "mulan" };
int m = circleLeft(folks, 5, 1);  // returns 1
    // folks now contains:  "moana", "ariel", "raya", "mulan", "elsa"

`int enumerateRuns(const string a[], int n);`

Return the number of sequences of one or more consecutive identical items in `a`.

string d\[9\] = {
    "belle", "merida", "raya", "raya", "tiana", "tiana", "tiana", "raya", "raya"
};
int p = enumerateRuns(d, 9);  //  returns 5
	   //  The five sequences of consecutive identical items are
	   //    "belle"
	   //    "merida"
	   //    "raya", "raya"
	   //    "tiana", "tiana", "tiana"
	   //    "raya", "raya"

`int flip(string a[], int n);`

Reverse the order of the elements of the array and return `n`. Here's an example:

string roles\[6\] = { "merida", "raya", "", "belle", "moana", "elsa" };
int q = flip(roles, 4);  // returns 4
    // roles now contains:  "belle"  ""  "raya"  "merida"  "moana"  "elsa"

`int locateDifference(const string a1[], int n1, const string a2[], int n2);`

Return the position of the first corresponding elements of `a1` and `a2` that are not equal. `n1` is the number of interesting elements in `a1`, and `n2` is the number of interesting elements in `a2`. If the arrays are equal up to the point where one or both runs out, return whichever value of `n1` and `n2` is less than or equal to the other. Here's an example:

string roles\[6\] = { "merida", "raya", "", "belle", "moana", "elsa" };
string group\[5\] = { "merida", "raya", "elsa", "", "belle" };
int r = locateDifference(roles, 6, group, 5);  //  returns 2
int s = locateDifference(roles, 2, group, 1);  //  returns 1

`int subsequence(const string a1[], int n1, const string a2[], int n2);`

If all `n2` elements of `a2` appear in `a1`, consecutively and in the same order, then return the position in `a1` where that subsequence begins. If the subsequence appears more than once in `a1`, return the smallest such beginning position in the array. Return −1 if `a1` does not contain `a2` as a contiguous subsequence. (Consider a sequence of 0 elements to be a subsequence of any sequence, even one with no elements, starting at position 0.) For example,

string names\[10\] = { "moana", "mulan", "raya", "tiana", "merida" };
string names1\[10\] = { "mulan", "raya", "tiana" };
int t = subsequence(names, 5, names1, 3);  // returns 1
string names2\[10\] = { "moana", "tiana" };
int u = subsequence(names, 4, names2, 2);  // returns -1

`int locateAny(const string a1[], int n1, const string a2[], int n2);`

Return the smallest position in `a1` of an element that is equal to any of the `n2` elements in `a2`. Return −1 if no element of `a1` is equal to any element of `a2`. Here's an example:

string names\[10\] = { "moana", "mulan", "raya", "tiana", "merida" };
string set1\[10\] = { "elsa", "merida", "tiana", "mulan" };
int v = locateAny(names, 6, set1, 4);  // returns 1 (a1 has "mulan" there)
string set2\[10\] = { "belle", "ariel" };
int w = locateAny(names, 6, set2, 2);  // returns -1 (a1 has none)

`int separate(string a[], int n, string separator);`

Rearrange the elements of the array so that all the elements whose value is < `separator` come before all the other elements, and all the elements whose value is > `separator` come after all the other elements. Return the position of the first element that, after the rearrangement, is not < `separator`, or `n` if there are no such elements. Here's an example:

string cast\[6\] = { "elsa", "ariel", "mulan", "belle", "tiana", "moana" };
int x = separate(cast, 6, "merida");  //  returns 3
	// cast must now be
	//      "belle"  "elsa"  "ariel"  "moana"  "tiana"  "mulan"
	// or   "elsa"  "ariel"  "belle"  "mulan"  "moana"  "tiana"
	// or one of several other orderings.
	// All elements < "merida" (i.e., "elsa", "ariel", and "belle")
	//   come before all others
	// All elements > "merida" (i.e., "tiana", "moana", and "mulan")
	//   come after all others
string cast2\[4\] = { "mulan", "tiana", "ariel", "raya" };
int y = separate(cast2, 4, "raya");  //  returns 2
	// cast2 must now be either
	//      "mulan"  "ariel"  "raya"  "tiana"
	// or   "ariel"  "mulan"  "raya"  "tiana"
	// All elements < "raya" (i.e., "ariel" and "mulan") come
        // before all others.
	// All elements > "raya" (i.e., "tiana") come after all others.

For each of the functions `circleLeft`, `flip`, and `separate`, if the function is correctly implemented, you will earn one bonus point for that function if it does its job without creating any additional array.

Your program must _not_ use any function templates from the algorithms portion of the Standard C++ library. If you don't know what the previous sentence is talking about, you have nothing to worry about.

Your implementations must not use any global variables whose values may be changed during execution.

Your program must build successfully under both g31 and either Visual C++ or clang++.

The correctness of your program must not depend on undefined program behavior. Your program could not, for example, assume anything about `t`'s value in the following, or even whether or not the program crashes:

	int main()
	{
	    string s\[3\] = { "merida", "raya", "tiana" };
	    string t = s\[3\];   // position 3 is out of range
	    …

As with Project 3, a nice way to test your functions is to use the `assert` facility from the standard library. As an example, here's a very incomplete set of tests for Project 4:

	#include <iostream>
	#include <string>
	#include <cassert>
	using namespace std;

	int main()
	{
	    string h\[7\] = { "moana", "mulan", "ariel", "tiana", "", "belle", "elsa" };
	    assert(locate(h, 7, "belle") == 5);
	    assert(locate(h, 7, "ariel") == 2);
	    assert(locate(h, 2, "ariel") == -1);
	    assert(locationOfMax(h, 7) == 3);

	    string g\[4\] = { "moana", "mulan", "belle", "raya" };
	    assert(locateDifference(h, 4, g, 4) == 2);
	    assert(circleLeft(g, 4, 1) == 1 && g\[1\] == "belle" && g\[3\] == "mulan");

	    string c\[4\] = { "ma", "can", "tu", "do" };
	    assert(reduplicate(c, 4) == 4 && c\[0\] == "mama" && c\[3\] == "dodo");

	    string e\[4\] = { "ariel", "tiana", "", "belle" };
	    assert(subsequence(h, 7, e, 4) == 2);

	    string d\[5\] = { "mulan", "mulan", "mulan", "belle", "belle" };
	    assert(enumerateRuns(d, 5) == 2);
	
	    string f\[3\] = { "tiana", "ariel", "raya" };
	    assert(locateAny(h, 7, f, 3) == 2);
	    assert(flip(f, 3) == 3 && f\[0\] == "raya" && f\[2\] == "tiana");
	
	    assert(separate(h, 7, "elsa") == 3);
	
	    cout << "All tests succeeded" << endl;
	}

The reason for the one line of output at the end is to ensure that you can distinguish the situation of all tests succeeding from the case where one test silently crashes the program.

Make sure that if you were to replace your main routine with the one above, your program would build successfully under both g31 and either Visual C++ or clang++. (This means that even if you haven't figured out how to implement some of the required functions, you must still have _some_ kind of implementation for each of them, even if such a stub implementation does nothing more than immediately return, say, 42.) If the program built with that main routine happens to run successfully, you'll probably get a pretty good correctness score.

### What to turn in

You won't turn anything in through the CS 31 web site for Part 1; the zyBook system notes your successful completion of the PAs and CAs. For Part 2, turn in a zip file containing these two files and nothing more:

1.  A text file named **array.cpp** that contains the source code for your C++ program. Your source code should have helpful comments that explain any non-obvious code. If you chose to write additional functions, make sure they are in this file.
    
2.  A file named **report.docx** or **report.doc** (in Microsoft Word format), or **report.txt** (an ordinary text file) that contains:
    1.  A brief description of notable obstacles you overcame.
    2.  A list of the test data that could be used to thoroughly test your functions, along with the reason for each test. You must note which test cases your program does not handle correctly. (This could happen if you didn't have time to write a complete solution, or if you ran out of time while still debugging a supposedly complete solution.) Notice that most of this portion of your report can be written just after you read the requirements in this specification, before you even start designing your program.

How nice! Your report this time doesn't have to contain any design documentation.

By Tuesday, November 2, there will be a link on the class webpage that will enable you to turn in your zip file electronically. Turn in the file by the due time above.
