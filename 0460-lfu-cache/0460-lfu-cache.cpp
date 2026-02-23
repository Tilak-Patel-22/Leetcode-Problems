class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if(!keyValFreq.count(key)) return -1;
        int val = keyValFreq[key].first;
        int freq = keyValFreq[key].second;
        freqList[freq].erase(keyIter[key]);
        if(freqList[freq].empty() && minFreq == freq) minFreq++;
        keyValFreq[key].second++;
        freqList[freq+1].push_front(key);
        keyIter[key] = freqList[freq+1].begin();
        return val;
    }

    void put(int key, int value) {
        if(cap == 0) return;
        if(keyValFreq.count(key)) {
            keyValFreq[key].first = value;
            get(key);
            return;
        }
        if(keyValFreq.size() == cap) {
            int delKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValFreq.erase(delKey);
            keyIter.erase(delKey);
        }
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};