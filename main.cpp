#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <utility>
#include <unistd.h>
#include "Menu.h"
#include "LyricsHandler.h"

int main(){

    //TEST
    main_menu();
    //END OF TEST
    return 0;
    std::string song_path = "dark.flac";

    sf::Music music;
    if (!music.openFromFile(song_path))
        return -1;
	
    music.play();
    music.setPlayingOffset(sf::seconds(55.0f));
    std::cout << "Playing audio...\n";
    
	LyricsHandler LH;
	LH.loadLyrics("text.txt");
	
	for(float i = 0; i < 60.0f * 10;){
		i = music.getPlayingOffset().asSeconds();
		LH.render(i+/*temp offset*/0.03f);
		usleep(10000);
	}
	
    int c = 0;
    std::cin >> c;
}