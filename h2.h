// h2.h
 #include <iostream> 
using namespace std; 
namespace B { 
float func(float a) {
 cout << "using namespace B"; 
return 2*a; 
} 
}