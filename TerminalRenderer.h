#include <iostream>
#include <string>

#define terminal_x 50
#define terminal_y 20


namespace trm{

    void clear_screen(){
        std::cout << "\033[H\033[2J\033[3J";
    }

    void draw_window(std::string song_name, std::string lyrics){
        clear_screen();
        for(int i=0; i < 0.5f * (terminal_x-song_name.size()+2); ++i){
            std::cout << "#";
        }
        std::cout << " " << song_name << " ";
        for(int i=0; i < 0.5f * (terminal_x-song_name.size()+2); ++i){
            std::cout << "#";
        }
        //Gör snyggare
        std::cout << "\n" << lyrics << std::endl;

    }

}