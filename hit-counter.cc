class HitCounter {
public:
    HitCounter() : count_(0) {
        
    }
    
    void hit(int timestamp) {
        getHits(timestamp);
        if (!dq_.empty() && dq_.back().first == timestamp) {
            ++dq_.back().second;
        } else {
            dq_.emplace_back(timestamp, 1);
        }
        ++count_;
    }
    
    int getHits(int timestamp) {
        while (!dq_.empty() && dq_.front().first <= timestamp - k_) {
            count_ -= dq_.front().second;
            dq_.pop_front();
        }
        return count_;
    }

private:
    const int k_ = 300;
    int count_;
    deque<pair<int, int>> dq_;
};
