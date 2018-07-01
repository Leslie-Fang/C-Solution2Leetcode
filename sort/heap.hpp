#ifndef HEAP_HPP
#define HEAP_HPP
void heap_sort(int * input,int length);
void heap_build(int * input,int length);
template<typename T>
void swap(T * input,int start,int end);
void heap_part_build(int * input,int length);
#endif
