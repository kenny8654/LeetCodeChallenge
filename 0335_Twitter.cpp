/**
Runtime: 0 ms, Beats: 100%
Memory: 14.8 MB, Beats: 5.8%
**/
#define USER_NUM 500
#define RECENT_TWEET_NUM 10
// pii: time - tweetId
#define pii pair<int,int> 
class Twitter {
private:
    typedef struct _user{
        set<int> sFollowee;
        queue<pii> qTweets;
    }user;
    user mUsers[USER_NUM];
    int cnt;

public:
    Twitter() : cnt(0){}
    
    void postTweet(int userId, int tweetId) {
        mUsers[userId].qTweets.push({cnt++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        priority_queue <pii> pq;

        auto qUserTweets = mUsers[userId].qTweets;
        while(!qUserTweets.empty()){
            pq.push(qUserTweets.front());
            qUserTweets.pop();
        }
        
        auto sFollowee = mUsers[userId].sFollowee;
        for(auto it=sFollowee.begin(); it!=sFollowee.end(); it++){
            auto qFolloweeTweets = mUsers[*it].qTweets;
            while(!qFolloweeTweets.empty()){
                pq.push(qFolloweeTweets.front());
                qFolloweeTweets.pop();
            }
        }

        while(!pq.empty() && ret.size()<RECENT_TWEET_NUM){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        mUsers[followerId].sFollowee.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mUsers[followerId].sFollowee.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
