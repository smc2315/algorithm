#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct heap {
	int arr[100000];
	int size;
}heap;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void initHeap(heap *hp) {
	hp->size = 0;
}
void insert(heap* hp, int data)
{
	int here = ++hp->size;

	while ((here != 1) && (data < hp->arr[here / 2]))
	{
		hp->arr[here] = hp->arr[here / 2];
		here /= 2;
	}
	hp->arr[here] = data;
}

int deleteData(heap *hp) {
	if (hp->size == 0) return 0;
	int ret = hp->arr[1];
	hp->arr[1] = hp->arr[hp->size--];
	int parent = 1;
	int child;

	while (1) {
		child = parent * 2;
		if (child + 1 <= hp->size && hp->arr[child] > hp->arr[child + 1])
			child++;

		if (child > hp->size || hp->arr[child] > hp->arr[parent]) break;

		swap(&hp->arr[parent], &hp->arr[child]);
		parent = child;
	}

	return ret;

}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	heap hp;
	initHeap(&hp);
	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
			cout << deleteData(&hp) <<"\n";
		else
			insert(&hp,x);
	}
	
	
	
	return 0;
}