#pragma once

#include <SFML/Graphics.hpp>

#include "MediaProvider.h"

///global objects and variables
extern MediaProvider<sf::Texture> gTextureProvider;
extern MediaProvider<sf::Font> gFontProvider;

///global functions
//load all media, return false on failure
extern bool load_media();
