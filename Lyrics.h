#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Word.h"

class Lyrics{
private:
    
public:
    std::vector<Word> words;
    float start_time, end_time;
    void calculate_timings();
    std::string render_string(float current_time);
};