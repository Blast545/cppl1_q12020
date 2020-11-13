/*
 * Isometry library
 * Author: Agustin Alba Chicar, 2019
 * Author: Gerardo Puga, 2020
 * Author: Jorge J. Perez, 2020
 */


#pragma once

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <limits>

namespace ekumen {

namespace math {

class Vector3 {
 public:
  Vector3(const double x, const double y, const double z);
  Vector3();
  double norm() const;

  double x() const;
  double &x();

  double y() const;
  double &y();
  
  double z() const;
  double &z();

  double dot(const Vector3& vector1) const;
  Vector3 cross(const Vector3& vector1) const;

  static const Vector3 kUnitX;
  static const Vector3 kUnitY;
  static const Vector3 kUnitZ;
  static const Vector3 kZero;

  bool operator==(const Vector3& vector1) const;
  bool operator!=(const Vector3& vector1) const;
  Vector3 operator+(const Vector3& vector1) const;
  Vector3 operator-(const Vector3& vector1) const;
  Vector3 operator*(const Vector3& vector1) const;
  Vector3 operator/(const Vector3& vector1) const;
  Vector3 operator/(const double divider) const;

  Vector3& operator+=(const Vector3& vector1);
  Vector3& operator-=(const Vector3& vector1);
  Vector3& operator*=(const Vector3& vector1);
  Vector3& operator/=(const Vector3& vector1);
  Vector3& operator*=(const double scalar);
  Vector3& operator/=(const double scalar);

  friend const Vector3 operator*(const Vector3& vector1, const double scalar);
  friend const Vector3 operator*(const double scalar, const Vector3& vector1);

  double operator[](int) const;
  double &operator[](int);

  friend std::ostream& operator<<(std::ostream &ss, const Vector3& vector1);

 private:
  double x_;
  double y_;
  double z_;
};

class Matrix3 {
 public:
  Matrix3(
    const double a1, const double a2, const double a3,
    const double b1, const double b2, const double b3,
    const double c1, const double c2, const double c3
  );
  Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
  Matrix3();

  static const Matrix3 kIdentity;
  static const Matrix3 kOnes;
  static const Matrix3 kZero;

  bool operator==(const Matrix3& matrix1) const;
  bool operator!=(const Matrix3& matrix1) const;
  Matrix3 operator+(const Matrix3& matrix1) const;
  Matrix3 operator-(const Matrix3& matrix1) const;
  Matrix3 operator*(const Matrix3& matrix1) const;
  Matrix3 operator/(const Matrix3& matrix1) const;
  Matrix3 operator/(const double divider) const;

  friend const Matrix3 operator*(const Matrix3& matrix1, const double scalar);
  friend const Matrix3 operator*(const double scalar, const Matrix3& matrix1);

  friend const Vector3 operator*(const Matrix3& matrix1, const Vector3& vector1);

  double det() const;

  Matrix3& operator+=(const Matrix3& matrix1);
  Matrix3& operator-=(const Matrix3& matrix1);
  Matrix3& operator*=(const Matrix3& matrix1);
  Matrix3& operator/=(const Matrix3& matrix1);
  Matrix3& operator*=(const double scalar);
  Matrix3& operator/=(const double scalar);

  friend std::ostream& operator<<(std::ostream &ss, const Matrix3& matrix1);

  Vector3 col(const int column) const;
  Vector3 row(const int row) const;

  Vector3 operator[](const int) const;
  Vector3 &operator[](const int);

 private:
   std::array<Vector3, 3> rows;
};
  
}  // namespace math

}  // namespace ekumen
