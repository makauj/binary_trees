#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int reached_null = 0;

	if (!tree)
		return (0);

	queue_t *queue = create_queue();
	if (!queue)
		return (0);

	enqueue(queue, tree);

	while (!queue_is_empty(queue))
	{
		binary_tree_t *current = dequeue(queue);
		
		if (!current)
		{
			reached_null = 1;
		}
		else
		{
			if (reached_null)
			{
				free_queue(queue);
				return (0);
			}
			enqueue(queue, current->left);
			enqueue(queue, current->right);
		}
	}

	free_queue(queue);
	return (1);
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

