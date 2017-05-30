 
#include "PID.h"
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_N, double Kd_N, double Ki_N) {
  Kp = Kp_N;
  Kd = Kd_N;
  Ki = Ki_N;

  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {

  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;
}

double PID::TotalError() {
  double alpha = -Kp * p_error - Kd * d_error - Ki * i_error;
  return alpha;
}
