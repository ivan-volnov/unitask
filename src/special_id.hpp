#ifndef SPECIAL_ID_HPP
#define SPECIAL_ID_HPP

#include <array>
#include <cassert>
#include <string>

namespace uni {


/** The class represents a special ID

    The first sequence identifier is A1, the second is A2,
    the third is A3 and so on. A9 is followed by B1.
    The next after Z9 is A1-A1, then A1-A2 and so on.
    Id A2-A1 is followed by A1-Z9.
    The maximum length of an identifier is 10 sections of two characters.
    It should never contain the letters D, F, G, J, M, Q, V and number 0

    The alphabets are:
    ABCEHIKLNOPRSTUWXYZ
    123456789
*/
class SpecialId
{
    // Use table lookup for fastest and easiest parsing
    static const constexpr std::string_view Sequence = "A1A2A3A4A5A6A7A8A9"
                                                       "B1B2B3B4B5B6B7B8B9"
                                                       "C1C2C3C4C5C6C7C8C9"
                                                       "E1E2E3E4E5E6E7E8E9"
                                                       "H1H2H3H4H5H6H7H8H9"
                                                       "I1I2I3I4I5I6I7I8I9"
                                                       "K1K2K3K4K5K6K7K8K9"
                                                       "L1L2L3L4L5L6L7L8L9"
                                                       "N1N2N3N4N5N6N7N8N9"
                                                       "O1O2O3O4O5O6O7O8O9"
                                                       "P1P2P3P4P5P6P7P8P9"
                                                       "R1R2R3R4R5R6R7R8R9"
                                                       "S1S2S3S4S5S6S7S8S9"
                                                       "T1T2T3T4T5T6T7T8T9"
                                                       "U1U2U3U4U5U6U7U8U9"
                                                       "W1W2W3W4W5W6W7W8W9"
                                                       "X1X2X3X4X5X6X7X8X9"
                                                       "Y1Y2Y3Y4Y5Y6Y7Y8Y9"
                                                       "Z1Z2Z3Z4Z5Z6Z7Z8Z9";

    static const constexpr auto MaxSections = 10;
    static const constexpr auto MaxValue = 19 * 9;

    using SectionArrayType = std::array<uint8_t, MaxSections>;

public:
    constexpr SpecialId() = default;

    constexpr SpecialId(std::string_view sv)
    {
        assign(sv);
    }

    constexpr SpecialId &operator=(std::string_view sv)
    {
        return assign(sv);
    }

    constexpr SpecialId &assign(std::string_view sv)
    {
        static_assert(Sequence.size() == MaxValue * 2);
        if (sv.empty()) {
            throw std::runtime_error("SpecialId parsing error");
        }

        // Due to strong exception guarantee we must ensure first that parsing is success
        SectionArrayType value{};
        auto pos = std::string_view::npos;

        // Iterate by 2 bytes from the end of the string
        for (auto &section : value) {
            if (sv.size() < 2 ||
                (pos = Sequence.find(sv.substr(sv.size() - 2, 2))) ==
                    std::string_view::npos) {
                break;
            }
            section = pos / 2 + 1;
            sv.remove_suffix(2 + (sv.size() > 2 && sv[sv.size() - 3] == '-'));
        }

        if (!sv.empty()) {
            throw std::runtime_error("SpecialId parsing error");
        }

        // Everything is ok. Assign the parsed value
        _value = value;

        return *this;
    }

    constexpr SpecialId &operator++()
    {
        for (int i{};;) {
            // Increment the value
            if (++_value[i] <= MaxValue) {
                break;
            }

            // Reset current section to A1
            _value[i] = 1;

            // Handle the case where all sections are full
            if (++i >= MaxSections) {
                _value = {1};
                break;
            }
        }
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

        // Reserve 3 symbols per section - 1 for first separator
        str.reserve(MaxSections * 3 - 1);

        int i;
        for (const auto &section : _value) {
            if (!section) {
                break;
            }
            // Calculate the index
            i = (section - 1) * 2;

            // It should never happen. But check for sure in debug mode
            assert(i < Sequence.size());

            // Add the separator and placeholders
            str.insert(0, 3, '-');

            // Write the section string representation
            str[0] = Sequence[i];
            str[1] = Sequence[i + 1];
        }

        // Strip trailing separator
        if (!str.empty() && str.back() == '-') {
            str.resize(str.size() - 1);
        }

        return str;
    }

private:
    SectionArrayType _value{1};
};


} // namespace uni

#endif // SPECIAL_ID_HPP
