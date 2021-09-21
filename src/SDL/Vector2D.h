#ifndef Vector2D_H
#define Vector2D_H

#include <cfloat>
#include <climits>

/*The Vector2D class is an object consisting of simply an x and
  y value. Certain operators are overloaded to make it easier
  for vector math to be performed.*/

class Vector2D {
public:
    /*The x and y values are public to give easier access for
      outside funtions. Accessors and mutators are not really
      necessary*/
    float x;
    float y;

    //Constructor assigns the inputs to x and y.
    Vector2D();
    Vector2D(float, float);

    /*The following operators simply return Vector2Ds that
      have operations performed on the relative (x, y) values*/
    Vector2D operator+(const Vector2D&) const;
    Vector2D operator-(const Vector2D&) const;
    Vector2D operator*(const Vector2D&) const;
    Vector2D operator/(const Vector2D&) const;

    //Check if the Vectors have the same values.
    bool operator==(const Vector2D&) const;

    /*Check which Vectors are closer or further from the
      origin.*/
    bool operator>(const Vector2D&) const;
    bool operator<(const Vector2D&) const;
    bool operator>=(const Vector2D&) const;
    bool operator<=(const Vector2D&) const;

    //Negate both the x and y values.
    Vector2D operator-() const;

    //Apply scalar operations.
    Vector2D operator*(const float&) const;
    Vector2D operator/(const float&) const;

    //Product functions
    static float DotProduct(const Vector2D&, const Vector2D&);
    static float CrossProduct(const Vector2D&, const Vector2D&);

    //Returns the length of the vector from the origin.
    static float Magnitude(const Vector2D&);

    //Return the unit vector of the input
    static Vector2D Normal(const Vector2D&);

    //Return a vector perpendicular to the left.
    static Vector2D Perpendicular(const Vector2D&);

    //Return true if two line segments intersect.
    static bool Intersect(const Vector2D&, const Vector2D&, const Vector2D&, const Vector2D&);

    //Return the point where two lines intersect.
    static Vector2D GetIntersect(const Vector2D&, const Vector2D&, const Vector2D&, const Vector2D&);
};

#endif
