#include <iostream>
#include <cstdint>

enum class Mode{
    NUMERIC, ALPHANUMERIC, BYTE, KANJI,
    STRUCTURED_APPEND, FNC1_P1, FNC1_P2,
    ECI,
};

std::uint8_t MODE_INDS[]{
    0b0001, 0b0010, 0b0100, 0b1000,
    0b0011, 0b0101, 0b1001,
    0b0111,
};
std::uint8_t CHAR_CNT_IND_LENS[]{
    10, 9, 8, 8,
    12, 11, 16, 10,
    14, 13, 16, 12
};

std::uint8_t get_terminator_length(){
    return 4;
}
std::uint8_t get_mode_indicator(Mode mode){
    return MODE_INDS[(std::size_t)mode];
}
std::uint8_t get_character_count_indicator_length(Mode mode, std::size_t version){
    if ((std::size_t)mode > 3) throw std::invalid_argument("");
    if (version <= 9) return CHAR_CNT_IND_LENS[(std::size_t)mode];
    if (version <= 26) return CHAR_CNT_IND_LENS[4+(std::size_t)mode];
    if (version <= 40) return CHAR_CNT_IND_LENS[8+(std::size_t)mode];
    throw std::invalid_argument("");
}

void encode_numeric(std::uint8_t* out, std::uint8_t* in, std::size_t siz){

}

int main(){
    std::uint8_t in[8]{0,1,2,3,4,5,6,7};
    std::uint8_t out[3]{};
    encode_numeric(out, in, 8);
    for (std::size_t a = 0; a < 3; a++){
        std::cout << +out[a] << "\n";
    }
}
