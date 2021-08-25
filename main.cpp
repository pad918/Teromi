#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <utility>
#include <unistd.h>
#include "LyricsHandler.h"

int main(){

    std::string song_path = "test.flac";

    sf::Music music;
    if (!music.openFromFile(song_path))
        return -1;
	
    music.play();
    std::cout << "Playing audio...\n";
    
	LyricsHandler LH;
	LH.loadLyrics("text.txt");
	
	for(float i = 0; i < 10.0f;){
		i = music.getPlayingOffset().asSeconds();
		LH.render(i);
		usleep(100000);
	}
	
    int c = 0;
    std::cin >> c;
}