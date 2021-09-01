#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>

#include "Lyrics.h"
#include "Word.h"
#include "TerminalRenderer.h"

class LyricsHandler{
public:
    std::vector<Lyrics> lines;
    std::vector<std::string> split_string(std::string line, std::string token);
public:
    void loadLyrics(std::string file_path);
    void render(float current_time);
};