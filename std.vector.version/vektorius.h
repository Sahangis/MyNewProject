#ifndef VEKTORIUS_H
#define VEKTORIUS_H

#include <initializer_list>

template<typename ValueT>
class Vector
{
private:
	ValueT* mData;
	std::size_t mSize;
	std::size_t mCapacity;

public:
	Vector(std::size_t pCapacity=4)
		: mData(nullptr), mSize(0), mCapacity(pCapacity)
	{ allocate(pCapacity); }

	Vector(const ValueT* const pData, std::size_t pSize)
		: mData(nullptr), mSize(0), mCapacity(0)
	{ 
		allocate(pSize); 
		copy(pData, pSize);
	}

	Vector(const std::initializer_list<ValueT>& pList)
			: mData(nullptr), mSize(0), mCapacity(0)
		{
			allocate(pList.size());
			copy(pList.begin(), pList.size());
		}

	Vector(const Vector& pOther)
		: mData(nullptr), mSize(0), mCapacity(pCapacity)
	{
		allocate(pOther.mCapacity);
		copy(pOther.mData, pOther.mSize);
	}

	~Vector()
	{
		deallocate();
	}
private:
	void allocate(std::size_t newCapacity)
	{
		this->mData = new ValueT[newCapacity];
		this->mSize = 0;
		this->mCapacity = newCapacity;
	}

	void deallocate()
	{
		if (this->mData != nullptr)
		{
			delete[] this->mData;
			this->mSize = 0;
			this->mCapacity = 0;
		}
	}

	void reallocate(std::size_t pNewCapacity)
	{
		ValueT* temp = new ValueT[pNewCapacity];

		if(this->mSize > pNewCapacity)
			this->mSize = pNewCapacity;

		for(unsigned int index = 0; index < this->mSize; ++index)
			temp[index]=this->mData[index];

		delete[] this->mData;
		this->mData = temp;
		this->mCapacity = pNewCapacity;
	}


public:
	void copy(const ValueT* pData, std::size_t pSize)
	{
		for(unsigned int index = 0; index < (this->mSize = pSize); ++index)
			this->mData[index] = pData[index];
	}

	const ValueT* getData() const
	{
		return this->mData;
	}

	std::size_t getSize() const
	{
		return this->mSize;
	}

	std::size_t getCapacity() const
	{
		return this->mCapacity;
	}

	void add(const ValueT& pValue)
	{
		if(this->mSize + 1 > this->mCapacity)
			reallocate(this->mCapacity + this->mCapacity / 2 + 1);

		this->mData[this->mSize++] = pValue;
	}

	void clear()
	{
		deallocate();
	}

	void eraseRangeTo(std::size_t pBegin, Vector<ValueT>& pOther)
	{
		std::size_t length = this->mSize - pBegin;
		pOther = Vector<ValueT>(this->mData+pBegin, length);

		ValueT* temp = new ValueT[pBegin];
		for (std::size_t index = 0; index < pBegin; ++index)
			temp[index] = this->mData[index];

		delete[] this->mData;
		this->mData = temp;
		this->mSize = pBegin;
		this->mCapacity = pBegin;
	}

	void erase(ValueT *begin, ValueT *end)
	{
		int range_length=static_cast<int>(end-begin);
		size_t newCapacity=this->mSize-range_length;
		ValueT* temp = new ValueT[newCapacity];
		size_t index=0;
		for(ValueT* it=this->mData; it!=begin; it++)
		{
			temp[index++]=*it;
		}
		for(ValueT* it=end; it!=this->mData+mSize; it++)
		{
			temp[index++]=*it;
		}

		deallocate();
		this->mData = temp;
		this->mSize = newCapacity;
		this->mCapacity = newCapacity;
	}
	// Iterators
	ValueT* begin()
	{
		return this->mData;
	}

	const ValueT* cbegin() const
	{
		return this->mData;
	}

	ValueT* end()
	{
		return this->mData + this->mSize;
	}

	const ValueT* cend() const
	{
		return this->mData + this->mSize;
	}

	//operatoriai
	Vector& operator =(const Vector& pOther)
	{
		if (this == &pOther)
			return *this;

		deallocate();
		allocate(pOther.mCapacity);
		copy(pOther.mData, pOther.mSize);
		return *this;
	}

	Vector& operator [](std::size_t pIndex)
	{
		if(pIndex < 0 || pIndex>= this->mSize)
			throw;
		return this->mData[pIndex];
	}

	const ValueT& operator [](std::size_t pIndex) const
	{
		if(pIndex < 0 || pIndex>= this->mSize)
			throw;
		return this->mData[pIndex];
	}

	bool operator ==(const Vector& pOther) const
	{
		if (this->mData == nullptr || pOther.mData == nullptr)
			return false;
		
		if(this->mSize <= 0 || pOther.mSize <= 0)
			return false;

		if(this->mSize != pOther.mSize)
			return false;
		
		for(std::size_t index = 0; index < this->mSize ++index)
			if(this->mData[index] != pOther.mData[index])
				return false;

		return true;
	}

	bool operator !=(const Vector& pOther) const
	{
		return !(*this == pOther);
	}

	/**
	 * Standart notations:
	 */
	void push_back(const ValueT& pValue)
	{
		add(pValue);
	}

	void insert(ValueT* insertp, ValueT* range_begin, ValueT* range_end)
	{
		int range_length=static_cast<int>(range_end-range_begin);
		size_t newCapacity=this->mSize+range_length;
		ValueT* temp = new ValueT[newCapacity];
		int fstop=static_cast<int>(insertp-this->mData);
		for(int index=0; index<fstop; index++)
		{
			temp[index]=this->mData[index];
		}
		for(int index=fstop; index<fstop+range_length; index++)
		{
			temp[index]=*(range_begin+index);
		}
		for(int index=fstop+range_length; index<fstop+range_length+(this->mSize-fstop); index++)
		{
			temp[index]=this->mData[index-range_length];
		}
		deallocate();
		this->mData=temp;
		this->mSize=newCapacity;
		this->mCapacity=newCapacity;
	}



	void pop_back()
	{
		size_t newCapacity=this->mSize-1;
		ValueT* temp=new ValueT[newCapacity];
		for(int index=0; index<newCapacity; index++)
		{
			temp[index]=this->mData[index];
		}
		deallocate();
		this->mData=temp;
		this->mSize=newCapacity;
		this->mCapacity=newCapacity;
	}
	
	const ValueT* data() const
	{
		return getData();
	}

	std::size_t size() const
	{
		return getSize();
	}

	std::size_t capacity() const
	{
		return getCapacity();
	}
};

#endif

