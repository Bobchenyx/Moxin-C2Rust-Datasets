//基本bfs大致思路 其余部分可自行理解 自由实现

q.enqueue(start)

while (!q.empty()) {
    node = q.dequeue();
    
    for each n in nodes.neighbours()
        if (visit[n] is not)
            q.enqueuue(n);

    node = q.dequeue();
}