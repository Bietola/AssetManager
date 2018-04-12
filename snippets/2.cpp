template <class Asset>
class AssetManager {
    public:
        bool load(const std::string& path);

        const Asset& get(const std::string& key) const;

    private:
        std::unordered_map<std::string, Asset> mAssets;
};
