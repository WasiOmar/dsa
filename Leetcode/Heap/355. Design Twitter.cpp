class Twitter {

    int timeStamp;

    unordered_map<int , vector<vector<int>>> userTweets;

    unordered_map<int , set<int>> followingList;

public:

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId , int tweetId) {

        userTweets[userId].push_back( { timeStamp++ , tweetId } );

    }

    vector<int> getNewsFeed(int userId) {

        vector<int> answer;

        auto cmp = []( const vector<int>& x , const vector<int>& y ) {
            return x[0] < y[0];
        };

        priority_queue<vector<int> , vector<vector<int>> , decltype(cmp)> pq(cmp);

        followingList[userId].insert(userId);

        for ( int fId : followingList[userId] ) {

            if ( userTweets.count(fId) ) {

                const vector<vector<int>>& tw = userTweets[fId];

                int idx = tw.size() - 1;

                pq.push( { tw[idx][0] , tw[idx][1] , fId , idx } );
            }
        }

        while ( !pq.empty() && answer.size() < 10 ) {

            vector<int> topTweet = pq.top();
            pq.pop();

            answer.push_back( topTweet[1] );

            int idx = topTweet[3];

            if ( idx > 0 ) {

                const vector<int>& prevTweet = userTweets[topTweet[2]][idx - 1];

                pq.push( { prevTweet[0] , prevTweet[1] , topTweet[2] , idx - 1 } );
            }
        }

        return answer;
    }

    void follow(int followerId , int followeeId) {

        followingList[followerId].insert(followeeId);

    }

    void unfollow(int followerId , int followeeId) {

        followingList[followerId].erase(followeeId);

    }
};