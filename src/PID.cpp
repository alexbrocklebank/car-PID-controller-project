#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this.p_error = 0.0;
	this.i_error = 0.0;
	this.d_error = 0.0;
	this.Kp = Kp;
	this.Ki = Ki;
	this.Kd = Kd;
	this.prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
	if (this.prev_cte == 0.0) {
		this.prev_cte = cte;
	}
	double diff_cte = cte - prev_cte;
	this.prev_cte = cte;
	this.p_error = cte * -this.Kp;
	this.i_error = (this.i_error + cte) * -this.Ki;
	this.d_error = diff_cte * -this.Kd;
}

double PID::TotalError() {
	return (p_error + i_error + d_error);
}

