#include <iostream>
#include <thread>
int main()
{
  // For literals indicating time
  using namespace std::chrono_literals;
  std::cout<<"Hello\r";
  std::cout.flush(); // flush the buffer!
  std::this_thread::sleep_for(1000ms);
  std::cout<<"Wo";
  std::cout.flush(); // flush the buffer!
  std::this_thread::sleep_for(500ms);
  std::cout<<"rld\n";
  return 0;
}
