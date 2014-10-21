#include<iostream>
#include<map>

using namespace std;


struct cache_node_s
{
    int key;
    int value;
    struct cache_node_s *next;
    struct cache_node_s *pre;
};
typedef struct cache_node_s cache_node_t;



class LRUCache{
    private:
        map<int, cache_node_t *> node_index; 
        cache_node_t *head;
        cache_node_t *tail;
        int lru_cache_capacity;
        int cache_size;
    public:

        LRUCache(int capacity) {
            lru_cache_capacity = capacity; 
            head = malloc_cache_node(-1, -1);
            tail = malloc_cache_node(-1, -1);
            head->next = tail;
            tail->pre = head;
            cache_size = 0;
        }
        ~LRUCache()
        {
            cache_node_t *tmp;
            while(head)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        
        int get(int key) {
            map<int, cache_node_t *> :: iterator itr = node_index.find(key);
            if(itr == node_index.end())
            {
                return -1;
            }
            cache_node_t *node = node_index[key];
            move_to_head(node);
            return node->value;
        }
        cache_node_t *malloc_cache_node(int key, int value)
        {
            cache_node_t *ptr = new cache_node_t;
            ptr->key = key;
            ptr->value = value;
            ptr->next  = NULL;
            ptr->pre = NULL;
            return ptr;
        }
        void set(int key, int value) {
            map<int, cache_node_t *> :: iterator itr = node_index.find(key);
            cache_node_t *node = NULL; 
            if(itr == node_index.end())
            {
                node = malloc_cache_node(key, value);
                node_index[key] = node;
                insert_to_head(node);
                cache_size++;
                if(cache_size > lru_cache_capacity)
                {
                    cache_size--;
                    node = tail->pre;
                    tail->pre = node->pre;
                    node->pre->next = tail;
                    node_index.erase(node->key);
                    delete node;
                }
            }
            else
            {
                node = node_index[key];
                node->value = value;
                move_to_head(node);
            }
        }
        void insert_to_head(cache_node_t *node)
        {
            head->next->pre = node;
            node->next = head->next;
            node->pre = head;
            head->next = node;

        }
        void move_to_head(cache_node_t *node)
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            insert_to_head(node);
            return;
        }
};
const int test_case[][3] = {
                         {1, 2, 1},
                         {1, 1, 1},
                         {2, 2, 1},
                         {1, 4, 1},
                         {2, 1, -1},
                         {2, 2, 1},
                         {0, 0, 0}
};
/*
const int test_case[][3] = {{1, 2, 1},
                         {1, 2, 2},
                         {2, 2, 2},
                         {1, 1, 1},
                         {1, 4, 1},
                         {2, 2, -1},
                         {0, 0, 0}
};
const int test_case[][3] = {{1, 100, 1},
                         {1, 101, 2},
                         {1, 103, 3},
                         {1, 104, 4},
                         {2, 100, -1},
                         {2, 101, 2},
                         {2, 102, -1},
                         {2, 103, 3},
                         {2, 104, 4},
                         {0, 0, 0}
};
*/
int main()
{
    LRUCache lru(2);

    int idx = 0;
    while(test_case[idx][0])
    {
        if(test_case[idx][0] == 1)
        {
            lru.set(test_case[idx][1], test_case[idx][2]);
            printf("set(%d,%d)\n", test_case[idx][1], test_case[idx][2]);
        }
        else
        {
            int val = lru.get(test_case[idx][1]);
            if(val == test_case[idx][2])
            {
                printf("get(%d) PASS\n", test_case[idx][1]);
            }
            else
            {
                printf("get(%d) value FAIL\n", test_case[idx][1]);
                printf("Expect : %d\n", test_case[idx][2]);
                printf("Infact : %d\n", val);
            }
        }
        idx++;
    }

}
