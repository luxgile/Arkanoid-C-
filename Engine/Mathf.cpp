#include "Mathf.h"

const float Mathf::Lerp(float a, float b, float t)
{
	if (t > 1) { t = 1; }
	float lerp = a + ((b - a) * t);

	return lerp;
}
