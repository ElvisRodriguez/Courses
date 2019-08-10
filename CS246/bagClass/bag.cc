#include "bag.h"

Bag::Bag() {
  count = 0;
  data = new int[20];
}

Bag::Bag(int size) {
  count = 0;
  data = new int[size];
}

void Bag::shift(size_t index) {
  for (size_t i = index; i < count; i++) {
    data[i] == data[i + 1];
  }
}

size_t Bag::size() const {
  return count;
}

void Bag::insert(int newItem) {
  data[count++] = newItem;
}

void Bag::removeAtEnd() {
  data[count--] = 0;
}

void Bag:: removeItem(int item) {
  for (size_t i = count; i >= 0; i--) {
    if (data[i] == item) {
      data[i] = 0;
      shift(i);
      return;
    }
  }
}

int Bag::occurences(int item) const {
  int result = 0;
  for (int i = 0; i <= count; i++) {
    if (data[i] == item) {
      result++;
    }
  }
  return result;
}

void Bag::destroy() {
  delete[] data;
}
