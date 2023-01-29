class LFUCache {
    int capacity;
    int time = 0;
    //key, [value, freq]
    Map<Integer, int[]> map;
    //[key, freq, time]
    PriorityQueue<int[]> pq;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        pq = new PriorityQueue<>((a, b) -> {
            if(a[1] == b[1]) {
                return a[2] - b[2];
            } else {
                return a[1] - b[1];
            }
        });
    }
    
    public int get(int key) {
        if(capacity == 0 || !map.containsKey(key)) return -1;
        int[] data = map.get(key);
        int value = data[0];
        int freq = data[1] + 1;
        map.put(key, new int[]{value, freq});
        pq.offer(new int[]{key, freq, time++});
        return value;
    }
    
    public void put(int key, int value) {
        if(capacity == 0) return;
        if(map.containsKey(key)) {
            int[] data = map.get(key);
            int freq = data[1] + 1;
            map.put(key, new int[]{value, freq});
            pq.offer(new int[]{key, freq, time++});
        } else {
            if(map.size() >= capacity) {
                while(!pq.isEmpty()) {
                    int[] e = pq.poll();
                    //make sure the freq is same as the map one.
                    if(map.containsKey(e[0]) && e[1] == map.get(e[0])[1]) {
                        map.remove(e[0]);
                        break;
                    }
                }
            }
            map.put(key, new int[]{value, 1});
            pq.offer(new int[]{key, 1, time++});
        }
    }
}