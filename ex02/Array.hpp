#pragma once

template< typename T >
class	Array
{
private:
	T				*_array;
	unsigned int	_size;

public:
	Array( void ) : _size( 0 )
	{
		_array = _size ? new T[_size] : nullptr;
	}
	
	Array( unsigned int n ) : _size( n )
	{
		_array = _size ? new T[_size] : nullptr;
	}
	
	Array( const Array &other ) : _size( 0 )
	{
		this->_array = nullptr;
		*this = other;
	}

	~Array( void )
	{
		if (this->_array != nullptr)
			delete [] _array;
	}

	Array	&operator=( const Array &src )
	{
		if (this->_array != nullptr)
			delete [] this->_array;

		if (src.size() != 0)
		{
			this->_size = src.size();
			this->_array = new T[src.size()];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}

		return (*this);
	}

	T	&operator[]( unsigned int index )
	{
		if (index >= this->_size || this->_array == nullptr)
			throw Array<T>::InvalidIndexException();
		
		return (this->_array[index]);
	}

	unsigned int	size( void ) const
	{
		return (this->_size);
	}

	class	InvalidIndexException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}
