#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double get_area(triangle tr)
{
    double s = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c));
}

int compare(const void *a, const void *b)
{
    triangle* tr1 = (triangle*)a;
    triangle* tr2 = (triangle*)b;
    
    double area1 = get_area(*tr1);
    double area2 = get_area(*tr2);
    
    if (area1 < area2) return -1;
    else if (area1 > area2) return 1;
    else return 0;
}

void sort_by_area(triangle* tr, int n) {
	
//   qsort(tr, n, sizeof(triangle), compare);
//  apparently with qsort function, im facing a problem
//  could because of Precision and Tolerance, or something else.
//  so im gonna try with the first approach that came in my mine.

//****Turns out it qs because 2.0 for sqrt for double!!!!
//****I was using 2 instead of 2.0 and it became a problem. 

    qsort(tr, n, sizeof(triangle), compare);

    // double area[n], s;
    
    // for (int i = 0; i < n; i++)
    // {
    //     s = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
    //     area[i] = sqrt(s * (s - tr[i].a) * (s - tr[i].b) * (s - tr[i].c));
    // }
        
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (area[i] > area[j])
    //         {
    //             double a_tmp = area[i];
    //             triangle tmp = tr[i];
    //             tr[i] = tr[j];
    //             tr[j] = tmp;
    //             area[i] = area[j];
    //             area[j] = a_tmp;
    //         }
    //     }
    // }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
