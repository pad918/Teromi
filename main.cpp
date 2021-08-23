#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <utility>
#include<unistd.h>
#include "TerminalRenderer.h"
#include "Lyrics.h"

int main(){

    std::string song_path = "test.flac";

    std::cout << "Testing audio playback through sfml\n";

    sf::Music music;
    if (!music.openFromFile(song_path))
        return -1;
    music.play();
    std::cout << "Playing audio...\n";
    
    trm::draw_window("Fall in the dark", "demo sunao ni ienai say be cool, stay be nice");

    Lyrics lyrics;
    lyrics.words.push_back("Demo");
    lyrics.words.push_back("sunao");
    lyrics.words.push_back("ni");
    lyrics.words.push_back("ienai");
    lyrics.words.push_back("stay");

    lyrics.words.push_back("Test");

    lyrics.timings.push_back(time_point(1, 2));
    lyrics.timings.push_back(time_point(2, 3));
    lyrics.timings.push_back(time_point(3, 4));
    lyrics.timings.push_back(time_point(4, 5));
    lyrics.timings.push_back(time_point(5, 6));
    lyrics.calculate_timings();
    for(float time=0; time<10; time += 0.1){
        usleep(100000);
        trm::draw_window("\e[1mFall in the dark\e[0m " + std::to_string(time) + "s", lyrics.render_string(time));
    }

    int c = 0;
    std::cin >> c;
}