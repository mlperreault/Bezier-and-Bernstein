#include <iostream>
#include <vector>
#include <assert.h>
#include <type_traits>	
#include <math.h>

/*
  'Hardcoded' Berstein polynomes functions for a Cubic ( 4 points ) curve.
*/
template<class T>
T GetBezierPointOnCurve_4_points(const std::vector<T>& P, float t)
{
	assert(
		(std::is_same<int, T>::value || std::is_same<float, T>::value || std::is_same<double, T>::value)
		&& "T doit etre de type INT ou FLOAT"
	);

	assert(
		(t >= 0 && t <= 1) 
    && "T dois etre compris entre 0 et 1"
	);

	auto n{ P.size() };

  // TODO : move bernstein polynomes into a generic function
	T control_point_1 = pow(1.0 - t, 3) * P[0];
	T control_point_2 = 3 * pow(1.0 - t, 2) * t * P[1];
	T control_point_3 = 3 * (1.0 - t) * pow(t, 2) * P[2];
	T control_point_4 = pow(t, 3) * P[3];
  
	return ( control_1 + control_2 + control_3 + control_4 );
}

int main(void)
{
  // Cubic curve.
  // Curve goes from point 1 to point 4 without touching point 2 and 3 ( which are direction vectors )
	std::vector<float> P = { 0.0 , 1.0 , 1.0 , 0.0 };
  
	for (float t = 0.0f; t <= 1.0f; t += 0.1f) {
		std::cout << "Point on curve for t " << t << " : " << GetBezierPointOnCurve_4_points(P, t) <<std::endl;
	}
  
	return 0;
}
