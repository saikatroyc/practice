import collections

class LRUCache(object):
    def __init__(self, capacity=10):
        self._capacity = capacity
        self._cache = collections.OrderedDict()

    def get(self, key):
        if key not in self._cache:
            raise KeyError
        val = self._cache[key]
        del self._cache[key]
        self._cache[key] = val

    def set(self, key, val):
        if key in self._cache:
            del self._cache[key]
            self._capacity = self._capacity + 1

        if self._capacity == 0:
            self._cache.popitem(last=False)
            self._capacity = self._capacity + 1


        self._cache[key] = val
        self._capacity = self._capacity - 1

    def delete(self, key):
        if key not in self._cache:
            raise KeyError

        del self._cache[key]
        self._capacity = self._capacity + 1

    def peek_oldest(self):
        if not self._cache:
            raise KeyError
        for k,v in self._cache.iteritems():
            return (k,v)

    def peek_latest(self):
        if not self._cache:
            raise KeyError
        items = self._cache.keys()
        return items[-1], self._cache[items[-1]]
    def peek_keys(self):
        return self._cache.keys()

cache = LRUCache(3)
cache.set('1', 1)
cache.set('2', 2)
cache.set('1', 1)
cache.set('3', 3)
print "latest:", cache.peek_latest()
print "oldest:", cache.peek_oldest()
print "keys:", cache.peek_keys()
cache.set('4', 1)
print "latest:", cache.peek_latest()
print "oldest:", cache.peek_oldest()
print "keys:", cache.peek_keys()
