#include <list>
#include <unordered_map>
#include <assert.h>

using namespace std;

template <class KEY_T, class VAL_T> class LRU_Cache{
public:
        LRU_Cache(int cache_size):cache_size_(cache_size){
                ;
        };

        void put(const KEY_T &key, const VAL_T &val){
                auto it = item_map_.find(key);

                if(it != item_map_.end()){
                        item_list_.erase(it->second);
                        item_map_.erase(it);
                }

                item_list_.push_front(make_pair(key,val));
                item_map_.insert(make_pair(key, item_list_.begin()));
                clean();
        };

        bool exist(const KEY_T &key){
                return (item_map.count(key) > 0);
        };

        VAL_T get(const KEY_T &key){
                assert(exist(key));
                auto it = item_map.find(key);
                item_list.splice(item_list.begin(), item_list, it->second);
                return it->second->second;
        };


private:
        list< pair<KEY_T,VAL_T> > item_list_;
        unordered_map<KEY_T, decltype(item_list_.begin()) > item_map_;
        size_t cache_size_;
        void clean(void){
                while(item_map_.size() > cache_size_){
                        auto last_it = item_list_.end(); 
                        last_it--;
                        item_map_.erase(last_it->first);
                        item_list_.pop_back();
                }
        };

}