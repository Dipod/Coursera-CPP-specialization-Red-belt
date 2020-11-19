#include <string>
#include <vector>
using namespace std;

#define CONCAT_2(x, y) x##y
#define CONCAT_1(x, y) CONCAT_2(x, y)
#define UNIQ_ID CONCAT_1(id_, __LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
