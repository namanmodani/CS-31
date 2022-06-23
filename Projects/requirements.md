## CS 31 General Programming Project Requirements

For each project, you will turn in programs and documentation electronically via a webpage that we will direct you to. What you will submit will be a single zip file containing the files listed in the project specification. Because we will be using software tools to help us grade your projects, there are certain requirements you must follow to receive any points at all:

- The names of the files contained in the zip file must be exactly what the project spec states. For example, if it says one of the files must be named calendar.cpp, then make sure it's named calendar.cpp, not calendar.cpp.txt or calendar.docx or calender.cpp or proj1.cpp or p1calendar.cpp. Even if English isn't your native language, or if you're a bad typist or speller, there's not much of an excuse for messing up here: We don't speak Irish, but if told to name a file "caoilfhionn" we could at least compare what we typed with what was required.

- The zip file must contain only the files required by the spec, unless the spec explicitly lists optional files you may include. The exception to this is that if you create the zip file under macOS, it is acceptable if it contains the additional files that the macOS zip utility sometimes introduces: `__MACOSX`, `.DS_Store`, and names starting with `._` that contain your file names.

We are continually amazed by people who get a zero by not meeting these simple requirements that someone who knows nothing about C++ could meet.

You are free to use any C++ development environment you want, but you must ensure that the programs you submit as source files run successfully using two compilers:

- One compiler must be either Visual C++ or clang++. If you use Xcode on a Mac, you're using clang++.
- The other compiler must be g31 on the SEASnet Linux server cs31.seas.ucla.edu. As the g++ with Linux writeup explains, g31 merely runs g++ in a way that catches more kinds of errors during execution. As a shorthand in this class, when we say "build/run using g++" or "build/run using g31", we mean "build/run using g31 on cs31.seas.ucla.edu — that specific command (g31, not g++) on a SEASnet machine reached via that specific name (not certain other SEASnet Linux machines).

Be sure you budget enough time to test your program using both compilers. In fact, periodically during program development, test your program using the compiler other than the one that you use to do your primary development. Rather than being a burden, this requirement to run using two compilers helps you improve your correctness score by assisting you in detecting errors in two ways:

- Different compilers might look for different questionable things to warn you about. For example, if instead of the character literal `'\n'` you mistakenly write `'/n'`, Visual C++ says nothing, while the other compilers warn you about a multi-character constant.
- Different compilers might produce code that behaves differently if your program does something with undefined behavior, such as using the value of an uninitialized variable or accessing an element outside the bounds of an array. If running your program under two different compilers produces different behavior, there's a very good chance your program is doing something undefined, which we prohibit.

If the program you turn in fails to build, your correctness score will be zero because we will be unable to test it. Don't make the mistake of making a last-minute change to your program and turning it in without having first tested the effect of that change. (Sometimes people think they made a change with no effect, like adding a comment, but didn't notice that their finger slipped and they also added a stray bad character not in a comment.)

You will get a very low correctness score, even zero, if your program does not handle the simplest cases correctly. Make sure no systematic error causes most or all cases to fail. If the project spec says the output of your program must be in a certain format exactly, then make it so. It's hard to go wrong with the format if you match exactly any examples we give in the spec.

Your program coding must be clear, simple, and straightforward. Your source code should have comments that tell the purpose of the major program segments and explain any tricky code.

Your programs will be scored on visible results, not effort. A program's correctness score will be closely correlated with its correctness, not with the amount of time you spent working on it. Using a careful, incremental development style, you may well spend less time and produce a more correct program than someone who tries to write the whole program at once, spends endless hours tracking down the bugs and trying to fix them, and runs out of time, ending up with something that fails most test cases. Make a backup copy of your program whenever it's in a state that builds successfully and correctly implements some of the project requirements; that way, if you try to add another feature, mess everything up, and run out of time, you still have something you can turn it that will earn you some correctness points.

It is your responsibility to make sure you frequently back up a program you are working on to an external device or a file server so that you can survive a misfortune like a stolen computer or a hard drive failure. A problem like this happens to someone every quarter, and it's especially sad when it happens on a project due date, their only backup (if any) was on the same machine, and they have no time to recreate all their work.

When a project requires you to submit a report, that report must be either a plain text file (produced by Notepad, TextEdit, nano, vim/vi, emacs, etc.) or a Microsoft Word document in .docx or .doc format (but not .rtf format).