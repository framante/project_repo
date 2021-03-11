
class myclass
{
private:
  int i = 5;
  double j = 4;
public:
  myclass(int a, double b) : i(a), j(b) {};
  int get_i() {return i;}
  double get_j() {return j;}
  ~myclass()=default;
}
  
