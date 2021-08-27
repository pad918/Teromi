#include "Lyrics.h"

void Lyrics::calculate_timings(){
    start_time = words.front().start_time;
    end_time   = words.back().end_time;
}

std::string Lyrics::render_string(float current_time){
    std::string render = "";

    for(auto word : words){
        if(word.start_time <= current_time && word.end_time >= current_time){
            
            //Add word and make it bold with escape characters
            render += "\e[1m" + word.text + "\e[0m ";
        }
        else{
            render += word.text + (word.is_part_of_word ? "" : " ");
        }
    }
    return render;
}