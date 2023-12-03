#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
using namespace std;
#if 0
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
#endif

class Tweet{
public:
    Tweet(int id, int timestamp) : _id(id), _timestamp(timestamp) {
    }

    int ID(){
        return _id;
    }

    int Timestamp() {
        return _timestamp;
    }

private:
    int _timestamp{-1};
    int _id;
};

class User{
public:
    User(int id) : _id(id) {
    }

    int ID() {
        return _id;
    }

    void Post(Tweet t) {
        _tweets.push_back(t);
    }

    const auto& GetTweets() {
        return _tweets;
    }

    void Follow(int user) {
        _followees.insert(user);
    }

    void Unfollow(int user) {
        _followees.erase(user);
    }

    set<User> Followees() {
        auto temp = _followees;
        // add user self;
        temp.insert(*this);
        return temp;
    }

private:
    set<User> _followees;
    list<Tweet> _tweets;
    int _id;
};

class Twitter {
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        _users[userId].Post(Tweet(tweetId, _globalTimestamp++));
    }
    
    vector<int> getNewsFeed(int userId) {
        const auto& user = _users[userId];
        // get this users followee;
        const auto& followees = user.Followees();

        // 创建一个minheap
        auto cmp = [](Tweet l, Tweet r) {
            return l.Timestamp() > r.Timestamp();
        };

        std::priority_queue<Tweet, decltype(cmp)> _minHeap;

        for (const auto& followee : followees) {
            for(const auto tweet : followee.GetTweets())
                _minHeap.push(tweet);
        }

        // 合并N条有序链表
        vector<int> ret;
        int limit = _countLimit; 
        while(!_minHeap.empty() && limit) {
            auto t = _minHeap.top();
            ret.push_back(t.ID());
            _minHeap.pop();
            limit--;
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        _users[followerId].Follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        _users[followerId].Unfollow(followeeId);
    }
private:
    unordered_map<int, User> _users;
    int _globalTimestamp = 0;
    const int _countLimit = 10;
};
