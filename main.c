
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//QUESTION 1
void count() {
 printf("Enter lines of text here: .../n");
 int c, nc = 0, nl = 0, nt = 0, nbackslash = 0;
 while ((c = getc(stderr)) != EOF) {
 if (c == '\n') {
     ++nl;
 }
 else if (c == '\t') {
     ++nt;
 }
 else if (c == '\\') {
     ++nbackslash;
 }
 else if (isspace(c)) {
     ++nc;
 }
 }
     printf("lines: %d\n",nl);
     printf("tabs: %d\n", nt);
     printf("backslashes: %d\n", nbackslash);
     printf("alphanumeric: %d\n", nc);
}

int main(int argc, const char* argv[]) {
 count();
 return 0;
}

//QUESTION 2
//char *strchr(const char* s, char c);

//QUESTION 3
 //size_t strspn(const char* s, const char* t);

//QUESTION 4
//void abort(void);

//QUESTION 5
//FILE *fopen("midterm.txt","r");

//QUESTION 6
char* strcpy(char *s, const char* t){
    char* p = s;
    while((*s++ = *t++) != '\0'){
    }
    return p;
}

//QUESTION 7

char* strncat(char* s, const char* t, size_t n){
    char* p = s;
    while(*s != '\0'){++s;} // iterate to the end of the string
    while(n-- > 0 && *t != '\0'){
        *s++ = *t++;
    }
    *s = '\0'; // add the termating of the string
    return p;
}

//QUESTION 8
int strcmp(const char* s, const char* t){
    while(*s != '\0' && *t != '\0' && *s == *t){
        s++;
        t++;
    }
    return *s - *t;
}

//QUESTION 9
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };

//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side){ // TODO
    square* first = (square*)malloc(sizeof(square));
    
    first->ul.x = ulx;
    first->ul.y = uly;
    first->side = side;
    
    return first;
}

void square_delete(square* sq){ // TODO
    free(sq);
}

void square_move(square* sq, double x, double y){ // TODO
    sq->ul.x = x;
    sq->ul.y = y;
}

void square_expandby(square* sq, double expandby){// TODO
    sq->ul.x += expandby;
    sq->ul.y += expandby;
}

double square_area(square* sq){ // TODO
    double area = sq->side * sq->side;
    return area;
}

double square_perimeter(square* r){ // TODO
    double perimeter = r->side + r->side + r->side + r->side;
    return perimeter;
}

// print location, side, area and perimeter
void square_print(const char* msg, square* sq){ // TODO
    printf("Location is: (%f,%f)\n", sq->ul.x, sq->ul.y);
    printf("Side Lenght is: %zu\n", sq->side);
    printf("Area is: %f\n", square_area(sq));
    printf("Perimeter is: %f\n", square_perimeter(sq));
}


void test_square(double ulx, double uly, double side) {
 square* sq = square_init(ulx, uly, side);
 square_print("sq is:", sq);
 square_move(sq,2, 2);
 square_print("sq is now: ", sq);
 square_expandby(sq, 10);
 square_print("sq has expanded to:", sq);
 square_delete(sq);
 printf("\n\n");
}
void tests_square() {
 test_square(0, 0, 10);
 test_square(1, 1, 5);
 // add other tests if you wish // TODO (optional)
}
int main(int argc, const char* argv[]) {
 tests_square();
 return 0;
}
