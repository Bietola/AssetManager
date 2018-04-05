#pragma once

#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>

/******************************************************************/
/* meta function to determine if given type is a valid asset type */
/******************************************************************/
template <class Asset, class = void>
struct is_asset : std::false_type {};

// asset object has to:
//     -) provide a valid loadFromFile(const char*) method
template <class Asset>
struct is_asset<Asset,
    std::void_t<decltype(
        std::declval<Asset>().loadFromFile(std::declval<const char*>())
    )>
> : std::true_type {};

// template variable alias
template <class Asset>
constexpr bool is_asset_v = is_asset<Asset>::value;

/**********************/
/* AssetManager class */
/**********************/
template <class Asset>
class AssetManager {
    // assert
    static_assert(is_asset_v<Asset>);

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
        // asset container
        std::map<std::string, Asset> mAssets;
};


/***********************************/
/* ediaProvider function templates */
/***********************************/
// load generic asset object into a asset container
template <class Asset>
bool AssetManager<Asset>::load(std::initializer_list<AssetManager::StringPair> paths) {
    // return value
    bool ret = true;
    // attempt to initialize asset one by one
    for(const auto& ele : paths) {
        // tmp
        Asset asset;
        // load asset
        if(ret &= asset.loadFromFile(ele.second)) {
            // add asset to asset container
            mAssets[ele.first] = asset;
        }
        else{
            // errors in the loading process should be handled by the asset loading function
            ;
        }
    }
    // return success
    return ret;
}

// retrieve a generic asset object from a container
template <class Asset>
const Asset& AssetManager<Asset>::get(const std::string& key) const {
    // attempt to retrieve asset by key
    try{
        return mAssets.at(key);
    }
    catch(std::out_of_range){
        // terminate program
        std::cout << "FATAL ERROR: trying to access nonexistent key through asset manager (key = " << key << ")." << std::endl;
        std::terminate();
    }
}
template <class Asset>
const Asset* AssetManager<Asset>::getPtr(const std::string& key) const {
    return &get(key);
}
