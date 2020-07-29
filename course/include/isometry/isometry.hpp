/*
 * Isometry library
 * Author: Agustin Alba Chicar, 2019
 * Author: Gerardo Puga, 2020
 */

#pragma once

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>

namespace ekumen {

namespace math {

class Vector3 {
 public:
  Vector3(double x, double y, double z);
  Vector3();
  double norm(void) const;

  double x(void) const;
  double &x(void);

  double y(void) const;
  double &y(void);
  
  double z(void) const;
  double &z(void);

  double dot(const Vector3& vector1) const;
  Vector3 cross(const Vector3& vector1) const;

  static const Vector3 kUnitX;
  static const Vector3 kUnitY;
  static const Vector3 kUnitZ;
  static const Vector3 kZero;

  const bool operator==(const Vector3& vector1) const;
  const bool operator!=(const Vector3& vector1) const;
  const Vector3 operator+(const Vector3& vector1) const;
  const Vector3 operator-(const Vector3& vector1) const;  
  const Vector3 operator*(const Vector3& vector1) const;
  const Vector3 operator/(const Vector3& vector1) const;
  const Vector3 operator/(const double& div) const;

  Vector3& operator+=(const Vector3& vector1);
  Vector3& operator-=(const Vector3& vector1);
  Vector3& operator*=(const Vector3& vector1);
  Vector3& operator/=(const Vector3& vector1);
  Vector3& operator*=(const double& scalar);
  Vector3& operator/=(const double& scalar);

  friend const Vector3 operator*(const Vector3& vector1, const int& scalar);
  friend const Vector3 operator*(const int& scalar, const Vector3& vector1);

  double operator[](int) const;
  double &operator[](int);

  friend std::ostream& operator<<(std::ostream &ss, const Vector3& vector1);

 private:
  double x_;
  double y_;
  double z_;
};

}  // namespace math

}  // namespace ekumen
