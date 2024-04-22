#pragma once

void heapify(int v[], int n, int i);
void build(int v[], int n);
int left(int index);
int right(int index);
void insert(int v[], int *n, int element);
void updatePriority(int v[], int n, int index, int newValue);
void removeMax(int v[], int *n);
int parent(int index);
void printHeap(int v[], int n, int index, int level);