#include "LyricsHandler.h"

#define DEBUG true
#define debug_print(a) std::cout << a << std::endl;

std::string song_name = "";

void LyricsHandler::render(float current_time){
    std::string render_string = "";
    float fade_in_time = 2.5f; 
    float fade_out_time = 0.0f; 

    for(auto & line : lines){
		if(line.start_time <= current_time + fade_in_time &&
            line.end_time >= current_time - fade_out_time){
			
            render_string += line.render_string(current_time) + "\n\n";
		}
    }

    trm::draw_window("\e[1m" + song_name + "\e[0m " + std::to_string(current_time) + "s", render_string);

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
        
        auto to_process = split_string(line, ">");
        Lyrics lyrics_line;
		
        for(std::string &str : to_process){
			if(DEBUG){ debug_print(str) }
			
            str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
            str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
            std::string lyric_word = "";
			bool isPartOfLongerWord = false;

			for(int i = 1; str.at(i) != '"'; ++i){
				lyric_word.push_back(str.at(i));
			}

			for(int marks=0, i=0; marks<2 && i < str.size(); ++i){
				if(str[0]=='"'){
					marks++;
				}
				str.erase(str.begin());
			}
			
			// \b detection
			if(lyric_word.size() > 2 && lyric_word.at(lyric_word.size()-1) == 'b'
				&& lyric_word.at(lyric_word.size()-2) == '\\'){
				
				isPartOfLongerWord = true;
				lyric_word.pop_back();
				lyric_word.pop_back();
			}
			
			auto result = split_string(str, ","); 

            Word word(std::stof(result[1]), std::stof(result[2]), lyric_word, isPartOfLongerWord);
            lyrics_line.words.push_back(word);
        }
        lyrics_line.calculate_timings();
        lines.push_back(lyrics_line);

    }
    song_name = file_path;
}