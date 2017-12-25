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
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	double total_error = -Kp * p_error - Ki * i_error - Kd * d_error;
	if (total_error > 1.0) {
		total_error = 1.0;
	}
	else if (total_error < -1.0) {
		total_error = -1.0;
	}
	return total_error;
}

