#pragma once
#include <iostream>
#include <vector>
#include <utility>

struct time_point
{
    float start;
    float end;
    time_point(float s, float e){
        start = s;
        end = e;
    }
};


class Lyrics{
private:
    
public:
    std::vector<std::string> words;
    std::vector<time_point> timings;
    float startTime, endTime;
    void calculate_timings();
    std::string render_string(float current_time);
};