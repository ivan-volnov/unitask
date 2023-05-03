#ifndef SPECIAL_ID_HPP
#define SPECIAL_ID_HPP

#include <array>
#include <string>

namespace uni {


/** The class represents a special ID

    The first sequence identifier is A1, the second is A2,
    the third is A3 and so on. A9 is followed by B1.
    The next after Z9 is A1-A1, then A1-A2 and so on.
    Id A1-Z9 is followed by A2-A1.
    The maximum length of an identifier is ten groups of two characters.
    It should never contain the letters D, F, G, J, M, Q, V and number 0
*/
class SpecialId
{
    static const constexpr auto AlphaSequence = "ABCEHIKLNOPRSTUWXYZ";
    static const constexpr auto BetaSequence = "123456789";
    static const constexpr auto MaxSections = 10;

    struct Section
    {
        // TODO: Find a way to pack it more compactly into just one byte
        uint8_t alpha : 5; // Need 19 use 2^5 = 32
        uint8_t beta  : 4; // Need  9 use 2^4 = 16
    };

public:
    constexpr SpecialId() = default;

    constexpr SpecialId(std::string_view sw)
    {
        assign(sw);
    }

    constexpr SpecialId &operator=(std::string_view sw)
    {
        return assign(sw);
    }

    constexpr SpecialId &assign(std::string_view sw)
    {
        // TODO: Implement me
        return *this;
    }

    constexpr SpecialId &operator++()
    {
        // TODO: Implement me
        return *this;
    }

    constexpr SpecialId operator++(int)
    {
        auto old = *this;
        operator++();
        return old;
    }

    std::string to_string() const
    {
        std::string str;
        // TODO: Implement me
        return str;
    }

private:
    std::array<Section, MaxSections> _sections{};
};


} // namespace uni

#endif // SPECIAL_ID_HPP
