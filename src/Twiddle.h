#ifndef Twiddle_H
#define Twiddle_H

class Twiddle {
public:
	/*
	* Twiddle
	*/
	int n;
	int max_steps;

	double[] dP;

	double err;
	double best_err;


	/*
	* Constructor
	*/
	Twiddle();

	/*
	* Destructor.
	*/
	virtual ~Twiddle();


};

#endif /* Twiddle_H */
