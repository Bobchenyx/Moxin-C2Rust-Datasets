int DistanceBFS(int** grid, int gridSize, int x, int y)
{
	Queue_t *queue = QueueInit(10240);
	if (queue == NULL) {
		return 0;
	}

	int *mark = malloc(sizeof(int) * gridSize * gridSize);
	memset(mark, 0, sizeof(int) * gridSize * gridSize);
	int distance = -1;

	QueuePush(queue, CreateNode(x, y));

	while (!IsQueueEmpty(queue)) {
		Node_t *n = QueueHead(queue);
		QueuePop(queue);
		mark[n->x * gridSize + n->y] = 1;
		if (*(*(grid + n->x) + n->y) == 1) { 
			distance = Distance(x, y, n->x, n->y);
			free(n);
			break;
		}
		if (n->y - 1 >= 0 && mark[n->x * gridSize + n->y - 1] != 1) {
			QueuePush(queue, CreateNode(n->x, n->y - 1));
		}

		if (n->y + 1 < gridSize && mark[n->x * gridSize + n->y + 1] != 1) {
			QueuePush(queue, CreateNode(n->x, n->y + 1));
		}

		if (n->x - 1 >= 0 && mark[(n->x - 1) * gridSize + n->y] != 1) {
			QueuePush(queue, CreateNode(n->x - 1, n->y));
		}

		if (n->x + 1 < gridSize && mark[(n->x + 1) * gridSize + n->y] != 1) {
			QueuePush(queue, CreateNode(n->x + 1, n->y));
		}
		free(n);
	}

	free(mark);
	QueueDestory(queue);

	return distance;
}

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
	if (CheckParam(grid, gridSize, gridColSize)) {
		return -1;
	}

	int max = -1;
	for (int i = 0; i < gridSize; ++i) {
		for (int j = 0; j < gridColSize[i]; ++j) {
			if (*(grid[i] + j) == 0) {
				int distance = DistanceBFS(grid, gridSize, i, j);
				if (distance > max) {
					max = distance;
				}
			}
		}
	}

	return max;
}