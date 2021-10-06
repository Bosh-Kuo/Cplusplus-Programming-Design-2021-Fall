// ============================================
// Functions (p. 20)

#include <iostream>
using namespace std;

void a();
void b();
int main ()
{
  a();
  b();
  return 0;
}

void a()
{
  // fine!
  b();
}
void b()
{
  a();
}

