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
  static bool almost_equal(double x, double y, int ulp) {
    return std::fabs(x-y) <=
      std::numeric_limits<double>::epsilon() * std::fabs(x+y) * ulp ||
      std::fabs(x-y) < std::numeric_limits<double>::min();
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
      almost_equal(x_, vector1.x_, 3) &&
      almost_equal(y_, vector1.y_, 3) &&
      almost_equal(z_, vector1.z_, 3));
  }

  bool Vector3::operator!=(const Vector3& vector1) const {
    return !(*this == vector1);
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

  const Vector3 operator*(const Vector3& vector1, const double scalar) {
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  const Vector3 operator*(const double scalar, const Vector3& vector1) {
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

  // Matrix --------------------------------------------

  Matrix3::Matrix3(
    const double a1, const double a2, const double a3,
    const double b1, const double b2, const double b3,
    const double c1, const double c2, const double c3) :
    rows{Vector3{a1, a2, a3}, Vector3{b1, b2, b3}, Vector3{c1, c2, c3}} {}

  Matrix3::Matrix3(
    const Vector3& row1, const Vector3& row2, const Vector3& row3) :
    rows{row1, row2, row3} { }

  Matrix3::Matrix3() :
    rows{
      Vector3{0.0, 0.0, 0.0}, Vector3{0.0, 0.0, 0.0}, Vector3{0.0, 0.0, 0.0}} {}

  const Matrix3 Matrix3::kIdentity =
    Matrix3({1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0});

  const Matrix3 Matrix3::kZero =
    Matrix3({0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0});

  const Matrix3 Matrix3::kOnes =
    Matrix3({1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0});

  bool Matrix3::operator==(const Matrix3& matrix1) const {
    return(
      rows.at(0) == matrix1.rows.at(0) &&
      rows.at(1) == matrix1.rows.at(1) &&
      rows.at(2) == matrix1.rows.at(2));
  }

  bool Matrix3::operator!=(const Matrix3& matrix1) const {
    return !(
      rows.at(0) == matrix1.rows.at(0) &&
      rows.at(1) == matrix1.rows.at(1) &&
      rows.at(2) == matrix1.rows.at(2));
  }

  Matrix3 Matrix3::operator+(const Matrix3& matrix1) const {
    return {
      rows.at(0)+matrix1.rows.at(0),
      rows.at(1)+matrix1.rows.at(1),
      rows.at(2)+matrix1.rows.at(2)};
  }

  Matrix3 Matrix3::operator-(const Matrix3& matrix1) const {
    return {
      rows.at(0)-matrix1.rows.at(0),
      rows.at(1)-matrix1.rows.at(1),
      rows.at(2)-matrix1.rows.at(2)};
  }

  Matrix3 Matrix3::operator*(const Matrix3& matrix1) const {
    return {
      rows.at(0)*matrix1.rows.at(0),
      rows.at(1)*matrix1.rows.at(1),
      rows.at(2)*matrix1.rows.at(2)};
  }

  Matrix3 Matrix3::operator/(const Matrix3& matrix1) const {
    return {
      rows.at(0)/matrix1.rows.at(0),
      rows.at(1)/matrix1.rows.at(1),
      rows.at(2)/matrix1.rows.at(2)};
  }

  Matrix3 Matrix3::operator/(const double divider) const {
    return {
      rows.at(0)/divider,
      rows.at(1)/divider,
      rows.at(2)/divider};
  }

  Matrix3 operator*(const Matrix3& matrix1, const double scalar) {
    return {
      matrix1.rows.at(0)*scalar,
      matrix1.rows.at(1)*scalar,
      matrix1.rows.at(2)*scalar};
  }

  Matrix3 operator*(const double scalar, const Matrix3& matrix1) {
    return {
      matrix1.rows.at(0)*scalar,
      matrix1.rows.at(1)*scalar,
      matrix1.rows.at(2)*scalar};
  }

  double Matrix3::det() const {
    return
      rows[0][0] * (rows[1][1]*rows[2][2] - rows[1][2]*rows[2][1]) -
      rows[0][1] * (rows[1][0]*rows[2][2] - rows[1][2]*rows[2][0]) +
      rows[0][2] * (rows[1][0]*rows[2][1] - rows[1][1]*rows[2][0]);
  }

  Vector3 operator*(const Matrix3& matrix1, const Vector3& vector1) {
    return {
      matrix1.rows.at(0).dot(vector1),
      matrix1.rows.at(1).dot(vector1),
      matrix1.rows.at(2).dot(vector1)};
  }

  Matrix3& Matrix3::operator+=(const Matrix3& matrix1) {
    rows.at(0) += matrix1.rows.at(0);
    rows.at(1) += matrix1.rows.at(1);
    rows.at(2) += matrix1.rows.at(2);
    return *this;
  }

  Matrix3& Matrix3::operator-=(const Matrix3& matrix1) {
    rows.at(0) -= matrix1.rows.at(0);
    rows.at(1) -= matrix1.rows.at(1);
    rows.at(2) -= matrix1.rows.at(2);
    return *this;
  }

  Matrix3& Matrix3::operator*=(const Matrix3& matrix1) {
    rows.at(0) *= matrix1.rows.at(0);
    rows.at(1) *= matrix1.rows.at(1);
    rows.at(2) *= matrix1.rows.at(2);
    return *this;
  }

  Matrix3& Matrix3::operator/=(const Matrix3& matrix1) {
    rows.at(0) /= matrix1.rows.at(0);
    rows.at(1) /= matrix1.rows.at(1);
    rows.at(2) /= matrix1.rows.at(2);
    return *this;
  }

  Matrix3& Matrix3::operator*=(const double scalar) {
    rows.at(0) *= scalar;
    rows.at(1) *= scalar;
    rows.at(2) *= scalar;
    return *this;
  }

  Matrix3& Matrix3::operator/=(const double scalar) {
    rows.at(0) /= scalar;
    rows.at(1) /= scalar;
    rows.at(2) /= scalar;
    return *this;
  }

  Vector3 Matrix3::operator[](const int row) const {
    return rows.at(row);
  }

  Vector3 & Matrix3::operator[](const int row) {
    return rows.at(row);
  }

  std::ostream& operator<<(std::ostream &ss, const Matrix3& matrix1) {
    ss << "[["
       << matrix1[0][0] << ", "
       << matrix1[0][1] << ", "
       << matrix1[0][2] << "], ["

       << matrix1[1][0] << ", "
       << matrix1[1][1] << ", "
       << matrix1[1][2]  << "], ["
       << matrix1[2][0] << ", "
       << matrix1[2][1] << ", "
       << matrix1[2][2]
       << "]]";
    return ss;
  }

  Vector3 Matrix3::col(const int column) const {
    return { rows.at(0)[column], rows.at(1)[column], rows.at(2)[column]};
  }

  Vector3 Matrix3::row(const int row) const {
    return rows.at(row);
  }

}  // namespace math
}  // namespace ekumen
