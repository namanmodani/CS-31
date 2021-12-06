// Code for Project 1
	// Report survey results
	
	#include <iostream>
	using namespace std;
	
	int main()
	{
	    int numberSurveyed;
	    int likeInPerson;
	    int likeAtHome;
	
	    cout << "How many students were surveyed? ";
	    cin >> numberSurveyed;
	    cout << "How many of them prefer being at school in person? ";
	    cin >> likeInPerson;
	    cout << "How many of them would rather do school from home? ";
	    cin >> likeAtHome;
	
	    double pctLikeInPerson = 100.0 * likeInPerson / numberSurveyed;
		// Error 1: Incorrect math, replaced 100.0 with 42.0
	    double pctLikeAtHome = 42.0 * likeAtHome / numberSurveyed;

	    cout.setf(ios::fixed);
	    cout.precision(1);
	
	    cout << endl;
	    cout << pctLikeInPerson << "% prefer being at school in person." << endl;
	    cout << pctLikeAtHome << "% prefer doing school from home." << endl;

		// Error 2: Reversed the greater than (>) sign, leading to an incorrect prediction
	    if (likeInPerson < likeAtHome)
	        cout << "More students like being at school in person than doing school at home." << endl;
	    else
	        cout << "More students like doing school from home than being at school in person." << endl;
	}