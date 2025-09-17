using my_pair = pair<int, string>;
using my_priority_queue = priority_queue<my_pair, vector<my_pair>, greater<my_pair>>;

class FoodRatings {
public:
    map<string, my_pair> food_map;
    map<string, my_priority_queue> cuisine_map;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food_map[foods[i]] = {ratings[i], cuisines[i]};
            cuisine_map[cuisines[i]].push({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_map[food].second;
        food_map[food] = {newRating, cuisine};
        cuisine_map[cuisine].push({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisine_map[cuisine];
        while (-pq.top().first != food_map[pq.top().second].first) pq.pop();
        return pq.top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
