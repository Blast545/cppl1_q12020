#ifndef ISOMETRY_H
#define	ISOMETRY_H

#include <string>

namespace ekumen {
namespace math {

class Vector3 {
 public:
  Vector3(double x, double y, double z);
  Vector3();
  double norm(void) const;
  double x(void) const;
  double y(void) const;
  double z(void) const;
  double dot(const Vector3& vector1) const;
  Vector3 cross(const Vector3& vector1) const;

  static const Vector3 kUnitX;
  static const Vector3 kUnitY;
  static const Vector3 kUnitZ;
  static const Vector3 kZero;

  // Is it there any way to define these functions without the friend declaration?
  friend const bool operator==(const Vector3& vector1, const Vector3& vector2);
  friend const bool operator!=(const Vector3& vector1, const Vector3& vector2);
  friend const Vector3 operator+(const Vector3& vector1, const Vector3& vector2);
  friend const Vector3 operator-(const Vector3& vector1, const Vector3& vector2);
  friend const Vector3 operator*(const Vector3& vector1, const int& scalar);
  friend const Vector3 operator*(const int& scalar, const Vector3& vector1);
  friend const Vector3 operator*(const Vector3& vector1, const Vector3& vector2);
  friend const Vector3 operator/(const Vector3& vector1, const Vector3& vector2);  
  friend const Vector3 operator*(const Vector3& vector1, const Vector3& vector2);
  double operator[](int) const;
  // friend const void operator<<(std::stringstream& stream_, const Vector3& vector);

 private:
  double x_;
  double y_;
  double z_;
  // const int value_{};
};

} // math
} // ekumen

#endif
