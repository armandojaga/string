#include "String.h"

#include "Logger.h"

String::String(const char* value)
{
	size = 0;
	LOG("Call String(const char*)");
	while (value[size] != '\0')
	{
		++size;
	}
	data = new char[size + 1];

	std::copy(value, value + size, data);
	data[size] = '\0';
}

String::String(const String& other)
{
	LOG("Call String(const String&)");
	data = new char[other.size + 1];
	size = other.size;
	std::copy(other.data, other.data + size + 1, data);
}

String::String(String&& other) noexcept
{
	LOG("Call String(String&&)");
	data = other.data;
	size = other.size;

	other.data = nullptr;
	other.size = 0;
}

String::~String()
{
	LOG("Call destroy");
	delete[] data;
	data = nullptr;
}

size_t String::length() const
{
	return size;
}

void String::clear()
{
	LOG("Call clear");
	delete[] data;
	data = nullptr;
	size = 0;
}

String String::operator+(const String& other) const
{
	LOG("Call operator+(const String&)");
	const size_t ns = size + other.size;
	char* newArr = new char[ns + 1];
	std::copy_n(data, size, newArr);
	std::copy_n(other.data, other.size + 1, newArr + size);
	return String(newArr);
}

String& String::operator=(const String& other)
{
	LOG("Call operator=(const String&)");
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		data = new char[size + 1];

		memcpy(data, other.data, size + 1);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	LOG("Call operator=(String&&)");
	if (this != &other)
	{
		delete[] data;

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;
	}

	return *this;
}

bool String::operator==(String&& other) const
{
	LOG("Call operator==(String&&)");
	if (other.size != size)
	{
		return false;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (other.data[i] != data[i])
		{
			return false;
		}
	}
	return true;
}
