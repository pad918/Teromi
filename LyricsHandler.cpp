#include "LyricsHandler.h"
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include "TerminalRenderer.h"


void LyricsHandler::render(float current_time){
    trm::draw_window("\e[1mBad Apple\e[0m " + std::to_string(current_time) + "s", lines.front().render_string(current_time));
}

std::vector<std::string> LyricsHandler::split_string(std::string line, std::string token){
    size_t pos;
    std::vector<std::string> words;
    while ((pos = line.find(token)) != std::string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + token.length());
    }
    if(line!=""){
        words.push_back(line);
    }
    return words;
}

void LyricsHandler::loadLyrics(std::string file_path){
    
    std::string line;
    std::ifstream infile(file_path);
    
    while(std::getline(infile, line)){
        //TEST IF VALID LINE FIRST
        
        auto to_process = split_string(line, ">");
        Lyrics lyrics_line;
		
        for(auto &str : to_process){
            str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
            str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
            str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
            auto result = split_string(str, ","); 
            Word word(std::stof(result[1]), std::stof(result[2]), result[0], false);
            lyrics_line.words.push_back(word);
        }
        lyrics_line.calculate_timings();
        lines.push_back(lyrics_line);

    }

}