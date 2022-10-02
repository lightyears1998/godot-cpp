/*************************************************************************/
/*  vector4.hpp                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GODOT_VECTOR4_HPP
#define GODOT_VECTOR4_HPP

#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/core/math.hpp>

namespace godot {

class String;

class Vector4 {
	_FORCE_INLINE_ GDNativeTypePtr _native_ptr() const { return (void *)this; }

	friend class Variant;

public:
	enum Axis {
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
		AXIS_W,
	};

	union {
		struct {
			real_t x;
			real_t y;
			real_t z;
			real_t w;
		};
		real_t components[4] = { 0, 0, 0, 0 };
	};

	_FORCE_INLINE_ real_t &operator[](int idx) {
		return components[idx];
	}
	_FORCE_INLINE_ const real_t &operator[](int idx) const {
		return components[idx];
	}
	_FORCE_INLINE_ real_t length_squared() const;
	bool is_equal_approx(const Vector4 &p_vec4) const;
	real_t length() const;
	void normalize();
	Vector4 normalized() const;
	bool is_normalized() const;
	Vector4 abs() const;
	Vector4 sign() const;
	Vector4 floor() const;
	Vector4 ceil() const;
	Vector4 round() const;

	Vector4::Axis min_axis_index() const;
	Vector4::Axis max_axis_index() const;
	Vector4 clamp(const Vector4 &p_min, const Vector4 &p_max) const;

	Vector4 inverse() const;
	Vector4 lerp(const Vector4 &p_to, const real_t p_weight) const;
	_FORCE_INLINE_ real_t dot(const Vector4 &p_vec4) const;

	_FORCE_INLINE_ void operator+=(const Vector4 &p_vec4);
	_FORCE_INLINE_ void operator-=(const Vector4 &p_vec4);
	_FORCE_INLINE_ void operator*=(const Vector4 &p_vec4);
	_FORCE_INLINE_ void operator/=(const Vector4 &p_vec4);
	_FORCE_INLINE_ void operator*=(const real_t &s);
	_FORCE_INLINE_ void operator/=(const real_t &s);
	_FORCE_INLINE_ Vector4 operator+(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ Vector4 operator-(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ Vector4 operator*(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ Vector4 operator/(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ Vector4 operator-() const;
	_FORCE_INLINE_ Vector4 operator*(const real_t &s) const;
	_FORCE_INLINE_ Vector4 operator/(const real_t &s) const;

	_FORCE_INLINE_ bool operator==(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ bool operator!=(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ bool operator>(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ bool operator<(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ bool operator>=(const Vector4 &p_vec4) const;
	_FORCE_INLINE_ bool operator<=(const Vector4 &p_vec4) const;

	operator String() const;

	_FORCE_INLINE_ Vector4() {}

	_FORCE_INLINE_ Vector4(real_t p_x, real_t p_y, real_t p_z, real_t p_w) :
			x(p_x),
			y(p_y),
			z(p_z),
			w(p_w) {
	}

	Vector4(const Vector4 &p_vec4) :
			x(p_vec4.x),
			y(p_vec4.y),
			z(p_vec4.z),
			w(p_vec4.w) {
	}

	void operator=(const Vector4 &p_vec4) {
		x = p_vec4.x;
		y = p_vec4.y;
		z = p_vec4.z;
		w = p_vec4.w;
	}
};

real_t Vector4::dot(const Vector4 &p_vec4) const {
	return x * p_vec4.x + y * p_vec4.y + z * p_vec4.z + w * p_vec4.w;
}

real_t Vector4::length_squared() const {
	return dot(*this);
}

void Vector4::operator+=(const Vector4 &p_vec4) {
	x += p_vec4.x;
	y += p_vec4.y;
	z += p_vec4.z;
	w += p_vec4.w;
}

void Vector4::operator-=(const Vector4 &p_vec4) {
	x -= p_vec4.x;
	y -= p_vec4.y;
	z -= p_vec4.z;
	w -= p_vec4.w;
}

void Vector4::operator*=(const Vector4 &p_vec4) {
	x *= p_vec4.x;
	y *= p_vec4.y;
	z *= p_vec4.z;
	w *= p_vec4.w;
}

void Vector4::operator/=(const Vector4 &p_vec4) {
	x /= p_vec4.x;
	y /= p_vec4.y;
	z /= p_vec4.z;
	w /= p_vec4.w;
}
void Vector4::operator*=(const real_t &s) {
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}

void Vector4::operator/=(const real_t &s) {
	*this *= 1.0f / s;
}

Vector4 Vector4::operator+(const Vector4 &p_vec4) const {
	return Vector4(x + p_vec4.x, y + p_vec4.y, z + p_vec4.z, w + p_vec4.w);
}

Vector4 Vector4::operator-(const Vector4 &p_vec4) const {
	return Vector4(x - p_vec4.x, y - p_vec4.y, z - p_vec4.z, w - p_vec4.w);
}

Vector4 Vector4::operator*(const Vector4 &p_vec4) const {
	return Vector4(x * p_vec4.x, y * p_vec4.y, z * p_vec4.z, w * p_vec4.w);
}

Vector4 Vector4::operator/(const Vector4 &p_vec4) const {
	return Vector4(x / p_vec4.x, y / p_vec4.y, z / p_vec4.z, w / p_vec4.w);
}

Vector4 Vector4::operator-() const {
	return Vector4(x, y, z, w);
}

Vector4 Vector4::operator*(const real_t &s) const {
	return Vector4(x * s, y * s, z * s, w * s);
}

Vector4 Vector4::operator/(const real_t &s) const {
	return *this * (1.0f / s);
}

bool Vector4::operator==(const Vector4 &p_vec4) const {
	return x == p_vec4.x && y == p_vec4.y && z == p_vec4.z && w == p_vec4.w;
}

bool Vector4::operator!=(const Vector4 &p_vec4) const {
	return x != p_vec4.x || y != p_vec4.y || z != p_vec4.z || w != p_vec4.w;
}

bool Vector4::operator<(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w < p_v.w;
			} else {
				return z < p_v.z;
			}
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

bool Vector4::operator>(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w > p_v.w;
			} else {
				return z > p_v.z;
			}
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

bool Vector4::operator<=(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w <= p_v.w;
			} else {
				return z < p_v.z;
			}
		} else {
			return y < p_v.y;
		}
	} else {
		return x < p_v.x;
	}
}

bool Vector4::operator>=(const Vector4 &p_v) const {
	if (x == p_v.x) {
		if (y == p_v.y) {
			if (z == p_v.z) {
				return w >= p_v.w;
			} else {
				return z > p_v.z;
			}
		} else {
			return y > p_v.y;
		}
	} else {
		return x > p_v.x;
	}
}

_FORCE_INLINE_ Vector4 operator*(const float p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

_FORCE_INLINE_ Vector4 operator*(const double p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

_FORCE_INLINE_ Vector4 operator*(const int32_t p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

_FORCE_INLINE_ Vector4 operator*(const int64_t p_scalar, const Vector4 &p_vec) {
	return p_vec * p_scalar;
}

} // namespace godot

#endif // GODOT_VECTOR3_HPP
