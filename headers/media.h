#pragma once

#include <SFML/Graphics.hpp>

#include "AssetManager.h"

// managers
extern AssetManager<sf::Texture> gTextureManager;
extern AssetManager<sf::Font> gFontManager;

// loads all assets managers
extern bool load_media();
