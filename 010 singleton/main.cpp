#include <iostream>

class Singleton
{
private:
	Singleton() { };
	~Singleton() { };
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
	static Singleton* Instance() 
        {
		static Singleton instance;
		return &instance;
	}

    int value;
};

int main(int argc, char** argv) {
    Singleton* instance = Singleton::Instance();

    printf("%d\n", instance->value);

    Singleton::Instance()->value = 2;

    printf("%d\n", instance->value);

}