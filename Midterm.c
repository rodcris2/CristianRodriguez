#include <stdlib.h>
#include <stdio.h>

void count() {
	printf("Enter lines of text here: .../n");
	int c, nc = 0, nl = 0, nt = 0, nbackslash = 0, nbackspace = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') { ++nl; }
		else if (c == '\t') { ++nt; }
		else if (c == '\b') { nbackspace++; }
		else if (c == '\\') { nbackslash++; }
		else if (isspace(c)) { ++nc; }
		printf("lines: %d\n", nl);
		printf("tabs: %d\n", nt);
		printf("backspaces: %d\n", nbackspace);
		printf("backslashes: %d\n", nbackslash);
		printf("alphanumeric: %d\n", nc);
	}
}

int main(int argc, const char* argv[]) {
	count();
	return 0;
}

//----------------------------------------------------------------------------------------------------

//2
#include <string.h>

//3
#include <string.h>

//4
#include <stdlib.h>

//5
#include <stdio.h>

//6
size_t strcpy_(char* s, const char* t) {
	size_t p = s;
	while ((*s++ = *t++) != '\0') {}

	return p;
}

//7
char* strncat(char* s, const char* t, size_t n) {
	char* p = s;

	while (*s != '\0') { ++s; }
	while (n-- > 0 && *t != '\0') {	*s++ = *t++; }

	*s = '\0';
	return p;
}

//8
int strcmp(const char* s, const char* t) {
	while (*s != '\0' && *t != '\0' && *s == *t) {
		++s;
		++t;
	}
	return *s - *t;
}

//9
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side); // TODO

void square_delete(square* sq); // TODO

void square_move(square* sq, double x, double y); // TODO

void square_expandby(square* sq, double expandby); // TODO

double square_area(square* sq); // TODO

double square_perimeter(square* r); // TODO
// print location, side, area and perimeter
void square_print(const char* msg, square* sq); // TODO

void test_square(double ulx, double uly, double side) {
	square* sq = square_init(ulx, uly, side);
	square_print(“sq is : “, sq);
	square_move(2, 2);
	square_print(“sq is now : “, sq);
	square_expandby(sq, 10);
	square_print(“sq has expanded to : “, sq);
	square_delete(sq);
	printf(“\n\n”);
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