// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
   private: 
    T arr[100];
    int first, last;
 public:
    TPQueue() : first(0), last(0) { }
    void push(T x) {
        if (last - first >= size) {
            throw std::string("Full!");
        } else {
            int y = last;
            while ((--y >= first) && (arr[y % size].prior < x.prior)) {
                arr[(y + 1) % size] = arr[y % size];
            }
            arr[(y + 1) % size] = x;
            last++;
            }
            T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        if (first < last) {
            return arr[first];
        } else {
            throw std::string("Empty!");
        }
    }
    T back() {
        if (first < last) {
            return arr[last - 1];
        } else {
            throw std::string("Empty!");
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
