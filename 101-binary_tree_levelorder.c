#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value in the node
 * 	must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current;
	queue_t *queue;

	if (!tree || !func)
		return;

	queue = create_queue();
	if (!queue)
		return;

	enqueue(queue, tree);

	while (queue_is_empty(queue) == 0)
	{
		current = dequeue(queue);

		func(current->n);

		if (current->left)
			enqueue(queue, current->left);

		if (current->right)
			enqueue(queue, current->right);
	}

	free_queue(queue);
}

/**
 * create_queue - Creates a new empty queue
 * Return: queue
 */
queue_t *create_queue(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (!queue)
		return (NULL);

	queue->front = NULL;
	queue->rear = NULL;

	return (queue);
}

/**
 * enqueue - Enqueues a node onto the queue
 * @queue: pointer to queue node
 * @node: pointer to node
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node;

	if (!queue || !node)
		return;

	new_node = malloc(sizeof(queue_node_t));
	if (!new_node)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (queue->rear)
		queue->rear->next = new_node;
	else
		queue->front = new_node;

	queue->rear = new_node;
}

/**
 * dequeue - Dequeues a node from the queue
 * @queue: pointer
 *
 * Return: node
 */
binary_tree_t *dequeue(queue_t *queue)
{
	if (!queue || !queue->front)
		return (NULL);

	queue_node_t *temp = queue->front;
	binary_tree_t *node = temp->node;
	queue->front = queue->front->next;

	if (!queue->front)
		queue->rear = NULL;

	free(temp);

	return (node);
}

/**
 * queue_is_empty - Checks if the queue is empty
 * @queue: pointer
 *
 * Return: queue && queue->front == NULL
 */
int queue_is_empty(queue_t *queue)
{
	return (queue && queue->front == NULL);
}

/**
 * free_queue - Frees the queue
 * @queue: pointer
 */
void free_queue(queue_t *queue)
{
	if (!queue)
		return;

	queue_node_t *temp;
	while (queue->front)
	{
		temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}

	free(queue);
}
