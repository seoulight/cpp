
### 생성자의 초기화 리스트 (Initializier List)
- 초기화 리스트를 사용하지 않은 생성자로 객체를 생성할 경우, 실제로는 객체 생성 후 값 대입이 이루어진다
- 상수(const)와 레퍼런스(reference) 변수는 생성과 초기화가 동시에 이루어져야 한다
- 초기화 리스트를 사용하면 생성과 초기화가 동시에 이루어지므로 상수, 레퍼런스 변수가 있는 객체는 초기화 리스를 사용해야 한다

### static 변수
- static 변수는 모든 객체가 공유하는 변수이다
- static 변수는 자동으로 초기화 되지만 명시적으로 초기화를 해주는 것이 좋다
- static 변수는 프로그램이 종료되는 순간까지 존재한다

### static 함수
- 객체에 종속되지 않는 함수이다
- `Marine::show_status`와 같은 방식으로 호출할 수 있다
- static 변수와 마찬가지로 프로그램이 종료되는 순간까지 존재한다

### this
- 객체 내부에서 자기 자신을 호출할 때 사용한다


### 생각해볼 것
```c++
#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

 public:
  B(int c) : a(c) {}
  B(const B& b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main() {
  B b(10);

  std::cout << "---------" << std::endl;
  A a1 = b.get_A();
}
```
위 코드를 컴파일 했을 때 `복사 생성`이 몇 번 출력되는가?

1. `b.get_A()`를 호출했을 때 `A temp(a)`에서 a객체를 복사하여 생성하므로 `복사 생성`을 출력한다.
2. `b.get_A()`가 `temp`를 반환하면 임시 객체의 값을 복사하여 객체를 생성해 반환하므로 `복사 생성`을 출력한다.
3. `A a1 = b.get_A()`에서 `get_A()`의 반환값인 임시 객체를 `a1`에 대입하면서 복사생성자를 호출하여 `복사 생성`을 출력한다.