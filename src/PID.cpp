#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	Kp = Kp;
	Ki = Ki;
	Kd = Kd;
	prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
	if (prev_cte == 0.0) {
		prev_cte = cte;
	}
	double diff_cte = cte - prev_cte;
	prev_cte = cte;
	p_error = cte * -Kp;
	i_error = (i_error + cte) * -Ki;
	d_error = diff_cte * -Kd;
}

double PID::TotalError() {
	return (p_error + i_error + d_error);
}

