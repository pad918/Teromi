#pragma once
#include <string>

/*

    String-related functions.

*/

inline int getLastOccuranceOfChar(std::string string, char chr){
    for(int pos = string.size()-1; pos>=0; pos--){
        if(string.at(pos) != chr){
            continue;
        }
        else{
            return pos;
        }
    }
    return -1;
}

inline int getFirstOccuranceOfChar(std::string string, char chr){
    int pos = 0;
    for(auto & character : string){
        if(character != chr){
            pos++;
        }
        else{
            return pos;
        }
    }
    return -1;
}

inline void removeEveryThingBefore(std::string & string, int pos){
    for(int i = 0; i < pos && string.size() > 0; ++i){
        string.pop_back();
    }
}

inline std::string getFileType(std::string file_path){
    int dot_pos = getFirstOccuranceOfChar(file_path, '.');
    if(dot_pos==-1){
        return ""; // If not file, or is lacking a filetype return ""
    }

    std::string type = "";
    for(int i = dot_pos+1; i < file_path.size(); ++i){
        type += file_path[i];
    }
    return type;
}