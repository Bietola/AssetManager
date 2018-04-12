#pragma once

#include <iostream>
#include <unordered_map>

template <class T, class = void>
struct is_asset : std::false_type {};

template <class T>
struct is_asset<T,
    std::void_t<decltype(
        std::declval<T>().loadFromFile(std::declval<const char*>())
    )>
> : std::true_type {};

template <class T>
constexpr bool is_asset_v = is_asset<T>::value;

template <class Asset>
class AssetManager {
    static_assert(is_asset_v<Asset>);

    public:
        bool load(const std::string& path);

        const Asset& get(const std::string& key) const;

    private:
        std::unordered_map<std::string, Asset> mAssets;
};

template <class Asset>
bool AssetManager<Asset>::load(const std::string& path) {
    bool success = false;

    if(Asset asset;
       success = asset.loadFromFile(path)) {
        mAssets[path] = asset;
    }
    else {
        // errors in the loading process should be handled by the asset loading function
        ;
    }

    return success;
}

template <class Asset>
const Asset& AssetManager<Asset>::get(const std::string& key) const {
    try{
        return mAssets.at(key);
    }
    catch(std::out_of_range){
        std::cout << "FATAL ERROR: trying to access nonexistent key through asset manager (key = " << key << ").\n";
        std::terminate();
    }
}
