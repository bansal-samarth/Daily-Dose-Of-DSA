class LRUCache {
public:
    queue<int> q;
    unordered_map<int,int> map;
    unordered_map<int,int> cnt;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(!map.count(key))
            return -1;
        
        cnt[key]++;
        q.push(key);
        return map[key];
    }
    
    void put(int key, int value) {
        
        map[key] = value;
        cnt[key]++;
        q.push(key);

        while (cnt.size() > size) {
            int val = q.front();
            q.pop();
            cnt[val]--;

            if(cnt[val] == 0) {
                map.erase(val);
                cnt.erase(val);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */