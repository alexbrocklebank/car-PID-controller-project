#include "Twiddle.h"

using namespace std;

Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}

void Twiddle::Init(int n_params, int n_steps) {
	bool to_twiddle;
	
	int num_params = n_params;
	int num_steps = n_steps;
	int current_step = 0;

	std::vector<Parameter> dP;
	std::vector<double> best_param;

	for (int i = 0; i < n_params; i++) {
		Parameter p;
		p.up = false;
		p.down = false;
		p.value = 1.0;
		dP.push_back(p);
	}

	double err = 0.0;
	double best_err = 100.0;
}


bool Twiddle::maxDistance() {
	return (current_step >= num_steps);
}