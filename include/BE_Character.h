// From standard includes.
#include <map>
#include <vector>

// From custom code.
#include "BE_Primarch.h"
#include "BE_Effect.h"
#include "BE_Ability.h"
#include "BE_Attribute.h"
#include "BE_Resource.h"

using namespace std;

/**
 * BE_Character matches the Character primarch of InvaderScript. Something
 * obvious that has sprung from our design considerations is that everything
 * that takes place in a battle/scenario is started by a Character and affects
 * a Character (possibly the same one). I made a pretty hand-drawn flowchart for
 * this.
 */
class BE_Character : BE_Primarch
{
	public:
	void BE_Character() = 0; // Unlike core-overridden characters, ours cannot be instantiated.
	
	/**
	 * Vector of all abilities available to the Character. Remember, we except
	 * actual subclasses since BE_Ability is purely virtual.
	 */
	vector<BE_Ability> Abilities;
	vector<BE_Resource> Resources;
	vector<BE_Attribute> Attributes;

	
};
