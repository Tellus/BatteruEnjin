#pragma once

namespace BE
{
	/**
	 * Interface class for modifiers.
	 **/
	class Modifier<P, T, R>
	{
		P* parent;
		T* target;

		virtual R apply() = 0;
	}
}
