#include <iostream>
#include <vector>
//#include <string>
#include <cassert>

using namespace std;

vector<string> validateUsers(vector<string> usernames,
                             vector<string> existingusers)
{
  vector<string> result;
  vector<string>::iterator it_i;
  vector<string>::iterator it_j;
  for (it_i = usernames.begin(); it_i < usernames.end(); it_i++)
  {
    for (it_j = existingusers.begin(); it_j < existingusers.end(); it_j++)
    {
      if (*it_i == *it_j) {
        result.push_back(*it_i);
      }
    }
  }
  return result;
}

int main() {
  //Testing function
  string users[5] = {"Alex", "Bob", "Jane", "Jack", "Dave"};
  cout << users[0].length() << endl;
  vector<string> usernames(users, users + 5);

  string existing[3] = {"Alex", "Bob", "Jack"};
  vector<string> existingusers(existing, existing + 3);

  vector<string> result(validateUsers(usernames,existingusers));

  vector<string>::iterator it;
  int i;
  for (it=result.begin(), i = 0; it < result.end(); it++) {
    assert(*it == existing[i]);
    i++;
  }

  return 0;
}
