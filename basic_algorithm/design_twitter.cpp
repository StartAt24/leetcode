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
        _seqTweet.push_back(std::make_pair(userId, tweetId));

    }
    
    vector<int> getNewsFeed(int userId) {
        // get the feed of this target user,
        // feed contains: what this user follows and user itself.
        int maxCount = _maxCnt;
        vector<int> ret;
        if (_followRelation.contains(userId))
        {
            auto followees = _followRelation[userId];
            for (auto i = _seqTweet.rend(); i!=_seqTweet.rbegin() && maxCount > 0; i++) {
                if (followees.find(i->first) != followees.end() || i->first == userId) {
                    ret.push_back(i->second);
                }
            }
            return ret;
        } else {
            // no followee
            // only show own tweet;
            for (auto i = _seqTweet.rend(); i!=_seqTweet.rbegin() && maxCount > 0; i++) {
                if(i->first == userId)
                    ret.push_back(i->second);
            }
            return ret;
        }

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
    unordered_map<int, vector<int>> _followRelation;
    list<pair<int, int>> _seqTweet;
    int _maxCnt = 10;
};