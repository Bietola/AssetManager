#include "media.h"

// media providers
AssetManager<sf::Texture> gTextureManager;
AssetManager<sf::Font> gFontManager;


// load all media, return false on failure
bool load_media(){
    // success/failure flag
    bool success = true;

    // load textures
    success = gTextureManager.load("assets/cat.jpg");


    return success;
}
