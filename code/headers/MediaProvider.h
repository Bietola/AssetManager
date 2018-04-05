#pragma once

#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>

/******************************************************************/
/* meta function to determine if given type is a valid media type */
/******************************************************************/
template <class T, class = void>
struct is_media : std::false_type {};

// media object has to:
//     -) provide a valid loadFromFile(const char*) method
template <class T>
struct is_media<T,
    std::void_t<decltype(
        std::declval<T>().loadFromFile(std::declval<const char*>())
    )>
> : std::true_type {};

// template variable alias
template <class T>
constexpr bool is_media_v = is_media<T>::value;

/**********************/
/* AssetManager class */
/**********************/
template <class Asset>
class AssetManager {
    // assert
    static_assert(is_media_v<Asset>);

    public:
        // aliases
        using StringPair = std::pair<std::string, std::string>;

        // load assets
        bool load(std::initializer_list<StringPair> paths);

        // provider access to assets
        const Asset& get(const std::string& key) const;
        const Asset* getPtr(const std::string& key) const;
		const Asset& operator[](const std::string& key) const { return get(key); }

    private:
        // media container
        std::map<std::string, Asset> mAssets;
};


/***********************************/
/* ediaProvider function templates */
/***********************************/
// load generic media object into a media container
template <class T>
bool AssetManager<T>::load(std::initializer_list<AssetManager::StringPair> paths) {
    // return value
    bool ret = true;
    // attempt to initialize media one by one
    for(const auto& ele : paths) {
        // tmp
        T media;
        // load media
        if(ret &= media.loadFromFile(ele.second)) {
            // add media to media container
            mAssets[ele.first] = media;
        }
        else{
            // errors in the loading process should be handled by the media loading function
            ;
        }
    }
    // return success
    return ret;
}

// retrieve a generic media object from a container
template <class T>
const T& AssetManager<T>::getMedia(const std::string& key) const {
    // attempt to retrieve media by key
    try{
        return mAssets.at(key);
    }
    catch(std::out_of_range){
        // terminate program
        std::cout << "FATAL ERROR: trying to access nonexistent key through media provider (key = " << key << ")." << std::endl;
        std::terminate();
    }
}
template <class T>
const T* AssetManager<T>::getMediaPtr(const std::string& key) const {
    return &getMedia(key);
}
