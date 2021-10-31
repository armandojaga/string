#pragma once
#include <ostream>

class String
{
private:
	char* data;
	size_t size;
public:
	String() = default;
	String(const char* value);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	size_t length() const;
	void clear();

	String operator+(const String& other) const;
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	bool operator==(String&& other) const;

	friend std::ostream& operator<<(std::ostream& _stream, String const& str)
	{
		if(str.data == nullptr)
		{
			return _stream;
		}
		return _stream << str.data;
	}
};
