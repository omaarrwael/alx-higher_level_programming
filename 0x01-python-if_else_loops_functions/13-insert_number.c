#!/bin/bash
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to the head of the linked list.
 * @number: Value to insert into the list.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number) {
listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
if (new_node == NULL) 
{
return NULL;
}
new_node->n = number;
new_node->next = NULL;
if (*head == NULL || number < (*head)->n)
{
new_node->next = *head;
*head = new_node;
return new_node;
}
listint_t *current = *head;
while (current->next != NULL && current->next->n < number)
{
current = current->next;
}
new_node->next = current->next;
current->next = new_node;
return new_node;
}