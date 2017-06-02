#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp0, double Ki0, double Kd0) {
    Kp = Kp0;
    Ki = Ki0;
    Kd = Kd0;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    i_error += cte;
    d_error = cte - prev_cte;
    prev_cte = cte;
}

double PID::TotalError() {
    double total_error;
    total_error = -1 * (Kp * p_error + Ki * i_error + Kd * d_error);
    return total_error;
}

