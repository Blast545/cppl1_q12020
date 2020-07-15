#include "isometry.h"
#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>

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

  double Vector3::y(void) const{
    return y_;
  }

  double Vector3::z(void) const{
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

  const bool operator==(const Vector3& vector1, const Vector3& vector2){
    return(
      (vector1.x_==vector2.x_) &&
      (vector1.y_==vector2.y_) &&
      (vector1.z_==vector2.z_));
  }

  const bool operator!=(const Vector3& vector1, const Vector3& vector2){
    return(!(
      (vector1.x_==vector2.x_) &&
      (vector1.y_==vector2.y_) &&
      (vector1.z_==vector2.z_)
    ));
  }

  const Vector3 operator+(const Vector3& vector1, const Vector3& vector2){
    return Vector3(vector1.x_+vector2.x_, vector1.y_+vector2.y_, vector1.z_+vector2.z_);
  }

  const Vector3 operator-(const Vector3& vector1, const Vector3& vector2){
    return Vector3(vector1.x_-vector2.x_, vector1.y_-vector2.y_, vector1.z_-vector2.z_);
  }

  const Vector3 operator*(const Vector3& vector1, const int& scalar){
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  const Vector3 operator*(const int& scalar, const Vector3& vector1){
    return Vector3(vector1.x_*scalar, vector1.y_*scalar, vector1.z_*scalar);
  }

  const Vector3 operator*(const Vector3& vector1, const Vector3& vector2){
    return Vector3(vector1.x_*vector2.x_, vector1.y_*vector2.y_, vector1.z_*vector2.z_);
  }

  const Vector3 operator/(const Vector3& vector1, const Vector3& vector2){
    return Vector3(vector1.x_/vector2.x_, vector1.y_/vector2.y_, vector1.z_/vector2.z_);
  }

  double Vector3::operator[](int index) const{
    if(index<0 || index>2){
      return std::numeric_limits<double>::quiet_NaN();
    }
    else if(index==0) return x_;
    else if(index==1) return y_;
    else return z_;
  }

  // I can't get this to compile idk why
  /*
  const void operator<<(std::stringstream& stream_, const Vector3& vector){
    stream_ << "hey";
    
    // stream_ << "(x: " << vector.x_
    // 	    << ", y: " << vector.y_
    // 	    << ", z: " << vector.z_
    // 	    << ")";
  }
  */
    
  const Vector3 Vector3::kUnitX = Vector3(1.0, 0.0, 0.0);
  const Vector3 Vector3::kUnitY = Vector3(0.0, 1.0, 0.0);
  const Vector3 Vector3::kUnitZ = Vector3(0.0, 0.0, 1.0);
  const Vector3 Vector3::kZero = Vector3(1.0, 2.0, 3.0);

}
}
