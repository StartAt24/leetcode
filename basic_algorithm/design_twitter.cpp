#include <vector>
#include <map>
#include <list>
using namespace std;
class Twitter {
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        // need a map to store it
        // also need a list to store the sequence?

    }
    
    vector<int> getNewsFeed(int userId) {
        // get the feed of this target user,
        // feed contains: what this user follows and user itself.

    }
    
    void follow(int followerId, int followeeId) {
        if (_followRelation.contains(followerId)) {
            _followRelation[followerId].push_back(followeeId);
        } else {
            _followRelation[followerId] = vector<int> {followeeId};
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        _followRelation[followerId].erase(followeeId);
        if (_followRelation[followerId].size() == 0)
            _followRelation.erase(followerId);
    }
private:
    unordered_map<int, list<int>> _followRelation;

    
};