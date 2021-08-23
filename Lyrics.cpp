#include "Lyrics.h"

void Lyrics::calculate_timings(){
    std::cout << "TEST\n";
    //startTime = timings.front().start;
    //endTime = timings.back().end;
}

std::string Lyrics::render_string(float current_time){
    std::string render = "";
    for(int i=0; i < words.size(); ++i){
        if(timings[i].start <= current_time &&
            timings[i].end >= current_time){
                render += "\e[1m" + words[i] + "\e[0m ";
        }
        else{
            render += words[i] + " ";
        }
    }
    return render;
}