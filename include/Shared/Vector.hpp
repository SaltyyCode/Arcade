/*
** EPITECH PROJECT, 2025
** B-OOP-400-LIL-4-1-arcade-nicolas.dumetz
** File description:
** Vector
*/

#ifndef VECTOR_H
    #define VECTOR_H
    #include <cmath>
    
namespace Arc::Shared {

    class Vector {
        public:
            ~Vector() = default;
            Vector() : _x(0), _y(0) {}
            Vector(float x, float y) : _x(x), _y(y) {}
            Vector(const Vector& other) : _x(other._x), _y(other._y) {}
            float getX() const { return _x; }
            void setX(float x) { _x = x; }
            float getY() const { return _y; }
            void setY(float y) { _y = y; }
            float magnitude() const {
                return std::sqrt(_x * _x + _y * _y);
            }
            Vector& normalize() {
                float mag = magnitude();
                if (mag > 0) {
                    _x /= mag;
                    _y /= mag;
                }
                return *this;
            }
            float dot(const Vector& other) const {
                return _x * other._x + _y * other._y;
            }
            Vector& operator=(const Vector& other) = default;
            Vector operator+(const Vector& other) const {
                return Vector(_x + other._x, _y + other._y);
            }
            Vector operator-(const Vector& other) const {
                return Vector(_x - other._x, _y - other._y);
            }
            Vector operator*(float scalar) const {
                return Vector(_x * scalar, _y * scalar);
            }
            Vector operator/(float scalar) const {
                return Vector(_x / scalar, _y / scalar);
            }
            Vector& operator+=(const Vector& other) {
                _x += other._x;
                _y += other._y;
                return *this;
            }
            bool operator==(const Vector& other) const{
                return this->_x == other._x && this->_y == other._y;
            }
            Vector& operator-=(const Vector& other) {
                _x -= other._x;
                _y -= other._y;
                return *this;
            }
            Vector& operator*=(float scalar) {
                _x *= scalar;
                _y *= scalar;
                return *this;
            }

        private:
            float _x;  // X coordinate
            float _y;  // Y coordinate
    };
}
#endif // VECTOR_H