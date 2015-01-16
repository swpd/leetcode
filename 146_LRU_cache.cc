class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        unordered_map<int, int>::iterator it = m.find(key);
        if (it == m.end()) return -1;
        renew(key);
        return it->second;
    }
    
    void set(int key, int value) {
        unordered_map<int, int>::iterator it = m.find(key);
        if (it != m.end()) {
            it->second = value;
            renew(key);
            return;
        }
        if (m.size() >= capacity) remove_lru();
        m[key] = value;
        renew(key);
    }
    
    void renew(int key) {
        unordered_map<int, list<int>::iterator>::iterator it = pos.find(key);
        if (it != pos.end()) pri_list.erase(it->second);
        pri_list.push_front(key);
        pos[key] = pri_list.begin();
    }
    
    void remove_lru() {
        m.erase(pri_list.back());
        pos.erase(pri_list.back());
        list<int>::iterator it = pri_list.end();
        it--;
        pri_list.erase(it);
    }
    
private:
    int capacity;
    unordered_map<int, int> m;
    list<int> pri_list;
    unordered_map<int, list<int>::iterator> pos;
};
