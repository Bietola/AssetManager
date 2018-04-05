#include "media.h"

///global objects and variables
//media providers
MediaProvider<sf::Texture> gTextureProvider;
MediaProvider<sf::Font> gFontProvider;

///global functions
//load all media, return false on failure
bool load_media(){
    //success/failure flag
    bool success = true;
    //load textures
    success &= gTextureProvider.loadMedia({
        {"cat", "assets/cat.jpg"},
    });
    //load fonts
    /* success &= gFontProvider.loadMedia({ */
    /*     ... */
    /* }); */
    //return
    return success;
}
