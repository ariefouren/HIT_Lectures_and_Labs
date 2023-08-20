// An example of how an error in the type parameter results
// in a misleading error message

// Warning: This program contains an error by design!
// note however that the error line and message do not help
// much to find it! To remove the error you need to uncomment
// the operator > member to the Number class.
template <class T>
class OrdSingle
{
	T	data;
public:
	OrdSingle (){}
	void	Set (T el){	data = el;}
	T	    Get (){	return data;}

	int	operator > (int value)
		{
			return (data > value);
		}
};

class Number
{
  public:
	int	n;

	//int	operator > (int i)
	//	{
	//		return (n > i);
	//	}

} ;

void main ()
{
	// instantiates a couple of objects
	OrdSingle <int>		os1;
	OrdSingle <Number>	os2;
    if( os1 > 5 )
		;        

	Number n1;
	n1.n=5;
	if ( n1>4 )
		;

}


