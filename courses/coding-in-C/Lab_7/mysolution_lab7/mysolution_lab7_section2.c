#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    double value;          // gespeicherter Wert
    struct Node *next;     // Zeiger auf den nächsten Node
} Node;

// erstellt einen neuen Node (malloc), setzt value, next = NULL
Node* create_node(double v) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL; // Speicherreservierung fehlgeschlagen
    }
    n->value = v;
    n->next = NULL;
    return n;
}

// hängt einen Node ans Ende der Liste an (über tail pointer)
void append_node(Node **head, Node **tail, Node *n) {
    if (*head == NULL) {
        // Liste ist leer: head und tail zeigen auf den ersten Node
        *head = n;
        *tail = n;
    } else {
        // Liste hat schon Elemente: tail->next zeigt auf neuen Node
        (*tail)->next = n;
        *tail = n; // tail wird auf das neue Ende gesetzt
    }
}

// fügt einen Node als 3. Node ein (nach dem 2. Node)
// Annahme: Liste hat mindestens 2 Nodes (bei 50 stimmt das)
void insert_as_third(Node **head, Node *newNode) {
    // head = 1. Node
    // head->next = 2. Node
    Node *second = (*head)->next;

    // newNode soll zwischen 2. und 3. hängen:
    // newNode->next zeigt auf den bisherigen 3.
    newNode->next = second->next;

    // 2. Node zeigt jetzt auf newNode
    second->next = newNode;
}

// gibt Liste aus
void print_list(Node *head) {
    int idx = 0;
    while (head != NULL) {
        printf("List[%d] = %.2f\n", idx, head->value);
        head = head->next;
        idx++;
    }
}

// gibt Array aus
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Array[%d] = %d\n", i, a[i]);
    }
}

// gibt alle Nodes frei
void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next; // nächsten merken, sonst verlieren wir den Rest
        free(head);
        head = next;
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    // 1) head ist Startpointer (leer -> NULL)
    Node *head = NULL;
    Node *tail = NULL; // hilft beim schnellen Anhängen

    // 2) 50 Nodes erstellen und an Liste anhängen
    for (int c = 0; c < 50; c++) {
        Node *n = create_node((double)c); // oder random double, wenn du willst
        if (n == NULL) {
            printf("malloc failed\n");
            free_list(head);
            return 1;
        }
        append_node(&head, &tail, n);
    }

    // 3) Array mit 51 Elementen
    int array_51[51];

    // 4) Index 0..49 mit 50 random ints füllen
    for (int i = 0; i < 50; i++) {
        array_51[i] = rand() % 50;
    }

    // 5) zusätzlichen random Wert erzeugen
    int extra = rand() % 50;

    // 6) extra bei Index 3 ins Array einfügen => Shift nach rechts
    // Wichtig: rückwärts laufen, sonst überschreibst du Werte
    for (int i = 49; i >= 3; i--) {
        array_51[i + 1] = array_51[i];
    }
    array_51[3] = extra;

    // 7) gleichen extra Wert als neuen Node einfügen: als 3. Node
    Node *extraNode = create_node((double)extra);
    if (extraNode == NULL) {
        printf("malloc failed\n");
        free_list(head);
        return 1;
    }
    insert_as_third(&head, extraNode);

    // 8) Array und Liste ausgeben
    printf("----- ARRAY -----\n");
    print_array(array_51, 51);

    printf("----- LIST -----\n");
    print_list(head);

    // 9) Was ist zeitaufwändiger?
    // Array: Einfügen bei Index 3 braucht Shift vieler Elemente -> O(n)
    // Linked List: Einfügen an bekannter Stelle (hier 3.) braucht nur wenige Pointer-Änderungen -> O(1)
    // (ABER: Wenn du erst suchen musst, kostet das Durchlaufen -> O(n).)

    // 10) Speicher freigeben
    free_list(head);

    return 0;
}