// https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    
    map<int, list<pair<int,int>>::iterator> pos_map;
    list<pair<int, int>> q;
    int cap;
        
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(pos_map.find(key) != pos_map.end()) {
            list<pair<int,int>>::iterator next_pos, pos = pos_map[key];
            int value = (*pos).second;
            next_pos = pos;
            advance(next_pos, 1);
            q.erase(pos, next_pos);
            q.push_front(make_pair(key, value));
            pos_map[key] = q.begin();
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(pos_map.find(key) == pos_map.end()) {
            if(q.size() == cap) {
                // list<pair<int,int>>::iterator itr = q.rbegin();
                pos_map.erase((*q.rbegin()).first);
                q.pop_back();   
            }
            
        } else {
            list<pair<int,int>>::iterator next_pos, pos = pos_map[key];
            next_pos = pos;
            advance(next_pos, 1);
            q.erase(pos, next_pos);
        }
        q.push_front(make_pair(key, value));
        pos_map[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
