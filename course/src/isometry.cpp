/*
 * Isometry library
 * Author: Agustin Alba Chicar, 2019
 * Author: Gerardo Puga, 2020
 */

#include <isometry/isometry.hpp>

namespace ekumen {
namespace math {

  Vector3::Vector3(double x, double y, double z) :
    x_(x), y_(y), z_(z) {};

  Vector3::Vector3() :
    x_(1.0), y_(2.0), z_(3.0) {};

  double Vector3::norm(void) const{
    return sqrt(pow(x_,2) + pow(y_,2) + pow(z_,2));
  }

  double Vector3::x(void) const{
    return x_;
  }

  double & Vector3::x(void) {
    return x_;
  }

  double Vector3::y(void) const{
    return y_;
  }

  double & Vector3::y(void) {
    return y_;
  }

  double Vector3::z(void) const{
    return z_;
  }

  double & Vector3::z(void) {
    return z_;
  }

  double Vector3::dot(const Vector3& vector1) const{
    return x_*vector1.x() + y_*vector1.y() + z_*vector1.z();
  }
  
  Vector3 Vector3::cross(const Vector3& vector1) const{
    return Vector3(
		   y_*vector1.z() - z_*vector1.y(),
		   z_*vector1.x() - x_*vector1.z(),
		   x_*vector1.y() - y_*vector1.x());
  }

  const bool Vector3::operator==(const Vector3& vector1) const {
    return(
      (x_==vector1.x_) &&
      (y_==vector1.y_) &&
      (z_==vector1.z_));
  }

  const bool Vector3::operator!=(const Vector3& vector1) const{
    return(!(
      (x_==vector1.x_) &&
      (y_==vector1.y_) &&
      (z_==vector1.z_)
    ));
  }

  const Vector3 Vector3::operator+(const Vector3& vector1) const{
    return Vector3(x_+vector1.x_, y_+vector1.y_, z_+vector1.z_);
  }

  const Vector3 Vector3::operator-(const Vector3& vector1) const{
    return Vector3(x_-vector1.x_, y_-vector1.y_, z_-vector1.z_);
  }

  const Vector3 Vector3::operator*(const Vector3& vector1) const{
    return Vector3(x_*vector1.x_, y_*vector1.y_, z_*vector1.z_);
  }

  const Vector3 Vector3::operator/(const Vector3& vector1) const{
    return Vector3(x_/vector1.x_, y_/vector1.y_, z_/vector1.z_);
  }

  const Vector3 operator*(const Vector3& vector1, const int& scalar){
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  const Vector3 operator*(const int& scalar, const Vector3& vector1){
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  double Vector3::operator[](int index) const{
    if(index<0 || index>2){
      return std::numeric_limits<double>::quiet_NaN();
    }
    else if(index==0) return x_;
    else if(index==1) return y_;
    else return z_;
  }

  double & Vector3::operator[](int index) {
    // How do I implement this check to return a valid reference?
    /*
    if(index<0 || index>2){
      return -1.0;
    }
    */
    if(index==0) return x_;
    else if(index==1) return y_;
    else return z_;
  }

  std::stringstream& operator<<(std::stringstream &ss, const Vector3& vector1){
    ss << "(x: " << vector1.x_
       << ", y: " << vector1.y_
       << ", z: " << vector1.z_
       << ")";
    return ss;
  }

  const Vector3 Vector3::kUnitX = Vector3(1.0, 0.0, 0.0);
  const Vector3 Vector3::kUnitY = Vector3(0.0, 1.0, 0.0);
  const Vector3 Vector3::kUnitZ = Vector3(0.0, 0.0, 1.0);
  const Vector3 Vector3::kZero = Vector3(1.0, 2.0, 3.0);

}  // namespace math
}  // namespace ekumen
