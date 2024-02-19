#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a polynomial term
struct poly {
    int cf, px, py, pz;
    int flag;
    struct poly *link;
};

// Define a pointer to the polynomial structure
typedef struct poly *NODE;

// Function to insert a term at the rear of the polynomial
NODE insertrear(NODE h, int cf, int px, int py, int pz) {
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct poly));
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    temp->flag = 0; // Initialize the flag to 0
    temp->link = h; // Set the link to the head of the polynomial
    if (h->link == h) {
        h->link = temp;
        return h;
    }
    cur = h->link;
    while (cur->link != h)
        cur = cur->link;
    cur->link = temp;
    return h;
}

// Function to read a polynomial from the user
void readpoly(NODE h) {
    int cf, px, py, pz, ch;
    do {
        printf("Enter co-eff, px, py, pz:");
        scanf("%d%d%d%d", &cf, &px, &py, &pz);
        h = insertrear(h, cf, px, py, pz);
        printf("\n1 to continue, 0 to exit:");
        scanf("%d", &ch);
    } while (ch != 0);
}

// Function to evaluate a polynomial for given values of x, y, and z
void evalpoly(NODE h1) {
    int x, y, z;
    float result = 0.0;
    NODE temp = h1->link;
    printf("\nEnter the value of x, y, z:");
    scanf("%d%d%d", &x, &y, &z);
    while (temp != h1) {
        result += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
        temp = temp->link;
    }
    printf("\nThe result = %f\n", result);
}

// Function to display a polynomial
void display(NODE h1) {
    NODE temp;
    if (h1->link == h1) {
        printf("\nPolynomial is empty");
        return;
    }
    temp = h1->link;
    while (temp != h1) {
        if (temp->cf > 0)
            printf(" +%dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
        else
            printf(" %dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);
        temp = temp->link;
    }
}

// Function to add two polynomials and store the result in another polynomial
void addpoly(NODE h1, NODE h2, NODE h3) {
    NODE p1, p2;
    int cf1, px1, py1, pz1, cf2, px2, py2, pz2, cf;
    p1 = h1->link;
    while (p1 != h1) {
        cf1 = p1->cf;
        px1 = p1->px;
        py1 = p1->py;
        pz1 = p1->pz;
        p2 = h2->link;
        while (p2 != h2) {
            cf2 = p2->cf;
            px2 = p2->px;
            py2 = p2->py;
            pz2 = p2->pz;
            if (px1 == px2 && py1 == py2 && pz1 == pz2)
                break;
            p2 = p2->link;
        }
        if (p2 != h2) {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0)
                h3 = insertrear(h3, cf, px1, py1, pz1);
            p1 = p1->link;
            p2 = p2->link;
        } else {
            h3 = insertrear(h3, cf1, px1, py1, pz1);
            p1 = p1->link;
        }
    }
    p2 = h2->link;
    while (p2 != h2) {
        if (p2->flag == 0)
            h3 = insertrear(h3, p2->cf, p2->px, p2->py, p2->pz);
        p2 = p2->link;
    }
}

// Main function
void main() {
    int ch;
    NODE h1, h2, h3;
    // Allocate memory for polynomial structures
    h1 = (NODE)malloc(sizeof(struct poly));
    h2 = (NODE)malloc(sizeof(struct poly));
    h3 = (NODE)malloc(sizeof(struct poly));
    // Initialize the links to themselves
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    while (1) {
        printf("\n1. Evaluate a polynomial\n2. Add polynomials\n3. Exit\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter polynomial:");
                readpoly(h1);
                evalpoly(h1);
                display(h1);
                h1->link = h1;
                break;
            case 2:
                printf("Enter 1st polynomial:");
                readpoly(h1);
                printf("Enter 2nd polynomial:");
                readpoly(h2);
                addpoly(h1, h2, h3);
                printf("\n1st polynomial is\n");
                display(h1);
                printf("\n");
                printf("\n2nd polynomial is\n");
                display(h2);
                printf("\n");
                printf("\nResultant polynomial is\n");
                display(h3);
                printf("\n");
                break;
            case 3:
                exit(0);
        }
    }
}
