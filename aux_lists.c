#include "hell.h"

/**
 *  * add_sep_node_end - Adds the separator found at the end 
 *   * of a sep_list.
 *    * @head: the head of the linked list.
 *     * @sep: the separator to be added (; | &).
 *      * Return: an address of the updated head.
 *       */
sep_list *add_sep_node_end(sep_list **head, char sep) {
    sep_list *new, *temp;

    new = malloc(sizeof(sep_list));
    if (new == NULL)
        return (NULL);

    new->separator = sep;
    new->next = NULL;
    temp = *head;

    if (temp == NULL) {
        *head = new;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 *  * free_sep_list - Frees of the separator list.
 *   * @head: an head of a linked list.
 *    * Return: No rtrn value.
 *     */
void free_sep_list(sep_list **head) {
    sep_list *temp;
    sep_list *curr;

    if (head != NULL) {
        curr = *head;
        while ((temp = curr) != NULL) {
            curr = curr->next;
            free(temp);
        }
        *head = NULL;
    }
}

/**
 *  * add_line_node_end - Adds a cmd line at the end 
 *   * of a line_list.
 *    * @head: the head of a linked list.
 *     * @line: cmd line to be added.
 *      * Return: an address of the updated head.
 *       */
line_list *add_line_node_end(line_list **head, char *line) {
    line_list *new, *temp;

    new = malloc(sizeof(line_list));
    if (new == NULL)
        return (NULL);

    new->line = line;
    new->next = NULL;
    temp = *head;

    if (temp == NULL) {
        *head = new;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 *  * free_line_list - Frees a line_list
 *   * @head: a head of the linked list.
 *    * Return: No retrn value.
 *     */
void free_line_list(line_list **head) {
    line_list *temp;
    line_list *curr;

    if (head != NULL) {
        curr = *head;
        while ((temp = curr) != NULL) {
            curr = curr->next;
            free(temp);
        }
        *head = NULL;
    }
}

