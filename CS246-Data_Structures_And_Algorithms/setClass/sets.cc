#include "sets.h"

Set::Set() {
  size = 5;
  dataSet = new int[5];
  dataSet[0] = 0;
}

Set::Set(int newSize) {
  if (newSize < 0) {
    newSize *= -1;
  }
  size = newSize;
  dataSet = new int[size];
  dataSet[0] = 0;
}

bool Set::isDataASet() const {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++)
    if (dataSet[i] == dataSet[j]) {
      return false;
    }
  }
  return true;
}

int Set::getSize() const {
  return size;
}

void Set::insertRandomData() {
  srand(time(0));
  int x;
  while (!(isDataASet())) {
    for (int i = 0; i < size; i++) {
      x = rand() % 25 + 1;
      dataSet[i] = x;
    }
  }
}

bool Set::insertData(int numArray[]) {
  for (int i = 0; i < size; i++) {
    dataSet[i] = numArray[i];
  }
  if (isDataASet()) {
    return true;
  } else {
    insertRandomData();
    return false;
  }
}

int Set::getDataByIndex(int index) const {
  return dataSet[index];
}

string Set::getData() const {
  stringstream result;
  result << "{ ";
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      result << dataSet[i] << " }\n";
    } else {
      result << dataSet[i] << ", ";
    }
  }
  return result.str();
}

bool Set::isInSet(int num) const {
  for (int i = 0; i < size; i++) {
    if (num == dataSet[i]) {
      return true;
    }
  }
  return false;
}

string Set::dataUnion(Set otherSet) const {
  stringstream unionSet;
  unionSet << "{ ";
  for (int i = 0; i < size; i++) {
    unionSet << dataSet[i] << ", ";
  }
  for (int i = 0; i < otherSet.getSize(); i++) {
    if (!isInSet(otherSet.getDataByIndex(i))) {
      unionSet << otherSet.getDataByIndex(i) << ", ";
    }
  }
  unionSet << "}\n";
  return unionSet.str();
}

string Set::dataIntersection(Set otherSet) const {
  stringstream intersectedSet;
  intersectedSet << "{ ";
  if (size < otherSet.getSize()) {
    for (int i = 0; i < size; i++) {
      if (otherSet.isInSet(dataSet[i])) {
        intersectedSet << dataSet[i] << ", ";
      }
    }
  } else {
    for (int i = 0; i < otherSet.getSize(); i++) {
      if (isInSet(otherSet.getDataByIndex(i))) {
        intersectedSet << otherSet.getDataByIndex(i) << ", ";
      }
    }
  }
  intersectedSet << "}\n";
  return intersectedSet.str();
}

string Set::dataDifference(Set otherSet) const {
  stringstream differenceSet;
  differenceSet << "{ ";
  for (int i = 0; i < size; i++) {
    if (!otherSet.isInSet(dataSet[i])) {
      differenceSet << dataSet[i] << ", ";
    }
  }
  differenceSet << "}\n";
  return differenceSet.str();
}

string Set::dataCartesianProduct(Set otherSet) const {
  stringstream cProductSet;
  cProductSet << "{ ";
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cProductSet << "(" << dataSet[i] << ",";
      cProductSet << otherSet.getDataByIndex(j) << "), ";
    }
  }
  cProductSet << "}\n";
  return cProductSet.str();
}

void Set::garbageCollection() {
  delete[] dataSet;
}
