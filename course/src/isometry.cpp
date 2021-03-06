/*
 * Isometry library
 * Author: Agustin Alba Chicar, 2019
 * Author: Gerardo Puga, 2020
 * Author: Jorge J. Perez, 2020
 */
// Copyright 2020, Blast545

#include <isometry/isometry.hpp>

namespace ekumen {
namespace math {

  // Used for double comparison, not public
  static bool cmpf(double A, double B, double epsilon) {
    return (fabs(A - B) < epsilon);
  }

  Vector3::Vector3(double x, double y, double z) :
    x_{x}, y_{y}, z_{z} {}

  Vector3::Vector3() :
    x_{0.0}, y_{0.0}, z_{0.0} {}

  double Vector3::norm() const {
    return sqrt(dot(*this));
  }

  double Vector3::x() const {
    return x_;
  }

  double & Vector3::x() {
    return x_;
  }

  double Vector3::y() const {
    return y_;
  }

  double & Vector3::y() {
    return y_;
  }

  double Vector3::z() const {
    return z_;
  }

  double & Vector3::z() {
    return z_;
  }

  double Vector3::dot(const Vector3& vector1) const {
    return x_*vector1.x() + y_*vector1.y() + z_*vector1.z();
  }

  Vector3 Vector3::cross(const Vector3& vector1) const {
    return {
            y_*vector1.z() - z_*vector1.y(),
            z_*vector1.x() - x_*vector1.z(),
            x_*vector1.y() - y_*vector1.x()};
  }

  bool Vector3::operator==(const Vector3& vector1) const {
    return(
      cmpf(x_, vector1.x_, 0.00001f) &&
      cmpf(y_, vector1.y_, 0.00001f) &&
      cmpf(z_, vector1.z_, 0.00001f));
  }

  bool Vector3::operator!=(const Vector3& vector1) const {
    return(!(
      cmpf(x_, vector1.x_, 0.00001f) &&
      cmpf(y_, vector1.y_, 0.00001f) &&
      cmpf(z_, vector1.z_, 0.00001f)));
  }

  Vector3 Vector3::operator+(const Vector3& vector1) const {
    return {x_+vector1.x_, y_+vector1.y_, z_+vector1.z_};
  }

  Vector3 Vector3::operator-(const Vector3& vector1) const {
    return {x_-vector1.x_, y_-vector1.y_, z_-vector1.z_};
  }

  Vector3 Vector3::operator*(const Vector3& vector1) const {
    return {x_*vector1.x_, y_*vector1.y_, z_*vector1.z_};
  }

  Vector3 Vector3::operator/(const Vector3& vector1) const {
    return {x_/vector1.x_, y_/vector1.y_, z_/vector1.z_};
  }

  Vector3 Vector3::operator/(const double divider) const {
    return {x_/divider, y_/divider, z_/divider};
  }

  Vector3& Vector3::operator+=(const Vector3& vector1) {
    x_ += vector1.x_;
    y_ += vector1.y_;
    z_ += vector1.z_;
    return *this;
  }

  Vector3& Vector3::operator-=(const Vector3& vector1) {
    x_ -= vector1.x_;
    y_ -= vector1.y_;
    z_ -= vector1.z_;
    return *this;
  }

  Vector3& Vector3::operator*=(const Vector3& vector1) {
    x_ *= vector1.x_;
    y_ *= vector1.y_;
    z_ *= vector1.z_;
    return *this;
  }

  Vector3& Vector3::operator/=(const Vector3& vector1) {
    x_ /= vector1.x_;
    y_ /= vector1.y_;
    z_ /= vector1.z_;
    return *this;
  }

  Vector3& Vector3::operator*=(const double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    z_ *= scalar;
    return *this;
  }

  Vector3& Vector3::operator/=(const double scalar) {
    x_ /= scalar;
    y_ /= scalar;
    z_ /= scalar;
    return *this;
  }

  const Vector3 operator*(const Vector3& vector1, const int scalar) {
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  const Vector3 operator*(const int scalar, const Vector3& vector1) {
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  double Vector3::operator[](int index) const {
    if (index<0 || index>2) {
      throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
      return x_;
    } else if (index == 1) {
      return y_;
    } else {return z_;}
  }

  double & Vector3::operator[](int index) {
    if (index<0 || index>2) {
      throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
      return x_;
    } else if (index == 1) {
      return y_;
    } else {return z_;}
  }

  std::ostream& operator<<(std::ostream &ss, const Vector3& vector1) {
    ss << "(x: " << vector1.x_
       << ", y: " << vector1.y_
       << ", z: " << vector1.z_
       << ")";
    return ss;
  }

  const Vector3 Vector3::kUnitX = Vector3(1.0, 0.0, 0.0);
  const Vector3 Vector3::kUnitY = Vector3(0.0, 1.0, 0.0);
  const Vector3 Vector3::kUnitZ = Vector3(0.0, 0.0, 1.0);
  const Vector3 Vector3::kZero = Vector3(0.0, 0.0, 0.0);

}  // namespace math
}  // namespace ekumen
