#pragma once

namespace BE
{
	namespace Primarch
	{
		/**
		 * Primarch is the abstract base class for all types used in the engine. This
		 * mimics the behaviour of InvaderScript constructs - however, for completely
		 * different reasons. The central inheritance hierarchy means that we can more
		 * easily create interfaces for cross-class signaling, for example in the case
		 * of modifiers, I envision allowing true Primarchs (Character, Ability, etc) to
		 * all have a collection of modifiers, each one with a separate implementation
		 * (but identical interface) to change values. The hosting object should
		 * determine how, and when, modifiers are finally applied.
		 **/
		class Primarch
		{
			public:
				/**
				 * Clones the current object. This is simply intended to be a wrapper around
				 * a copy-constructor call, but enforces overrides so subclasses will call
				 * the proper constructor and return it.
				 * \note All Primarchs (and their children) should implement their own
				 * clone() method or risk slicing their data when the engine copies data
				 * during simulation runs.
				 * \example Character would implement this with the the line
				 *			return new Character(*this);
				 * It's a simple, though slightly bulky, mechanic to ensure sufficient
				 * copies. Also, it makes Primarch abstract :D
				 **/
				virtual Primarch* clone() = 0;

				/**
				 * Determines whether a primarch should be considered volatile (dangerous to
				 * modify outside of its natural scope, risky to game balance, or other
				 * reasons). Directly determines how the engine copies objects into a
				 * GameState. If true, a copy is made and referenced. If false, the
				 * original is directly referenced. This can potentially save massive
				 * amounts of memory in controlled implementations. It is recommended
				 * that any competitive rulesets (where the AI code was not necessarily
				 * sanitized) contain a high degree of volatility, while highly scripted
				 * environments (for example processing results of a single-player RPG)
				 * contain low volatility to increase flexibility of the data set while
				 * reducing the memory footpring.
				 * \default The value defaults to true (volatile), making cross-changing
				 * a more difficult task for malicious code.
				 **/
				bool is_volatile;

				/**
				 * The default constructor handles some values that I would like
				 * specified in the class otherwise. There's probably a syntax,
				 * I just haven't figured it out.
				 **/
				Primarch();
		};
	}
}
