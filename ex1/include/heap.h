#pragma once

void heapify(int v[], int n, int i);
void build(int v[], int n);
int left(int index);
int right(int index);
void insert(int v[], int *n, int element);
int parent(int index);