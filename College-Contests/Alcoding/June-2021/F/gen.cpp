// Todo: make a better generator, eventually
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

vector <int> generate_vector (int start, int end, int size) {
    vector <int> temp(size);
    for (int i = 0; i < size; i++) {
        int x = rand (start, end);
        temp[i] = x;
    }
    return temp;
}

vector <int> generate_permutation (int size) {
    vector <int> temp(size);
    for (int i = 0; i < size; i++) {
        temp[i] = i + 1;
    }
    random_shuffle (temp.begin(), temp.end());
    return temp;
}

void print_vector (vector <int>& v) {
    for (auto x: v) {
        printf("%d ", x);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
	srand (atoi (argv[1]));
    // test cases
    // printf("1\n");
	int n = rand (2, 5);
	printf ("%d", n);
    int m = rand (1, 3);
    printf(" %d", m);
    printf("\n");
	set <int> used;
	for (int i = 0; i < n; i++) {
		int x;
        x = rand (1, 10);
        // to make x unique, uncomment the following
		// do {
			// x = rand (1, 100);
		// } while (used.count (x));
		// used.insert (x);
		printf("%d ", x);
	}
    puts("");
    vector <int> s = generate_permutation (m);
    print_vector (s);
}
