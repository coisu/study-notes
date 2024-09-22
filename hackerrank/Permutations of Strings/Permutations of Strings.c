#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    // anyway it should be printed in lexicographical order.
    // so it is gonna be searching the pivot element and rearrange from backward.
    
    // 1. Search the mostright pivot index that non-duplicated mand sorted mostright element 
    // 2. Search mostright bigger element than pivot and switch it with pivot
    // 3. Sort suffix from left side for suffix in lexicographical order.

    int pivot = n -1;
    
    // if [pivot] is smaller or same as the [pivot-1], gonna ignore it, reduce pivot index 
    // the actual pivot will be [pivot - 1]
    while (pivot > 0 && strcmp(s[pivot - 1], s[pivot]) >= 0)
    {
        pivot--;
    }
    if (pivot <= 0) // cause actual pivot is pivot -1, so it has to be bigger than 0
        return 0;
        
    // 2. find index that is least bigger(lexicographically)than pivot which is possibly switched before from frontward
    // and switch them(search from backward).
    // *result array from the function
    // a b b c d d > [pivot - 1] = c
    //*a b b d c d > [pivot - 1] = c 
    //         ^
    //*a b b d d c
    // a b b d d c > [pivot - 1] = b
    //     ^     ^ : c is the most right bigger element than b in suffix
    // a b c d d b : after pivot switching smaller
    // a b c[d d b]: and then sort the suffix in lexicographical order 
    //              [pivot - 1] = c suffix = [d d b]
    //*a b c b d d 
    //       ^
    //*a b c d b d
    //         ^
    // a b c d d b
    //     ^
    // a b d[d c b]
    //*a b d b c d
    //         ^
    //*a b d b d c
    //       ^
    // a b d c[d c]
    //*a b d c c d
    //*a b d c d c
    //*a b d d c c
    //   ^
    // a c[d d c b]   --------> ***suffix is always decrease order, 
    //*a c b c d d 
    //       ^

    int i = n - 1; // i = most_right_bigger
    while (strcmp(s[pivot - 1], s[i]) >= 0) // Searching mostrigt bigger element in suffix
        i--;
    char *tmp = s[i];
    s[i] = s[pivot - 1];
    s[pivot - 1] = tmp;
    
    // 3. Suffix sorting (***Reversing)
    i = n - 1;
    while (pivot < i)
    {
        tmp = s[pivot];
        s[pivot++] = s[i];
        s[i--] = tmp;
    }
    
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
