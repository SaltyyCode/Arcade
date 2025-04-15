
namespace Arc::Shared
{
    class Unit
    {
    private:
        float _pixel = 8.0f;
        int _value;
    
    public:
        Unit(int value) : _value(value) {}
        ~Unit() = default;
    
        int toPixel() const { return static_cast<int>(_value * _pixel); }
        int getValue() const { return _value; }
    
        float toFloatPixel() const { return static_cast<float>(_value) * _pixel; }
        float getFloatValue() const { return static_cast<float>(_value); }
        Unit& operator=(const Unit& other) = default;
    }; 
} // namespace Arc::Shared
