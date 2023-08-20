// A program showing template compatibility rules

// Warning: Uncommenting the last statement in the main
// function will generate a compiler error
template <class T> class Single
{
	T 	data;

public:
	Single ()
		{ }

	void	Set (T el)
		{
			data = el;
		}

	T	Get ()
		{
			return data;
		}
} ;

void main ()
{
	// defines some "singles"
	Single <int>	oneInt;
	oneInt.Set (5);

	Single <float>	oneFloat;
	oneFloat.Set (4.9);

	Single <int>	secondInt;
	secondInt.Set (8);

	// assignment between instances of the template class are possible
	// only if they are type compatible

	oneInt = secondInt;     // CORRECT

	//oneInt = oneFloat;		// UNCORRECT !!!!!
}



