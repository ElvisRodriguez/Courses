#include "windows.h"

string Windows::drawHorizontal(int size, int position = 0) {
  stringstream result;
  for (int i = 0; i < position; i++) {
    result << "  ";
  }
  for (int i = 0; i < size; i++) {
    result << "**";
  }
  result << endl;
  return result.str();
}

string Windows::drawVertical(int size, int position = 0) {
  stringstream result;
  string indentation = "";
  for (int i = 0; i < position; i++) {
    indentation += "  ";
  }
  for (int i = 0; i < size; i++) {
    result << indentation;
    result << "*";
    for (int j = 0; j < size; j++) {
      if (j == size - 1) {
        result << "*\n";
      } else {
        result << "  ";
      }
    }
  }
  return result.str();
}

Windows::Windows() {
  currentSize = DEFAULT;
  cout << drawHorizontal(DEFAULT);
  cout << drawVertical(DEFAULT);
  cout << drawHorizontal(DEFAULT);
}


void Windows::open(int size) {
  currentSize = size;
  cout << drawHorizontal(size);
  cout << drawVertical(size);
  cout << drawHorizontal(size);
}

void Windows::minimize() {
  currentSize = 0;
  cout << drawHorizontal(5) << drawHorizontal(5);
}

void Windows::maximize() {
  currentSize = 30;
  cout << drawHorizontal(currentSize);
  cout << drawVertical(currentSize);
  cout << drawHorizontal(currentSize);
}

void Windows::restore() {
  currentSize = DEFAULT;
  cout << drawHorizontal(DEFAULT);
  cout << drawVertical(DEFAULT);
  cout << drawHorizontal(DEFAULT);
}

void Windows::move(unsigned int position = 0) {
  if (currentSize != 0) {
    cout << drawHorizontal(currentSize, position);
    cout << drawVertical(currentSize, position);
    cout << drawHorizontal(currentSize, position);
  }
}
