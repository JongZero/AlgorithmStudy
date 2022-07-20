#include <vector>
#include <string>
#include <iostream>
#include <chrono>

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> startTime = clock_t::now();

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> endTime = clock_t::now();
		std::cout << std::chrono::duration_cast<second_t>( endTime - startTime ).count() << '\n';
	}
};

class Item
{
public:
	Item( const std::string& name, const int ID, const int value )
	{
		_name = name;
		_ID = ID;
		_value = value;
		//std::cout << "Item " << _name << " : 생성자 호출\n";
	}
	Item( const Item& item )
	{
		_name = item._name;
		_ID = item._ID;
		_value = item._value;
		//std::cout << "Item " << _name << " : 복사 생성자 호출\n";
	}
	Item( const Item&& item )
	{
		_name = item._name;
		_ID = item._ID;
		_value = item._value;
		//std::cout << "Item " << _name << " : 이동 생성자 호출\n";
	}

	~Item() 
	{ 
		//std::cout << "Item " << _name << " : 소멸자 호출\n"; 
	}

private:
	std::string _name;
	int _ID;
	int _value;
};

int main()
{
	const int Count = 10000000;
	std::vector<Item> itemVec;
	
	itemVec.reserve( Count );
	
	Item item( "sword", 666, 50 );

	std::cout << "emplace_back\n";
	Timer emplaceTimer;
	for ( int i = 0; i < Count; i++ )
	{
		itemVec.emplace_back( item );
	}
	emplaceTimer.elapsed();
	itemVec.clear();

	std::cout << "push_back\n";
	Timer pushBackTimer;
	for ( int i = 0; i < Count; i++ )
	{
		itemVec.push_back( item );
	}
	pushBackTimer.elapsed();
	

	return 0;
}