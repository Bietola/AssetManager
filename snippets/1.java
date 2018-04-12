//initialization
AssetManager manager = new AssetManager();

// loading assets
manager.load("data/mytexture.png", Texture.class);
manager.load("data/myfont.fnt", BitmapFont.class);
manager.load("data/mymusic.ogg", Music.class);

// retrieving assets
Texture tex = manager.get("data/mytexture.png", Texture.class);
BitmapFont font = manager.get("data/myfont.fnt", BitmapFont.class);

// retrieving assets with check
if(manager.isLoaded("data/other_texture.png")) {
	Texture tex = manager.get("data/other_texture.png", Texture.class);
}
