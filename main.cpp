#include "LRUCache.h"

int main(int argc, char **argv) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(2);
    cache.put(3, 3);

    return 0;
}