// h1.h 
#include <iostream> 
using namespace std; 
namespace A { 
int func(int a) { 
cout << "using namespace A"; 
return 2*a; 
} 
}