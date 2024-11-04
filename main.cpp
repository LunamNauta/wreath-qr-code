#include <iostream>
#include <cstdint>

enum class MODE{
    ECI, NUMERIC, ALPHANUMERIC, BYTE, KANJI,
    STRUCTURED_APPEND, FNC1_P1, FNC1_P2,
    TERMINATOR
};
std::uint8_t MODE_INDICATORS[]{
    0b0111, 0b0001, 0b0010, 0b0100, 0b1000,
    0b0011, 0b0101, 0b1001,
    0b0000
};
std::uint8_t CHARACTER_COUNT_INDICATOR_LENGTHS[]{
    10, 9, 8, 8,
    12, 11, 16, 10,
    14, 13, 16, 12
};

void encode_numeric(std::uint8_t* out, std::uint8_t* in, std::size_t count){
    std::size_t out_count = (count/3*10 + count%3/2*7 + count%3%2*4)/8;
    std::uint8_t overflow = 0;
    std::size_t a = 0;
    for (; a < count; a += 3){
        std::uint16_t tmp1 = in[a]*100 + in[a+1]*10 + in[a];
        
    }
    if (a+1 < count){
        std::uint16_t tmp1 = in[a]*10 + in[a+1];

    } else if (a < count){
        std::uint16_t tmp1 = in[a];
    }
}

int main(){

}
