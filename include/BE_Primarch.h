/**
 * BE_Primarch is the abstract base class for all types used in the engine. This
 * mimics the behaviour of InvaderScript constructs - however, for completely
 * different reasons. The central inheritance hierarchy means that we can more
 * easily create interfaces for cross-class signaling, for example in the case
 * of modifiers, I envision allowing true Primarchs (Character, Ability, etc) to
 * all have a collection of modifiers, each one with a separate implementation
 * (but identical interface) to change values. The hosting object should
 * determine how, and when, modifiers are finally applied.
 **/
class BE_Primarch
{
	// Does nothing on its own.
	virtual unsigned action() = 0;
};
