#include<iostream>
using namespace std;

int main() {

    /* Condition 1: Collision Resolution Techniques in Hashing

    Chaining:
    h(k) = k % m  // Hash function: Map key k to a table of size m
    Insert like a linked list
    In chaining, each bucket contains a linked list of keys that hash to the same index.

    Linear Probing:
    h'(k) = [h(k) + i] % m
    In linear probing, if a collision occurs at the hashed index, it searches linearly for the next available position.

    Quadratic Probing:
    h'(k) = [h(k) + i^2] % m
    Quadratic probing resolves collisions by incrementing the index based on the square of the attempt number (i).

    Double Hashing:
    h1(k) = k % m
    h2(k) = k % 8
    h3(k) = [h1(k) + i * h2(k)] % m
    Double hashing uses two hash functions: if a collision occurs, the second hash function is applied to find a new slot.

    */

    cout << "This is some role of hash mapping" << endl;
    return 0;
}
