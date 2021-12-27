template <typename T>
class AbstractDeque
{
public:
	virtual int GetSize() = 0;
	virtual void pushFront(const T a) = 0;
	virtual void pushBack(const T a) = 0;
	virtual void popFront(T& a) = 0;
	virtual void popBack(T& a) = 0;
	virtual void peekFront(T& a) = 0;
	virtual void peekBack(T& a) = 0;
};