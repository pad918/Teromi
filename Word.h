#pragma once
#include <string>

struct Word{

public:
    float start_time, end_time;
    std::string text;
    bool is_part_of_word;
    
    Word(float s_time, float e_time, std::string word, bool part_of_word){
        is_part_of_word = part_of_word;
        text = word;
        start_time = s_time;
        end_time = e_time;
    }
};