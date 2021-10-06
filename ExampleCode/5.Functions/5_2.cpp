// ============================================
// Functions (p. 20)

#include <iostream>
using namespace std;

void a()
{
  // error!
  b();
}
void b()
{
  a();
}
int main ()
{
  a();
  b();
  return 0;
}
