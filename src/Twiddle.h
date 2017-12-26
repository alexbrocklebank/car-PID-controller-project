#ifndef Twiddle_H
#define Twiddle_H

struct Parameter {
	bool up, down;
	double value;
};

class Twiddle {
	public:
		/*
		* Twiddle
		*/
		bool to_twiddle;

		int num_params;
		int num_steps;
		int current_step;

		std::vector<Parameter> dP;
		std::vector<double> best_param;

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


		void Init(int n_params, int n_steps);


		bool maxDistance();
};

#endif /* Twiddle_H */
