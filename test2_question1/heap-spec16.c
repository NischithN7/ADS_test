#include <stdint.h>
#include <assert.h>
#include "heap16.h"

void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (data[idx] >= data[idx+1]);		
	}
}

void test_heap()
{
	int32_t data[] = { 1730, 1445, 1330, 1950, 1445, 1956, 1930, 1615, 1745, 1723, 234};
	Heap heap = heap_new(data, 10);	
	heap_insert(&heap, 2047);
	heap_test(&heap);
	//assert(heap_get_min(&heap) == 1045);
	//assert(heap_extract_min(&heap) == 1045);
	heap_get_min(&heap);
	heap_extract_min(&heap);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);

	heap_sort(&heap);
	test_sort(heap.data, 10);

}

int main()
{
	test_heap();
	return 0;
}