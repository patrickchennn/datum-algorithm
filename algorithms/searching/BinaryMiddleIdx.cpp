#include <iostream>
using std::cout;
using std::endl;

int main(){
  unsigned int  low = 33,  
                high = 4294967290, 
                mid;

  cout << "The value of low is " << low << endl;
  cout << "The value of high is " << high << endl;

  // expected result: 2147483661.5
  // floor(2147483661.5) = 2147483661

  mid = (low + high) / 2; // this one overflow because of 32 bit integer cannot store more than 2^31

  cout << "The value of mid is " << mid << endl;
  
  cout << (high-low)/2 << endl;
  mid = low + (high-low)/2;
  cout << "correct middle idx: " << mid << endl;

  return 0;
}
/*
https://stackoverflow.com/questions/6735259/calculating-mid-in-binary-search
*/ 