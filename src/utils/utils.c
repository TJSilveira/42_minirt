#include "../includes/minirt.h"

double length_squared(vec3 *v)
{
	return (v->e[0]*v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
}

double length(vec3 *v)
{
	return (sqrt(length_squared(v)));
}

vec3 vec3_mul_const_copy(vec3 v, double t)
{
	return (vec3){{
		v.e[0] * t,
		v.e[1] * t,
		v.e[2] * t
	}};
}

void vec3_mul_const(vec3 *v, double t)
{
	v->e[0] *= t;
	v->e[1] *= t;
	v->e[2] *= t;
}

vec3 vec3_div_const_copy(vec3 v, double t)
{
	return (vec3){{
		v.e[0] / t,
		v.e[1] / t,
		v.e[2] / t
	}};
}

void vec3_div_const(vec3 *v, double t)
{
	v->e[0] /= t;
	v->e[1] /= t;
	v->e[2] /= t;
}

vec3 vec3_add_2inst_copy(vec3 v1, vec3 v2)
{
	return (vec3){{
		v1.e[0] + v2.e[0],
		v1.e[1] + v2.e[1],
		v1.e[2] + v2.e[2]
	}};
}

void vec3_add_2inst(vec3 *v1, vec3 *v2)
{
		v1->e[0] += v2->e[0];
		v1->e[1] += v2->e[1];
		v1->e[2] += v2->e[2];
}

vec3 vec3_sub_2inst_copy(vec3 v1, vec3 v2)
{
	return (vec3){{
		v1.e[0] - v2.e[0],
		v1.e[1] - v2.e[1],
		v1.e[2] - v2.e[2]
	}};
}

void vec3_sub_2inst(vec3 *v1, vec3 *v2)
{

	v1->e[0] -= v2->e[0];
	v1->e[1] -= v2->e[1];
	v1->e[2] -= v2->e[2];
}

