//
// Created by Mike on 2021/8/18.
//

/*
 * 146. LRU 缓存机制
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 * 实现 LRUCache 类：
 * - LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * - int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * - void put(int key, int value)。如果关键字已经存在，则变更其数据值；
 * 如果关键字不存在，则插入该组「关键字-值」。
 * 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 */

#include <iostream>
#include <unordered_map>

/*
 Define the double list.
 */
struct DoubleList
{
    int key, value;
    DoubleList *prev;
    DoubleList *next;
    DoubleList() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DoubleList(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    DoubleList *head;
    DoubleList *tail;
    std::unordered_map<int, DoubleList *> cache;

public:
    LRUCache(int _capacity) : capacity(_capacity)
    {
        head = new DoubleList();            // 虚拟头部
        tail = new DoubleList();            // 虚拟尾部
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache()
    {
        if (head != nullptr)
        {
            delete head;
            head = nullptr;
        }
        if (tail != nullptr)
        {
            delete tail;
            tail = nullptr;
        }
        for (auto &it : cache)
        {
            if (it.second != nullptr)
            {
                delete it.second;
                it.second = nullptr;
            }
        }
    }

    int get(int _key)
    {
        if (!cache.count(_key))
        {
            return -1;
        }
        DoubleList *node = cache[_key];         // hash table 中找到这个 node
        remove(node);                           // 删除此时的 node
        add(node);                              // 更新到 DoubleList 尾部
        return node->value;
    }

    void put(int _key, int _value)
    {
        if (cache.count(_key))
        {                                       // 原来 key 已经有 node
            DoubleList *node = cache[_key];     // hash table 中找到这个 node
            remove(node);                       // 删除原有的 key 的 node
            node->value = _value;               // 更新 这个 key 对应的 node
            add(node);                          // 添加到 DoubleList 中
            return;
        }
        if (cache.size() == this->capacity)
        { // 缓存满了
            int removed = head->next->key;
            remove(head->next);                 // 头部是虚拟头部，所以删除头部的下一个
            cache.erase(removed);               // 在 cache 删除对应的 node
        }
        DoubleList *node = new DoubleList(_key, _value);
        add(node);                              // 新 node 放在尾部
        cache[_key] = node;                     // 更新 新node 到 hash table
    }

    void add(DoubleList *node)
    { // 将 node 存放在尾部
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void remove(DoubleList *node)
    { // 删除当前节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

int main(int argc, const char *argv[])
{
    LRUCache *lru = new LRUCache(2);

    lru->put(2, 1);
    lru->put(1, 1);

    std::cout << lru->get(2) << std::endl;

    lru->put(4, 1);

    std::cout << lru->get(1) << std::endl;
    std::cout << lru->get(2) << std::endl;

    return 0;
}
