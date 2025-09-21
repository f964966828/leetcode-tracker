class MovieRentingSystem {
public:
    unordered_map<int, unordered_map<int, int>> price_map; // shop -> movie -> price
    unordered_map<int, set<pair<int, int>>> unrented; // (movie, [(price, shop)])
    set<tuple<int, int, int>> rented; // (price, shop, movie)

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto & entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            unrented[movie].insert({price, shop});
            price_map[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        auto & st = unrented[movie];
        vector<int> shops;
        for (auto iter = st.begin(); iter != st.end() && shops.size() != 5; iter++) {
            shops.push_back(iter->second);
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        int price = price_map[shop][movie];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = price_map[shop][movie];
        unrented[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> results;
        for (auto iter = rented.begin(); iter != rented.end() && results.size() != 5; iter++) {
            auto & [price, shop, movie] = *iter;
            results.push_back({shop, movie});
        }
        return results;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
