
/**
 * Interface class for modifiers.
 **/
class BE_Modifier<P, T, R>
{
	P* parent;
	T* target;

	virtual R apply() = 0;
}
